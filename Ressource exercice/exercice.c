#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t child_pid;
    int child_finish = 0;
    char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

    child_pid = fork();

    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }

    if (child_pid == 0)
    {
        if (execve(argv[0], argv, NULL) == -1)
        {
            perror("Error:");
        }
        sleep(3);
    }
    else
    {
        wait(&child_finish);
        printf("%u, parent\n", child_pid);
    }

    return (0);
}