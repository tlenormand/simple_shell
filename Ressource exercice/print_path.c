#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * main - prints each directory contained in the the environment
 * variable PATH, one directory per line.
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
    char *env_path;
    char *dir_path;

    env_path = getenv("PATH");

    dir_path = strtok(env_path, ":");
    while (dir_path != NULL)
    {
        printf("%s\n", dir_path);
        dir_path = strtok (NULL, ":");
    }

    return (0);
}