#include "shell.h"

/**
 * process_command -handles builtin commands and executes shell
 * @args: command line arguments
 * @line_value: getline to be freed
 */

void process_command(char **args, char *line_value)
{
	char dir_path[INPUT_BUFFER_SIZE];
	char *directory = "/bin/";

	if (strcmp(args[0], "exit") == 0)
	{
		exit_shell(line_value, args);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		execute_env();
	}
	else
	{
		if (strchr(args[0], '/') != NULL)
		{
			if (access(args[0], X_OK) != -1)
			{
				execute_command(args, line_value);
			}
			else
			{
				char *error_msg = "./hsh: %d: %s: not found\n";
				fprintf(stderr, error_msg, 1, args[0]);
				free(line_value);
				free(args);
				exit(127);
			}
		}
		else
		{
			strcpy(dir_path, directory);
			strcat(dir_path, args[0]);

			if (access(dir_path, X_OK) != -1)
			{
				execute_command(args, line_value);
			}
			else
			{
				char *error_msg = "./hsh: %d: %s: not found\n";
				fprintf(stderr, error_msg, 1, args[0]);
				free(line_value);
				free(args);
				exit(127);
			}
		}
	}
}
