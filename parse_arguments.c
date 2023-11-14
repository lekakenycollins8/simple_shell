#include "shell.h"

/**
 * *split_line - Tokenizes user input
 * @line: user input
 * Return: modified tokens
 */

char **split_line(char *line)
{
	char **tokens;
	char *token;
	int position = 0;
	int bufsize = TOKEN_BUFFER_SIZE;

	tokens = (char **)malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	token = custom_strtok(line, TOKEN_DELIMETER);
	while (token != NULL)
	{
		int new_bufsize;

		tokens[position] = token;
		position++;
		if (position >= bufsize)
		{
			new_bufsize = bufsize + TOKEN_BUFFER_SIZE;
			tokens = _realloc(tokens, bufsize * sizeof(char *),
					new_bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("allocation error");
				exit(EXIT_FAILURE);
			}
			bufsize = new_bufsize;
		}
		token = custom_strtok(NULL, TOKEN_DELIMETER);
	}
	tokens[position] = NULL;
	return (tokens);
}
