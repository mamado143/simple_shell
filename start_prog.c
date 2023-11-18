#include "Myshell.h"
#include <unistd.h>


/**
 * str_program - Starts a new program as a child process.
 * @arguments: The command arguments passed as input.
 * Return: 0 on success, -1 on failure.
 */
int str_program(char *arguments[])
{
    char *line = NULL;
    int child_pid;
    char *executable_path;
    int process_status;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Forking Failed");
        free(line);
        return -1;
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
