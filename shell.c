#include "shell.h"

/**
 * run_shell - Runs a simple shell with a command prompt.
 *
 * This function initializes a simple shell that takes user input, tokenizes
 * it into arguments, and executes commands. It continues to run until the user
 * enters the "exit" command.
 */
void run_shell() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARGS];
    int should_run = 1;

    while (should_run) 
    {
        printf("($) ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) 
        {
            break; /* Exit on EOF */
        }

        /* Remove newline character */
        input[strcspn(input, "\n")] = '\0';

        /* Tokenize input into arguments */
        char *token = strtok(input, " ");
        int i = 0;
        while (token != NULL && i < MAX_ARGS - 1) 
        {
            args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
        args[i] = NULL; /* Null-terminate the argument list */

        if (i > 0) 
        {
            if (strcmp(args[0], "exit") == 0) {
                should_run = 0; /* Exit the shell */
            } else 
            {
                execute_command(args);
            }
        }
    }
}