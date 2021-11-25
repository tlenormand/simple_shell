#include "main.h"

/**
 * main - prints "$ ", wait for the user, prints it on the next line
 * @ac: number of arguments
 * @av: arguments
 * Return: number of xharactere read
 */

int main(void)
{
	size_t len = 0;
	char *line = NULL;

	printf("$ ");
	while ((getline(&line, &len, stdin)) != -1)
	{
		get_strtok(line);
		printf("$ ");
	}

	printf("\n");
	free(line);
	return (0);
}
