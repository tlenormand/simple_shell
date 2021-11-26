#include "main.h"

/**
 * main - prints "$ ", wait for the user, prints it on the next line
 * Return: always 0
 */

int main(void)
{
	size_t len = 0;
	char *line = NULL;

	printf("$ ");
	while ((getline(&line, &len, stdin)) != -1)
	{
		fork_main(line);
		printf("$ ");
	}

	printf("\n");
	free(line);
	return (0);
}


/**
 * fork_main - fork the main function
 * @line: input string got from the prompt
 * Return: 0 if success, on error -1
 */

int fork_main(char *line)
{
	pid_t child_pid;
	char **argv;
	int *end_fils;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error: fork()");
		return (1);
	}

	if (child_pid == 0)
	{
		argv = strtow(line);
		if (argv != NULL)
		{
			exe_func(argv);
		}
	}
	else
	{
		wait(end_fils);
	}

	return (0);
}
