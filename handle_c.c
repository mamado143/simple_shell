#include "Myshell.h"
/**
 * handle_comments - Function to handle comments in the shell.
 * @user_input: Stores the user input.
 */
void handle_comments(char *user_input)
{
	/* Find the index of the '#' symbol in the input string */
	char *comment_start = strchr(user_input, '#');
	
	if (comment_start != NULL)
	{
		*comment_start = '\0';
	}
}
