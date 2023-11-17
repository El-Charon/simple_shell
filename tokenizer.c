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
 *
 * @input: The input string to be tokenized.
 * @args: An array to store the tokenized arguments.
 */
void tokenize_input(char *input, char *args[])
{
    const char *delimiters = " \t\n";  /* Delimiters used for tokenization */
    char *token;  /* Pointer to the current token */
    int i = 0;  /* Index for storing tokens in the 'args' array */

    /* Tokenize the input string using delimiters */
    while ((token = strtok(input, delimiters)) != NULL && i < MAX_ARGS - 1)
    {
        args[i++] = token;  /* Store the current token in the 'args' array */
        input = NULL;  /* Continue tokenization from the next position */
    }

    args[i] = NULL;  /* Set the last element of 'args' to NULL for exec functions */
}