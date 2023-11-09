#include "shell.h"

/**
 * read_input - reads user input
 * Return: array of read strings on success
 */

char *read_input(void)
{
	ssize_t read_status;
	char *input_buffer = NULL;
	ssize_t buffer_size = 0;

	read_status = getline(&input_buffer, &buffer_size, stdin);
	if (read_status == -1)
	{
		if (feof(stdin))
		{
			_putchar('\n');
			free(input_buffer);
			exit(EXIT_STATUS);
		}
		else
		{
			free(input_buffer);
			perror("Error: getline failed");
			exit (EXIT_FAILURE);
		}
	}
	return (input_buffer);
}

/**
 * read_line - Reads lines of input character by character
 * Return: pointer to a string input
 */

char *read_line(void)
{
	int bufsize = INPUT_BUFFER_SIZE;
	int position = 0;
	char *buffer = malloc(bufsize * sizeof(char));
	char c;

	if (!buffer)
	{
		perror("Error: memory allocation failed");
		exit (EXIT_FAILURE);
	}
	while (1)
	{
		ssize_t read_status = read(STDIN_FILENO, &c, 1);

		if (read_status == -1)
		{
			perror("Error: read failed");
			free(buffer);
			exit(EXIT_FAILURE);
		}
		if (read_status == 0 || c = EOF || c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		buffer[position] = c;
		position++;

		if (position >= bufsize)
		{
			char *new_buffer;

			bufsize += INPUT_BUFFER_SIZE;
			new_buffer = realloc(buffer, bufsize * sizeof(char));
			if (!new_buffer)
			{
				perror("Error: reallocation failed");
				free(buffer);
				exit(EXIT_FAILURE);
			}
			buffer = new_buffer;
		}
	}
}
