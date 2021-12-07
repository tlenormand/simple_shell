#include "main.h"

/**
 * check_access - check if we can access to argv[0]
 * or if it is cd, exit ...
 * @argv: arguments given by _strtok
 * Return: 0 if success, 1 if built-in function, -1 if not found
 */

int check_access(char **argv)
{
	if (_strcmp(argv[0], "cd") == 0)
	{
		_cd(argv, head);
		return (1);
	}

	if (_strcmp(argv[0], "echo") == 0)
		if (_strcmp(argv[1], "$$") == 0)
		{
			_puts_integer(getpid());
			_putchar('\n');
			return (1);
		}

	if (_strcmp(argv[0], "printlist") == 0)
	{
		print_list(head);
		return (1);
	}

	/* we can access without the path */
	if (_stat(argv, head))
		;
	/* concatenate the path + command */
	else if (access(argv[0], F_OK) != -1)
		;
	else
		return (-1);

	return (0);
}
