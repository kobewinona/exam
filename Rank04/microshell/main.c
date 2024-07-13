#include "microshell.h"

t_cmd *parse_cmd(char **argv);
int run_cmd(t_cmd *cmd, char **envp, bool shouldFork);

static void cleanup(t_cmd *cmd) {
  if (cmd->type == C_EXEC)
    free(cmd);
  else if (cmd->type == C_SEQ) {
    cleanup(cmd->seq.left);
    cleanup(cmd->seq.right);
  }
}

static int handle_err(char *message, char *context) {
  while (*message)
    write(STDERR_FILENO, message++, 1);
  if (context) {
    while (*context)
      write(STDERR_FILENO, context++, 1);
  }
  write(STDERR_FILENO, "\n", 1);
  return EXIT_FAILURE;
}

static int cd(char **argv) {
  if (argv[1] && argv[2])
    return handle_err("error: cd: bad arguments", NULL);
  if (chdir(argv[1]) == -1)
    return handle_err("error: cd: cannot change directory to ", argv[1]);
  return EXIT_SUCCESS;
}

static int handle_exec(t_exec cmd, char **envp, bool shouldFork) {
  int status = EXIT_SUCCESS;

  if (!strcmp(cmd.argv[0], "cd"))
    return cd(cmd.argv);

  if (!shouldFork) {
    execve(cmd.argv[0], cmd.argv, envp);
    handle_err("error: cannot execute ", cmd.argv[0]);
    exit(EXIT_FAILURE);
  } else {
    pid_t pid = fork();
    if (pid == 0) {
      execve(cmd.argv[0], cmd.argv, envp);
      handle_err("error: cannot execute ", cmd.argv[0]);
      exit(EXIT_FAILURE);
    }
    waitpid(pid, &status, 0);
  }

  return WIFEXITED(status) ? WEXITSTATUS(status) : EXIT_FAILURE;
}

static int handle_seq(t_seq cmd, char **envp) {
  int status = EXIT_SUCCESS;

  if (cmd.is_pipe) {
    int pipe_fds[2];
    if (pipe(pipe_fds) == -1) {
      return handle_err("error: pipe failed", NULL);
    }

    pid_t left_pid = fork();
    if (left_pid == -1) {
      return handle_err("error: fork failed", NULL);
    }

    if (left_pid == 0) {
      close(pipe_fds[0]);
      if (dup2(pipe_fds[1], STDOUT_FILENO) == -1) {
        handle_err("error: dup2 failed", NULL);
        exit(EXIT_FAILURE);
      }
      close(pipe_fds[1]);
      exit(run_cmd(cmd.left, envp, false));
    }

    pid_t right_pid = fork();
    if (right_pid == -1) {
      return handle_err("error: fork failed", NULL);
    }

    if (right_pid == 0) {
      close(pipe_fds[1]);
      if (dup2(pipe_fds[0], STDIN_FILENO) == -1) {
        handle_err("error: dup2 failed", NULL);
        exit(EXIT_FAILURE);
      }
      close(pipe_fds[0]);
      exit(run_cmd(cmd.right, envp, false));
    }

    // Parent process
    close(pipe_fds[0]);
    close(pipe_fds[1]);
    waitpid(left_pid, &status, 0);
    waitpid(right_pid, &status, 0);

    return WIFEXITED(status) ? WEXITSTATUS(status) : EXIT_SUCCESS;
  } else {
    status = run_cmd(cmd.left, envp, true);
    status = run_cmd(cmd.right, envp, true);
  }

  return status;
}

int run_cmd(t_cmd *cmd, char **envp, bool shouldFork) {
  if (!cmd)
    return EXIT_FAILURE;

  int status = EXIT_SUCCESS;
  if (cmd->type == C_EXEC)
    status = handle_exec(cmd->exec, envp, shouldFork);
  else if (cmd->type == C_SEQ)
    status = handle_seq(cmd->seq, envp);

  return status;
}

int main(int argc, char **argv, char **envp) {
  t_cmd *cmd = NULL;
  int status = EXIT_SUCCESS;

  if (argc <= 0)
    return EXIT_SUCCESS;

  cmd = parse_cmd((argv + 1));
  status = run_cmd(cmd, envp, true);
  return cleanup(cmd), status;
}
