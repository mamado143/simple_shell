#include "Myshell.h"

/**
 * print_error_message - Prints an error message for a command not found.
 * @command: The command passed.
 * Exits with failure status.
 */
void print_error_message(char *command)
{
    char *first_error = "Command '";
    char *second_error = "' not found\n";

    write(STDERR_FILENO, first_error, strlen(first_error));
    write(STDERR_FILENO, command, strlen(command));
    write(STDERR_FILENO, second_error, strlen(second_error));

    free(command);
    exit(EXIT_FAILURE);
}
