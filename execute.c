#include "shell.h"

/**
 * execute_command - Forks a child process to execute a command.
 * @input: The input string containing the command and its arguments.
 *
 * This function forks a child process to execute a command specified by the
 * input string. The parent process waits for the child process to complete.
 */
void execute_command(char *input)
{
    pid_t pid;
    int status;
    char *args[MAX_ARGS];

    tokenize_input(input, args);

    pid = fork();
    if (pid == -1)
    {
        perror("shell");
        return;
    }

    if (pid == 0)
    {
        /* Child process */
        if (execvp(args[0], args) == -1)
        {
            perror("shell");
            _exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* Parent process */
        waitpid(pid, &status, 0);
    }
}