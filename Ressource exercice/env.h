#ifndef ENV_H
#define ENV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * struct directory_s - singly linked list
 * @name: name of the variable
 * @value: value of the variable
 * @next: points to the next node
 */
typedef struct directory_s
{
	char *name;
	char *value;
	struct directory_s *next;
} directory_t;


/* global variable */
extern char **environ;
char **env_cpy;


/* prototypes */

/* functions in PATH.c */
directory_t *add_node(directory_t **head, const char *name, const char *value);
directory_t *add_node_end(directory_t **h, const char *name, const char *val);
int print_list(const directory_t *h);
void free_list(directory_t *head);

/* functions in environ.c */
void _printenv(char **env);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

/* functions in double_pointer.c */
void _free_double_pointer(char **double_ptr);
void _add_value_double_ptr(char **double_ptr, char *value);
char **_double_pointer_copy(char **dest, char **src);

/* functions in init.c */
void _init(void);
void _close(void);


#endif /* ENV_H */
