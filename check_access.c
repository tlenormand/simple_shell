#include "main.h"

/**
 * check_access - check if we can access to argv[0]
 * or if it is cd, exit ...
 * @argv: arguments given by _strtok
 * Return: 0 if success, 1 if built-in function, -1 if not found
 */

int check_access(char **argv)
{
	if (strcmp(argv[0], "cd") == 0)
	{
		_cd(argv, head);
		return (1);
	}

	if (strcmp(argv[0], "whatcolor") == 0)
	{
		whatcolor();
		return (1);
	}

	if (strcmp(argv[0], "printlist") == 0)
	{
		print_list(head);
		return (1);
	}

	/*
	* if (strcmp(argv[0], "env") == 0)
	* {
	* _printenv(env_cpy);
	* return (1);
	* }
	*/

	if (strcmp(argv[0], "exit") == 0)
	{
		if (argv)
			_free_double_pointer(argv);
		if (env_cpy)
			_free_double_pointer(env_cpy);
		if (head)
			free_list(head);
		exit(EXIT_SUCCESS);
	}

	/* we can access without the path */
	if (access(argv[0], F_OK) != -1)
		;
	/* concatenate the path + command */
	else if (_stat(argv[0], head))
		argv[0] = _stat(argv[0], head);
	else
		return (-1);

	return (0);
}
