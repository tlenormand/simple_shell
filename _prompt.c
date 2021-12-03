#include "main.h"

/**
 * _prompt - prints "$ ", wait for the user, prints it on the next line
 * @av: name of the program
 * Return: always 0
 */

int _prompt(char **av)
{
	size_t length = 0;
	char *line = NULL;
	int nb_command = 1;
	(void)av;

	_initialisation();

	while (1)
	{
		/* display '$ ' */
		printf("$ ");

		/* if given ctrl + D */
		if ((getline(&line, &length, stdin)) == -1)
		{
			printf("\n");
			break;
		}

		/* if given exit */
		if (strcmp(line, "exit\n") == 0)
			break;

		if (*line != '\n')
		{
			/* '\n' replace by '\0' */
			line[strlen(line) - 1] = '\0';

			check_line(line);
		}
		nb_command++;
	}

	_close(line);
	return (0);
}
