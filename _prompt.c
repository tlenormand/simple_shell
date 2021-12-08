#include "main.h"

/**
 * _prompt - prints "$ ", wait for the user, prints it on the next line
 * @av: name of the program
 * Return: always 0
 */

int _prompt(char **av)
{
	/*size_t length = 0;*/
	int result = 0;
	char *line = malloc(sizeof(char) * 100);
	int nb_command = 1;

	_initialisation();

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			_puts_string("$ ");
		result = _getline(line);

		/* if given ctrl + D */
		if (result == -1)
			break;

		if (result == -2)
		{
			_error_too_long(line);
			break;
		}

		if (_strcmp(line, "exit\n") == 0)
			break;

		if (*line != '\n' && *line != '#')
		{
			line[_strlen(line) - 1] = '\0';
			check_line(line, nb_command, av[0]);
		}
		nb_command++;
	}

	if (isatty(STDIN_FILENO) == 1 && _strcmp(line, "exit\n") != 0)
		_putchar('\n');

	_close(line);
	return (0);
}
