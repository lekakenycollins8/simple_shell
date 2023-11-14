#include "shell.h"

/**
 * handle_child_process - Run the command in child process
 * @args: command line arguments to run
 * @line_value: getline value to be freed
 */

void handle_child_process(char **args, char *line_value);

void handle_child_process(char **args, char *line_value)
{
	char *error_message = "./hsh: %d: %s: not found\n";

	if (strchr(args[0], '/') != NULL)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("execve error");
			free(line_value);
			free(args);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		char *path = _getenv("PATH");
		char *path_copy = custom_strdup(path);
		char *dir = custom_strtok(path_copy, PATH_DELIMETER);
		char *resolved_command = NULL;

		while (dir != NULL)
		{
			size_t dir_len = custom_strlen(dir);
			size_t command_len = custom_strlen(args[0]);

			resolved_command = malloc(dir_len + command_len + 2);
			custom_strcpy(resolved_command, dir);
			custom_strcat(resolved_command, "/");
			custom_strcat(resolved_command, args[0]);

			if (access(resolved_command, X_OK) != -1)
			{
				if (execve(resolved_command, args, environ) != -1)
				{
					break;
				}
			}
			dir = custom_strtok(NULL, PATH_DELIMETER);
		}
		if (dir == NULL)
		{
			fprintf_stdout(error_message, 1, args[0]);
		}
		free(path_copy);
	}
}

/**
 * handle_parent_process - handles parent process and waits for child process
 * @child_pid: process ID of child
 * @args: command line arguments
 * @line_value: getline value to be freed
 */

void handle_parent_process(pid_t child_pid, char **args, char *line_value)
{
	int status;

	do {
		waitpid(child_pid, &status, WUNTRACED);

		if (WIFEXITED(status))
		{
			free(line_value);
			free(args);
			exit(WEXITSTATUS(status));
		}
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}

/**
 * execute_command - Run the specified command and manage exit status
 * @args: command line arguments
 * @line_value: getline to be freed
 */

void execute_command(char **args, char *line_value)
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("forking error");
		free(line_value);
		free(args);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		handle_child_process(args, line_value);
	}
	else
	{
		handle_parent_process(child_pid, args, line_value);
	}
}
