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

    while (1) {
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) > 0) {
            char *start = strchr(input, '(');
            char *end = strchr(input, ')');

            if (start != NULL && end != NULL && end > start) {
                *end = '\0';
                execute_command(start + 1);
            } else {
                execute_command(input);
            }
        }
    }
}
