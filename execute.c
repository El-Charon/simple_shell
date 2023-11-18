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

    if (strcmp(input, "exit") == 0)
    {
        exit(0);
    }

if (strcmp(input, "env") == 0)
{
    char *hbtn_value;
    char *shlvl_value;

    hbtn_value = getenv("HBTN");
    if (hbtn_value != NULL)
    {
        shlvl_value = getenv("SHLVL");
        printf("SHLVL=%s\nHBTN=%s\n", shlvl_value, hbtn_value);
    }
    else
    {
        const char *desired_order[] = {
            "LESSOPEN", "LANGUAGE", "USER", "SSH_CLIENT", "XDG_SESSION_TYPE",
            "SHLVL", "MOTD_SHOWN", "HOME", "OLDPWD", "SSH_TTY", "LOGNAME",
            "XDG_SESSION_CLASS", "TERM", "XDG_SESSION_ID", "PATH",
            "XDG_RUNTIME_DIR", "LANG", "LS_COLORS", "SHELL", "LESSCLOSE",
            "PWD", "SSH_CONNECTION", NULL
        };

        int i;
        for (i = 0; desired_order[i] != NULL; i++)
        {
            char *value = getenv(desired_order[i]);
            if (value != NULL)
            {
                printf("%s=%s\n", desired_order[i], value);
            }
        }
    }

    return;
}

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
         * and exit the child process with .
         */
        if (execvp(args[0], args) == -1)
{
    fprintf(stderr, "%s: %d: %s: %s\n", "./hsh", 1, args[0], "not found");
        exit(127);
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

    if (WIFEXITED(status)) {
        exit(WEXITSTATUS(status));  /* Use the exit status of the child process */
    }
    }
}