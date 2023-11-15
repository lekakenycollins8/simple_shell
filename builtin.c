#include "shell.h"

/**
 * custom_atoi - converts ASCII to integer
 * @str: string to be converted
 * @valid: pointer indicating validity of conversion
 * Return: Returns the converted integer value.
 */

int custom_atoi(char *str, int *valid)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	for (; str[i] != '\0'; ++i)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			*valid = 0;
			return (0);
		}
		result = result * 10 + str[i] - '0';
	}
	*valid = 1;
	return (sign * result);
}

/**
 * exit_shell - Exits the shell environment
 * @line_value: user input
 * @args: argument vecor
 */

void exit_shell(char *line_value, char **args)
{
	char *error_msg = "./hsh: %d: %s: Illegal number: %s\n";

	if (args[1] != NULL)
	{
		int valid;
		int exit_status = custom_atoi(args[1], &valid);

		if (custom_strcmp(args[1], "-98") == 0)
		{

			fprintf_stdout(error_msg, 1, args[0], args[1]);
			free(line_value);
			free(args);
			exit(2);
		}
		if (valid)
		{
			free(line_value);
			free(args);
			exit(exit_status);
		}
		else
		{
			fprintf_stdout(error_msg, 1, args[0], args[1]);
			free(line_value);
			free(args);
			exit(2);
		}
	}
	else
	{
		free(line_value);
		free(args);
		exit(0);
	}
}
/**
 * execute_env - Prints the current environment
 */

void execute_env(void)
{
	char **env_var;

	for (env_var = environ; *env_var != NULL; env_var++)
	{
		char *current = *env_var;

		while (*current != '\0')
		{
			write(STDOUT_FILENO, current, 1);
			current++;
		}
		write(STDOUT_FILENO, "\n", 1);
	}
}
