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

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

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
char **av;

/* -------------------------------------------------- */

/* prototypes */

/* in file prompt.c */
int _prompt(char **av);

/* in file _stat.c */
char *_stat(const char *file, directory_t *buf);

/* in file _cd.c */
int _cd(char **argv, directory_t *head);

/* in file visual.c */
void whatcolor(void);

/* in file _error.c */
void _error(char *av, int nb_command, char *command);

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

/* in file _strtok.c */
char **_strtok(char *str);
int nb_letter(int i, char *str);
int nb_word(int i, char *str);

/* in file check_access.c */
int check_access(char **argv);

/* in file fork_process.c */
int fork_process(char **argv);

#endif /* MAIN_H */
