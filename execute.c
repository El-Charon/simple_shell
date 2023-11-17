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

    /*
     * Tokenize the input string to separate the command and its arguments.
     * The result is stored in the 'args' array.
     */
    tokenize_input(input, args);

    /* Fork a child process */
    pid = fork();
    if (pid == -1)
    {
        /*
         * If fork fails, print an error message using perror and return.
         * perror prints a description for the last error that occurred.
         */
        perror("shell");
        return;
    }

    if (pid == 0)
    {
        /* Child process */
        /*
         * Attempt to execute the command using execvp.
         * If execvp fails, print an error message using perror,
         * and exit the child process with EXIT_FAILURE.
         */
        if (execvp(args[0], args) == -1)
        {
            perror("shell");
            _exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* Parent process */
        /*
         * Wait for the child process to complete using waitpid.
         * The status of the child process is stored in the 'status' variable.
         */
        waitpid(pid, &status, 0);
    }
}