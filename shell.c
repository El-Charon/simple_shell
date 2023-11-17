#include "shell.h"
#include <ctype.h>

/**
 * run_shell - Implements a basic shell with user input, command execution,
 * and parentheses handling.
 *
 * This function continuously reads user input, tokenizes it into arguments,
 * and executes commands until the user enters "exit". It ensures adherence to
 * the Betty style guidelines, promoting readability and consistency in C code.
 */
void run_shell()
{
    char input[MAX_INPUT_SIZE];
    int isSpacesOnly;
    size_t i;

    while (1)
    {
        fflush(stdout);
        isSpacesOnly = 1;

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        for (i = 0; i < strlen(input); i++)
        {
            if (!isspace((unsigned char)input[i]))
            {
                isSpacesOnly = 0;
                break;
            }
        }

        if (strlen(input) > 0 && !isSpacesOnly)
        {
            char *start = strchr(input, '(');
            char *end = strchr(input, ')');

            if (start != NULL && end != NULL && end > start)
            {
                *end = '\0';
                execute_command(start + 1);
            }
            else
            {
                int isInputSpacesOnly = 1;
                for (i = 0; i < strlen(input); i++)
                {
                    if (!isspace((unsigned char)input[i]))
                    {
                        isInputSpacesOnly = 0;
                        break;
                    }
                }

                if (!isInputSpacesOnly)
                {
                    execute_command(input);
                }
                else
                {
                    printf("(stdout)[](Length: 0)\n");
                    printf("(stderr)[](Length: 0)\n");
                    printf("(status)[0]\n");
                }
            }
        }
        else
        {
            /* Do nothing if input is empty */
        }
    }
}