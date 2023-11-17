#include "shell.h"

/**
 * execute_command - Forks a child process to execute a command.
 * @command: Array of strings representing the command and its arguments.
 *
 * This function forks a child process to execute a command specified by the
 * arguments. The parent process waits for the child process to complete.
 */
void execute_command(char *input) {
    pid_t pid;
    int status;
    char *args[MAX_ARGS];

    tokenize_input(input, args);

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("shell");
            _exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        perror("shell");
    } else {
        waitpid(pid, &status, 0);
    }
}