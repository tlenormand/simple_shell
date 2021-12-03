#include "main.h"

/**
 * _stat - function that fin the path of a file
 * @file: file to find the path
 * @buf: linked list of all path in environment
 * Return: path, NULL if failled or don't find
 */

char *_stat(char **argv, directory_t *buf)
{
	char *path;

	buf = head;

	while (buf)
	{
		path = malloc(sizeof(char) * (strlen(argv[0]) + strlen(buf->value) + 2));
		if (path == NULL)
			return (NULL);
		path = strcat(strcat(strcpy(path, buf->value), "/"), argv[0]);

		if (access(path, F_OK) != -1)
		{
			free(argv[0]);
			argv[0] = malloc(sizeof(char) * (strlen(path) + 1));
			argv[0] = strcpy(argv[0], path);
			free(path);
			return (argv[0]);
		}
		free(path);

		buf = buf->next;
	}

	return (NULL);
}
