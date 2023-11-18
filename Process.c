#include "Myshell.h"
#include <unistd.h>
/**
 * launch_new_process - starts a new program as a child process
 * @arguments: The command args as input
 * Return: returns 0.
 */
int launch_new_process(char *arguments[])
{
	char *line = NULL;
	int child_pid;
	char *executable_path;
	int process_status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror(free(line);
				return (-1);
	}
	else if (child_pid == 0)
	{
	executable_path = find_executable(arguments[0]);
	if (executable_path != NULL)
	{
	execve(executable_path, arguments, environ);
	free(line);
	print_error_message(arguments[0]);
	exit(1);
	}
	}
	else
	{
	waitpid(child_pid, &process_status, 0);
	}
	return (0);
}
