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
/* STRUCTURES */

/**
 * struct line_s - Struct line_s
 *
 * @separator: the separators
 * @f: the function associated
 */
typedef struct line_s
{
	char *separator;
	int (*f)(char *line, int nb_command, char *command);
} line_t;


/**
 * struct directory_s - singly linked list
 * @value: value of the variable
 * @next: points to the next node
 */
typedef struct directory_s
{
	char *value;
	struct directory_s *next;
} directory_t;


/* -------------------------------------------------- */
/* GLOBAL VARIABLES */

extern char **environ;
char **env_cpy;
directory_t *head;
char **av;
int exit_var;


/* -------------------------------------------------- */
/* PROTOTYPES */

/* in file prompt.c */
int _prompt(char **av);

/* in file _getline.c */
int _getline(char *line);

/* in file check_line */
int check_line(char *line, int nb_command, char *program);
int (*check_separator(char *line))(char *line, int nb_command, char *program);
int checked_line(char *line, int nb_command, char *program);
int check_comment(char *line);

/* in file check_access.c */
int check_access(char **argv);
int check_access2(char **argv);

/* in file fork_process.c */
int fork_process(char **argv);


/* in file _stat.c */
char *_stat(char **argv, directory_t *buf);

/* in file signal.c */
void ctrl_c(int i);
void ctrl_d(void);

/* in file _cd.c */
int _cd(char **argv, directory_t *head);

/* in file _error.c */
void _error(char *av, int nb_command, char *command);
void _error_too_long(char *command);
void _error_separator(char *av, int nb_command, char *command);

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

/* in file separators_functions.c */
int separator_func(char *line, int nb_command, char *program);
int and_if_func(char *line, int nb_command, char *program);
int or_if_func(char *line, int nb_command, char *program);

/* in file function_str.c */
int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);

/* in file function_allocation.c */
void *_calloc(unsigned int nmemb, unsigned int size);
void *_realloc(void *ptr, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);

/* in file function_print.c */
int _putchar(char c);
int _puts_integer(int d);
int _puts_string(char *str);
int _putchar_error(char c);
int _puts_integer_error(int d);

/* in file _help */
void _help(char **argv);
void _help_builtin(char **argv);


#endif /* MAIN_H */
