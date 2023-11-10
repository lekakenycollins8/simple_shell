#include "shell.h"

/**
 * custom_strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 * Return: void
 */

char *custom_strcat(char *dest, char *src)
{
        int i = 0;
        int j = 0;

        while (dest[i] != '\0')
        {
                i++;
        }
        while (src[j] != '\0')
        {
		if (i + j >= INPUT_BUFFER_SIZE - 1)
		{
			break;
		}
                dest[i + j] = src[j];
                j++;
        }
        dest[i + j] = '\0';
        return (dest);
}

/**
 * custom_strcmp - Compares two strings
 * @str1: first string
 * @str2: second string
 * Return: comparison value
 */

int custom_strcmp(const char *str1, const char *str2)
{
	if (!str1 || !str2)
	{
		return (str1 == str2) ? 0 : (str1 ? 1 : -1);
	}
        while (*str1 && (*str1 == *str2))
        {
                str1++;
                str2++;
        }
        return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

/**
 * char *custom_strcpy - a function that copies the string pointed by src
g* @dest: copy to
 * @src: copy from
 * Return: string
 */

char *custom_strcpy(char *dest, const char *src)
{
        int l = 0;

        int x = 0;

        while (*(src + l) != '\0')
        {
                l++;
        }
        for (x = 0; x < l; x++)
        {
                dest[x] = src[x];
        }
        dest[l] = '\0';
        return (dest);
}

/**
 * custom_strlen - returns the length of a string
 * @s: string
 * Return: the length
 */
size_t custom_strlen(const char *s)
{
        int longi = 0;

        while (*s != '\0')

        {
                longi++;
                s++;
        }

        return (longi);
}

/**
 * custom_strncmp - compares two string
 * @str1: first string
 * @str2: second string
 * @n: maximum number of characters to compare
 * Return: rresult of comparison
 */

int custom_strncmp(const char *str1, const char *str2, size_t n)
{
        while (n > 0 && *str1 && *str2 && *str1 == *str2)
        {
                str1++;
                str2++;
                n--;
        }
        if (n == 0 || (*str1 == '\0' && *str2 == '\0'))
        {
                return (0);
        }
        return (*str1 - *str2);
}
