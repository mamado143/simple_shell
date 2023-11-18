#include "Myshell.h"
#include <unistd.h>

/**
 * print_env - This Prints the env variables.
 */
void print_env(void)
{
    int index;

    for (index = 0; environ[index]; index++)
    {
        write(1, environ[index], strlen(environ[index]));
        write(1, "\n", 1);
    }
}
