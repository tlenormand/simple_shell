#include <stdio.h>
#include <unistd.h>

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
    extern char **environ;

    if (env != NULL)
    {
        printf("%p\n", (void *) env);
    }
    if (environ != NULL)
    {
        printf("%p\n", (void *) environ);
    }
    return (0);
}