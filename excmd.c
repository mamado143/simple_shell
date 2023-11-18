#include "Myshell.h"

/**
 * find_executable - Check for the existence of a command in the PATH
 * @command: The command to be checked in the PATH
 * Return: The full path of the executable, or the original command if not found
 */
char *find_executable(char *command)
{
    char *path = getenv("PATH");
    char *copy_path = strdup(path);

    if (copy_path == NULL)
    {
        perror("Failed");
        return NULL;
    }

    char cmd_path[1024];
    char *dir = strtok(copy_path, ":");

    while (dir != NULL)
    {
        strcpy(cmd_path, dir);

        if (cmd_path[calculate_string_length(cmd_path) - 1] != '/')
        {
            strcat(cmd_path, "/");
        }

        compare_strings(cmd_path, command);

        if (access(cmd_path, F_OK) == 0 && access(cmd_path, X_OK) == 0)
        {
            free(copy_path);
            return strdup(cmd_path);
        }

        dir = strtok(NULL, ":");
    }

    free(copy_path);
    return strdup(command);
}
