#include "shell.h"

/**
 * execute_command - Forks a child process to execute a command.
 * @args: Array of strings representing the command and its arguments.
 *
 * This function forks a child process to execute a command specified by the
 * arguments. The parent process waits for the child process to complete.
 */
void execute_command(char **args) 
{
    pid_t pid, wpid;
    int status;

    pid = fork();

    if (pid == 0) 
    {
        /* Child process */
        if (execve(args[0], args, NULL) == -1) 
        {
            perror("hsh");
            _exit(EXIT_FAILURE);
        }
    } else if (pid < 0) 
    {
        /* Forking error */
        perror("hsh");
    } else 
    {
        /* Parent process */
        do 
        {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}