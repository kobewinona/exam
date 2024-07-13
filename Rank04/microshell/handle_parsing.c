#include "microshell.h"

static void ft_memset(void *ptr, int value, size_t num) {
  unsigned char *p = ptr;
  while (num-- > 0) {
    *p++ = (unsigned char)value;
  }
}

static t_cmd *constr_cmd(t_cmd_t type) {
  t_cmd *cmd = NULL;

  if (!(cmd = (t_cmd *)malloc(sizeof(t_cmd))))
    return NULL;
  ft_memset(cmd, 0, sizeof(t_cmd));

  cmd->type = type;

  return cmd;
}

static t_cmd *constr_exec(int argc, char **argv) {
  t_cmd *cmd = NULL;

  if (!(cmd = constr_cmd(C_EXEC)))
    return NULL;

  for (int i = 0; i < argc; ++i)
    cmd->exec.argv[i] = argv[i];

  return cmd;
}

static t_cmd *constr_seq(t_cmd *left, t_cmd *right, bool is_pipe) {
  t_cmd *cmd = NULL;

  if (!left)
      return NULL;

  if (!right)
    return left;

  if (!(cmd = constr_cmd(C_SEQ)))
    return NULL;

  cmd->seq.is_pipe = is_pipe;
  cmd->seq.left = left;
  cmd->seq.right = right;

  return cmd;
}

static t_cmd *parse_exec(char ***argv) {
  t_cmd *cmd = NULL;

  if (!(*argv)[0])
    return NULL;

  int argc;
  for (argc = 0; (*argv)[argc]; ++argc) {
    if (!strcmp((*argv)[argc], "|") || !strcmp((*argv)[argc], ";"))
      break;
  }

  cmd = constr_exec(argc, &(*argv)[0]);
  return (*argv) += argc, cmd;
}

static t_cmd *parse_seq(char **argv) {
  t_cmd *cmd;

  while ((*argv) && (!strcmp((*argv), "|") || !strcmp((*argv), ";")))
    argv++;

  cmd = parse_exec(&argv);

  if (argv[0])
    cmd = constr_seq(cmd, parse_seq(argv), !strcmp(argv[0], "|"));

  return cmd;
}

t_cmd *parse_cmd(char **argv) { return parse_seq(argv); }
