#include "Myshell.h"
/**
 * find_executable - Check for the existence of a command in the PATH
 * @command: The command to be checked in the PATH
 * Return: The full path of the executable, or the original command if not
 */
char *find_executable(char *command)
{
	char *path = getenv("PATH");
	char *copy_path;
	char cmd_path[1024];
	char *dir;

	if (path == NULL)
	{
		perror("Failed to get PATH");
		return (NULL);
	}
	copy_path = strdup(path);
	if (copy_path == NULL)
	{
		perror("Failed to copy PATH");
		return (NULL);
	}
	dir = strtok(copy_path, ":");
	while (dir != NULL)
	{
		strcpy(cmd_path, dir);
		if (cmd_path[strlen(cmd_path) - 1] != '/')
		{
			strcat(cmd_path, "/");
		}
		strcat(cmd_path, command);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			free(copy_path);
			return (strdup(cmd_path));
		}
		dir = strtok(NULL, ":");
	}
	free(copy_path);
	return (strdup(command));
}
