#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* -------------------------------- */

/* in file prompt.c */
/* contain the main function */
int fork_main(char *line);

/* in file get_strtok.c */
char **strtow(char *str);
int nb_letter(int i, char *str);
int nb_word(int i, char *str);

/* in file exec.c */
int exe_func(char **argv);

#endif /* MAIN_H */
