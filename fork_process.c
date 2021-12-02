#include "main.h"

/**
 * fork_process - fork the prompt function
 * @argv: arguments given by _strtok
 * Return: 0 if success, on error -1
 */

int fork_process(char **argv)
{
	pid_t pid;
	int *end_child = 0;

	pid = fork();

	if (pid == -1)
	{
		perror("Error: fork()");
		return (-1);
	}

	if (pid == 0)
	{
		/* child process */
		if (execve(argv[0], argv, env_cpy) == -1)
			perror("Error: execve()");
	}
	else
	{
		/* parent process */
		wait(end_child);
	}

	return (0);
}
