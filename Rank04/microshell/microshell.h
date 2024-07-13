#ifndef MICROSHELL_H
#define MICROSHELL_H

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

typedef enum e_cmd_t {
  C_EXEC,
  C_SEQ,
} t_cmd_t;

typedef struct s_cmd t_cmd;

typedef struct s_exec {
  char *argv[MAX_INPUT + 1];
} t_exec;

typedef struct s_seq {
  bool is_pipe;
  t_cmd *left;
  t_cmd *right;
} t_seq;

struct s_cmd {
  t_cmd_t type;
  union {
    t_exec exec;
    t_seq seq;
  };
};

#endif