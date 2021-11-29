#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork + wait + execve
 *
 * Return: Always 0.
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
	pid_t child_pid_1, child_pid_2, my_pid;
	int status;

	my_pid = getpid();
	printf("parent's pid : %u\n", my_pid);
	child_pid_1 = fork();
	printf("child 1's pid : %u\n", child_pid_1);
	if (child_pid_1 == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid_1 == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
	else
	{
		wait(&status);
		printf("Oh, it's all better now\n");
	}

/* new fils */
	child_pid_2 = fork();
	printf("child 2's pid : %u\n", child_pid_2);
	if (child_pid_2 == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid_2 == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
	else
	{
		wait(&status);
		printf("Oh, it's all better now\n");
	}

	return (0);
}
