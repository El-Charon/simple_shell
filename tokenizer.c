#include <string.h>
#include <stdio.h>
#include "shell.h"

/**
 * tokenize_input - Tokenizes the input string into an array of arguments.
 * @input: The input string to be tokenized.
 * @args: An array to store the tokenized arguments.
 *
 * This function tokenizes the input string using space, tab, and newline
 * characters as delimiters. The resulting tokens are stored in the 'args' array.
 * The tokenization process is limited to 'MAX_ARGS - 1' tokens, and the last
 * element of the 'args' array is set to NULL for compatibility with exec functions.
 */
void tokenize_input(char *input, char *args[]) {
    const char *delimiters = " \t\n";
    char *token;
    int i = 0;

    while ((token = strtok(input, delimiters)) != NULL && i < MAX_ARGS - 1) {
        args[i++] = token;

        input = NULL;
    }

    args[i] = NULL;
}