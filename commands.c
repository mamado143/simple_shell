#include "Myshell.h"
/**
  * execute_user_command -  use to execute commands.
  */
void execute_user_command(void)
{
	int input_chars, write_chars = 0;
	char *prompt = "$ ";
	size_t len = 0;
	char *input_line = NULL;
	int is_interactive = isatty(STDIN_FILENO);

	signal(SIGINT, handle_signal);
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
	else
	{
		Token_input(input_line);
	}
	free(input_line);
}
