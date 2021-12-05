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

	_initialisation();

	while (1)
	{
		/* display '$ ' */
		_puts_string("$ ");

		/* if given ctrl + D */
		if ((getline(&line, &length, stdin)) == -1)
		{
			_putchar('\n');
			break;
		}

		/* if given exit */
		if (_strcmp(line, "exit\n") == 0)
			break;

		if (*line != '\n')
		{
			/* '\n' replace by '\0' */
			line[_strlen(line) - 1] = '\0';

			check_line(line, nb_command, av[0]);
		}
		nb_command++;
	}

	_close(line);
	return (0);
}
