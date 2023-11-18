#include "Myshell.h"
/**
  * main - This function is the entry point.
  * Return:returns 0
  */
int main(void)
{
	int input_chars;
	int write_chars = 0;
	char *prompt = "$ ";
	size_t len = 0;
	char *input_line = NULL;
	int is_interactive = isatty(STDIN_FILENO);

	signal(SIGINT, handle_signal);
	while (1)
	{
		if (is_interactive)
		{
			write_chars = write(1, prompt, strlen(prompt));
			if (write_chars == -1)
			{
				perror("Write error");
				free(input_line);
				exit(1);
			}
		}
		fflush(stdout);
		input_chars = getline(&input_line, &len, stdin);
		if (input_chars == -1)
		{
			if (feof(stdin))
			{
				free(input_line);
				exit_shell();
			}
			else
			{
				perror("Faild user input\n");
				free(input_line);
				exit(-1);
			}
		}
		else if (input_chars == 1)
		{
			continue;
		}
		else
		{
			Token_input(input_line);
		}
	}
	free(input_line);
	return (0);
}
