#include "shell.h"

/**
 * handle_child_process - Run the command in child process
 * @args: command line arguments to run
 * @line_value: getline value to be freed
 */

void handle_child_process (char **args, char *line_value)
{
	if (strchr(args[0], '/') != NULL)
	{
		if (execve(args[0], args, NULL) == -1)
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
		char *path_token = strtok(path, PATH_DELIMETER);

		while (path_token != NULL)
		{
			char dir_path[INPUT_BUFFER_SIZE];

			strcpy(dir_path, path_token);
			strcat(dir_path, "/");
			strcat(dir_path, args[0]);

			if (access(dir_path, X_OK) != -1)
			{
				execve(dir_path, args, NULL);
			}
			path_token = strtok(NULL, PATH_DELIMETER);
		}
		fprintf(stderr, "./hsh: %d: %s: not found\n", 1, args[0]);
		free(line_value);
		free(args);
		exit(127);
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

	do
	{
		waitpid(child_pid, &status, 0);

		if (WIFEXITED(status))
		{
			free(line_value);
			free(args);
			exit(WEXITSTATUS(status));
		}
	}
	while (!WIFEXITED(status) && !WIFSIGNALED(status));
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
