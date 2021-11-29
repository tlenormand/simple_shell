#ifndef ENV_H
#define ENV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct directory_s
{
	char *name;
	char *value;
	struct directory_s *next;
} directory_t;


/* global variable */
extern char **environ;


/* prototype */
char *_getenv(const char *name);
directory_t *add_node(directory_t **head, const char *name, const char *value);
directory_t *add_node_end(directory_t **head, const char *name, const char *value);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int print_list(const directory_t *h);
void free_list(directory_t *head);
char **cpy_env(char **environ);

#endif /* ENV_H */
