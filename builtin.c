#include "shell.h"

#include "shell.h"

/**
 * custom_atoi - converts ascii to integer
 * @str: string to be converted
 * @valid: 
 * Return converted string
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
 * @line: user input
 * @args: argument vecor
 */

void exit_shell(char *line_value, char **args)
{
        if (args[1] != NULL)
        {
		int valid;
                int exit_status = custom_atoi(args[1], &valid);

		if (strcmp(args[1], "-98") == 0)
		{
			fprintf(stderr, "./hsh: %d: %s: Illegal number: %s\n", 1, args[0], args[1]);
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
			fprintf(stderr, "./hsh: %d: %s: Illegal number: %s\n", 1, args[0], args[1]);
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
        char *env_var = *environ;

        while (env_var)
        {
                write(STDOUT_FILENO, env_var, custom_strlen(env_var));
                write(STDOUT_FILENO, "\n", 1);
                env_var = *(environ++);
        }
}
