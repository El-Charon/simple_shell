#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define MAX_INPUT_SIZE 1024

int main(int argc, char *argv[]) {
    char input[MAX_INPUT_SIZE];

    int i;

    if (argc > 1) {
        for (i = 1; i < argc; ++i) {
            FILE *file = fopen(argv[i], "r");
            if (file == NULL) {
                perror("fopen");
                continue;
            }

            while (fgets(input, MAX_INPUT_SIZE, file) != NULL) {
                input[strcspn(input, "\n")] = '\0';

                execute_command(input);
            }

            fclose(file);
        }
    } else {
        printf("Custom Shell: Enter commands. Type 'exit' to quit.\n");

        while (1) {
        printf("Custom Shell: Enter a command. Type 'exit' to quit.\n$ ");

        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
            printf("\n");
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            break;
        }

        execute_command(input);
        }
    }

    return 0;
}