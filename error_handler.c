#include "shell.h"

/**
 * *int_to_string - Converts an integer to string
 * @num: integer to convert
 * Return: pointer to string
 */

char *int_to_string(int num)
{
	int i;
	char *str;
	int temp = num;
	int digits = 0;

	while (temp != 0)
	{
		temp /= 10;
		digits++;
	}
	str = (char *)malloc((digits + 1) * sizeof(char));
	if (str == NULL)
	{
		exit(EXIT_FAILURE);
	}
	for (i = digits - 1; i >= 0; i--)
	{
		str[i] = '0' + (num % 10);
		num /= 10;
	}
	str[digits] = '\0';
	return (str);
}

/**
 * fprintf_stdout - Prints error message to standard output
 * @format: format string
 */

void fprintf_stdout(const char *format, ...)
{
	char c, *s;
	int d;
	char *num_str;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			format++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = va_arg(args, int);
					write(1, &c, 1);
					break;
				case 's':
					s = va_arg(args, char*);
					write(1, s, custom_strlen(s));
					break;
				case 'd':
					d = va_arg(args, int);
					num_str = int_to_string(d);
					write(1, num_str, custom_strlen(num_str));
					free(num_str);
					break;
				default:
					write(1, "%", 1);
					break;
			}
			format++;
		}
	}
	va_end(args);
}
