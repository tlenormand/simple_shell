#include "main.h"

/**
 * _calloc - function that allocates memory for an array, using malloc
 * @nmemb: array of nmemb elements
 * @size: size bytes
 * Return: the list created of NULL if fail
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *list = NULL;

	if (nmemb == 0 || size == 0)
		return (NULL);

	list = (char *)malloc(nmemb * size);
	if (list == NULL)
	{
		free(list);
		return (NULL);
	}

	for (i = 0; i < nmemb * size; i++)
		list[i] = 0;

	return (list);
}


/**
 * _realloc - function that reallocates a memory block
 * @ptr: old array
 * @new_size: size of the new array
 * Return: the new array
 */

void *_realloc(void *ptr, unsigned int new_size)
{
	void *new_ptr = NULL;

	if (new_size == (sizeof(char) * (_strlen(ptr) + 1)))
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		free(new_ptr);
		return (NULL);
	}

	if (new_size > (sizeof(char) * (_strlen(ptr) + 1)) && ptr != NULL)
		_memcpy(new_ptr, ptr, (sizeof(char) * (_strlen(ptr) + 1)));
	else if (ptr != NULL)
		_memcpy(new_ptr, ptr, new_size);

	free(ptr);

	return (new_ptr);
}


/**
 * _memcpy - function that copies memory area
 * @dest: memory area dest
 * @src: memory area src
 * @n: copies n bytes from memory area
 * Return: a pointer to destination (dest)
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{

	while (n != 0)
	{
		dest[n - 1] = src[n - 1];
		n--;
	}

	return (dest);
}
