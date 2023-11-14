#include "shell.h"

/**
 * is_delimiter - Checks if a character is a delimeter
 * @c: character to check
 * @delim: delimeter
 * Return: true or false
 */

bool is_delimiter(char c, const char *delim)
{
	while (*delim != '\0')
	{
		if (*delim == c)
		{
			return (true);
		}
		delim++;
	}
	return (false);
}
/**
 * custom_strtok - tokenizes a string
 * @str: string to be tokenized
 * @delim: a string containing one or more delimiter characters
 * Return: a pointer to a token
 */
char *custom_strtok(char *str, const char *delim)
{
	unsigned int i;
	static char *token_start;
	static char *next_token;

	if (str != NULL)
		next_token = str;
	token_start = next_token;
	if (token_start == NULL)
		return (NULL);
	for (i = 0; token_start[i] != '\0'; i++)
	{
		if (!is_delimiter(token_start[i], delim))
			break;
	}
	if (token_start[i] == '\0')
	{
		next_token = NULL;
		return (NULL);
	}
	next_token = token_start + i;
	for (i = 0; next_token[i] != '\0'; i++)
	{
		if (is_delimiter(next_token[i], delim))
			break;
	}
	if (next_token[i] == '\0')
		next_token = NULL;
	else
	{
		next_token[i] = '\0';
		next_token = next_token + i + 1;
		if (*next_token == '\0')
			next_token = NULL;
	}
	return (token_start);
}


/**
 * custom_strdup - dynamically allocates memory to store a copy of
 * the input string
 * @source: string
 * Return: the duplicate
 */
char *custom_strdup(char *source)
{
	size_t length = custom_strlen(source);
	char *duplicate = (char *)malloc(length + 1);

	if (source == NULL)
	{
		return (NULL);
	}
	if (duplicate != NULL)
	{
		custom_strcpy(duplicate, source);
	}
	return (duplicate);
}
