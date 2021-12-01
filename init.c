#include "main.h"

/**
 * _init - function that initialise the main function
 */

void _initialisation(void)
{
	env_cpy = _double_pointer_copy(env_cpy, environ);
	head = _init_linked_list_path("PATH");
}


/**
 * _close - function that close the main function
 */

void _close(char *line)
{
	if (line)
		free(line);
	if (env_cpy)
		_free_double_pointer(env_cpy);
	if (head)
		free_list(head);
}


/**
 * _init_linked_list_path - initialise the linked list directory
 * @name: name of the variable
 * Return: pointer to the start of the linked list
 */

directory_t *_init_linked_list_path(const char *name)
{
	const char *value = _getenv(name);
	char *path = NULL;
	int i = 0, j = 0;

	/*value = malloc(sizeof(char) * (strlen(_getenv(name)) + 1))*/

	path = malloc(sizeof(char) * (strlen(value) + 1));
	if (path == NULL)
	{
		printf("Error: malloc()");
		return (NULL);
	}

	while (value[i] != '\0')
	{
		path[j] = value[i];
		i++;
		j++;
		if (value[i + 1] == '\0')
			path[j] = value[i];
		if (value[i] == ':' || value[i + 1] == '\0')
		{
			path[j] = '\0';
			head = add_node(&head, path);
			free(path);
			path = malloc(sizeof(char) * (strlen(value) + 1));
			if (path == NULL)
			{
				printf("Error: malloc()");
				return (NULL);
			}
			j = 0;
			i++;
		}
	}

	free(path);
	return (head);
}