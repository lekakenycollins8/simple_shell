#include "shell.h"

/**
 * main - Entry point
 * Return: 0 on success
 */

int main(void)
{
	char user_input;
	char **args;
	bool interactive_shell = isatty(STDIN_FILENO);

	while(1)
	{
		if (interactive_shell)
		{
			PRINTPROMPT("Lekakeny$ ");
			fflush(stdout);

			user_input = read_input();
			if (user_input == NULL)
			{
				break;
			}
		}
		else
		{
			user_input = read_line();

			if (user_input == NULL)
			{
				break;
			}
		}
		args = split_line(user_input);
		process_command(args, user_input);

		free(user_input);
		free(args);

		if (!interactive_shell)
		{
			break;
		}
	}
	return (0);
}
