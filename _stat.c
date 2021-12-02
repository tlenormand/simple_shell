#include "main.h"

/**
 * _stat - function that fin the path of a file
 * @file: file to find the path
 * @buf: linked list of all path in environment
 * Return: path, NULL if failled or don't find
 */

char *_stat(const char *file, directory_t *buf)
{
	char *path;

	buf = head;

	while (buf)
	{
		path = malloc(sizeof(char) * (strlen(file) + strlen(buf->value) + 2));
		if (path == NULL)
			return (NULL);
		path = strcat(strcat(strcpy(path, buf->value), "/"), file);

		if (access(path, F_OK) != -1)
		{
			return (path);
		}
		free(path);

		buf = buf->next;
	}

	return (NULL);
}
