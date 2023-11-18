#include "Myshell.h"

/**
 * change_directory - Changes the current working directory.
 * @target_dir: Argument passed to the cd command.
 */
void change_directory_builtin(char *target_dir)
{
    char *home;

    if (target_dir == NULL)
    {
        home = getenv("HOME");
        if (home == NULL)
        {
            perror("cd: HOME environment is not set.\n");
        }
        else
        {
            if (chdir(home) != 0)
            {
                perror("Failed to change the directory.");
            }
        }
    }
    else
    {
        if (chdir(target_dir) != 0)
        {
            perror(" Failed to change the directory.");
        }
    }
}
