#include "Myshell.h"
/**
 * exit_shell - Exits the Myshell.
 * Exits with code 0 for success.
 */
void exit_shell(void)
{
	exit(0);
}

/**
 * handle_signal - Handles signals in the Myshell.
 * @signal_number: The number of the signal.
 */
void handle_signal(int signal_number)
{
	char *shell_prompt = "\n$ ";
	(void)signal_number;
	write(1, shell_prompt, strlen(shell_prompt));
	fflush(stdout);
}
