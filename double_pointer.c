#include "main.h"

/**
 * _double_pointer_copy - function that copy a char **
 * @dest: destination of char ** to copy
 * @src: source to copy in destination
 * Return: pointer to the destination, NULL if failed
 */

char **_double_pointer_copy(char **dest, char **src)
{
	int i;

	for (i = 0; src[i]; i++)
		;

	dest = calloc(i + 1, sizeof(char *));
	if (dest == NULL)
		return (NULL);

	for (i = 0; src[i]; i++)
		dest[i] = strdup(src[i]);

	return (dest);
}

/**
 * _add_value_double_ptr - function that add a value to a char ** adding a row
 * @double_ptr: double pointer to add value
 * @value: value to add to char **
 */

void _add_value_double_ptr(char **double_ptr, char *value)
{
	int i;

	if (value == NULL || *value == '\0')
		return;

	for (i = 0; double_ptr[i]; i++)
		;

	*double_ptr = realloc(*double_ptr, sizeof(char *) * (i + 1));
	if (double_ptr == NULL)
	{
		return;
	}

	double_ptr[i] = malloc(sizeof(char) * (strlen(value) + 1));
	if (double_ptr[i] == NULL)
	{
		_free_double_pointer(double_ptr);
		return;
	}

	double_ptr[i] = strcpy(double_ptr[i], value);
}

/**
 * _free_double_pointer - function that free a char **
 * @double_ptr: double pointer to free
 */

void _free_double_pointer(char **double_ptr)
{
	int i;

	for (i = 0; double_ptr[i]; i++)
		free(double_ptr[i]);
	free(double_ptr);
}
