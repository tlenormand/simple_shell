#include "main.h"

/**
 * main - prints "$ ", wait for the user, prints it on the next line
 * Return: number of characteres read
 */

int main(void)
{
	size_t len = 0;
	char *line = NULL;
	char *argv;

	printf("$ ");
	while ((getline(&line, &len, stdin)) != -1)
	{
		argv = get_strtok(line);
		printf("%s", argv);
		printf("$ ");
	}

	printf("\n");
	free(line);
	return (0);
}
