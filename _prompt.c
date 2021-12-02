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
	char **argv = NULL;

	_initialisation();

	while (1)
	{
		/* display '$ ' */
		printf("$ ");

		/* if given ctrl + D */
		if ((getline(&line, &length, stdin)) == -1)
			break;

		if (*line != '\n')
		{
			/* '\n' replace by '\0' */
			line[strlen(line) - 1] = '\0';

			argv = _strtok(line);

			if (check_access(argv) == 0)
			{
				fork_process(argv);
			}
			else if (check_access(argv) != 1)
				_error(av[0], nb_command, argv[0]);

			_free_double_pointer(argv);

		}
		/*if (line)
			free(line);*/
		nb_command++;
	}

	_close(line);
	return (0);
}
