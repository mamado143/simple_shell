#include "Myshell.h"
/**
 * Token_input - Tokenizes user input for further handling
 * @input_line: The line containing user input
 * Return: 0 on success
 */
int Token_input(char *input_line)
{
	int idx = 0;
	char *tok;
	char *seps = " \a\n\t\r";
	char *args[1024];

	tok = strtok(input_line, seps);
	while (tok != NULL)
	{
		args[idx] = tok;
		tok = strtok(NULL, seps);
		idx++;
	}
	args[idx] = NULL;
	if (args[0] == NULL)
	{
		return (0);
	}
	if (compare_strings(args[0], "chdir") == 0)
	{
		change_directory_builtin(args[1]);
	}
	else if (compare_strings(args[0], "exitsh") == 0)
	{
		free(input_line);
		exit_shell();
	}
	else if (compare_strings(args[0], "envshow") == 0)
	{
		print_env();
	}
	else
	{
		str_program(args);
	}
	return (0);
}
