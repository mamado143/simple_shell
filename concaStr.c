#include "Myshell.h"

/**
 * concatenate_strings - Concatenates two strings.
 * @destination: The destination string.
 * @source: The source string.
 * Return: 0 on success.
 */
char *concatenate_strings(char *destination, char *source)
{
    int dest_index = 0;
    int src_index = 0;

    while (destination[dest_index] != '\0')
        dest_index++;

    while (source[src_index] != '\0')
    {
        destination[dest_index] = source[src_index];
        dest_index++;
        src_index++;
    }

    destination[dest_index] = '\0';
    return destination;
}
