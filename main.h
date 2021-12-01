#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <limits.h>

/* -------------------------------------------------- */

/**
 * struct directory_s - singly linked list
 * @name: name of the variable
 * @value: value of the variable
 * @next: points to the next node
 */
typedef struct directory_s
{
	char *value;
	struct directory_s *next;
} directory_t;

/* -------------------------------------------------- */

/* global variable */
extern char **environ;
char **env_cpy;
directory_t *head;

/* -------------------------------------------------- */

/* prototypes */

/* in file prompt.c */
/* contain the main function */
int fork_main(char **argv);
int exe_func(char **argv);
char *_stat(const char *file, directory_t *buf);
int _change_wd(char **argv, directory_t *head);

/* functions in init.c */
void _initialisation(void);
void _close(char *line);
directory_t *_init_linked_list_path(const char *name);

/* functions in linked_list.c.c */
directory_t *add_node(directory_t **head, const char *value);
directory_t *add_node_end(directory_t **h, const char *val);
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

/* in file get_strtok.c */
char **strtow(char *str);
int nb_letter(int i, char *str);
int nb_word(int i, char *str);


#endif /* MAIN_H */
