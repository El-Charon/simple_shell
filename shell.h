#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
extern char **environ;

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 32

void tokenize_input(char *input, char *args[]);
void execute_command(char *command);
void run_shell();

#endif /* SHELL_H */