#include "shell.h"

/**
 * fill_with_byte - Fill an array with a constant byte
 * @array: Pointer to the array
 * @byte: Byte value to fill
 * @len: Length of the array
 * Return: Pointer to the array
 */

void *fill_with_byte(void *array, int byte, unsigned int len)
{
	char *ptr = array;
	unsigned int i = 0;

	while (i < len)
	{
		*ptr = byte;
		ptr++;
		i++;
	}
	return (array);
}

/**
 * _memcpy - Copy memory area
 * @dest: Destination pointer
 * @src: Source pointer
 * @n: Number of bytes to copy
 * Return: Destination pointer
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the original memory block
 * @old_size: Previous size of the memory block
 * @new_size: New size of the memory block
 * Return: Pointer to the newly allocated memory block
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *value;

	if (new_size == old_size)
	{
		return (ptr);
	}
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	value = malloc(new_size);
	if (value == NULL)
	{
		return (NULL);
	}
	if (ptr == NULL)
	{
		fill_with_byte(value, '\0', new_size);
	}
	else
	{
		_memcpy(value, ptr, old_size);
	}
	free(ptr);
	return (value);
}
