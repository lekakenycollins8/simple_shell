#include "shell.h"

/**
 * process_command -handles builtin commands and executes shell
 * @args: command line arguments
 * @line_value: input value to be freed
 */

void process_command(char **args, char *line_value)
{
	if (custom_strcmp(args[0], "exit") == 0)
	{
		exit_shell(line_value, args);
	}
	else if (custom_strcmp(args[0], "env") == 0)
	{
		execute_env();
	}
	else
	{
		execute_command(args, line_value);
	}
}
