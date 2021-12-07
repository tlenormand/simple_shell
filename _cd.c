#include "main.h"

/**
 * _cd - change work directory
 * @argv: arguments given by _strtok
 * @head: global struct of path
 * Return: 0 if succeed, 1 otherwise
 */

int _cd(char **argv, directory_t *head)
{
	char *current_wd = _calloc(1024, sizeof(char));
	(void) head;

	if (argv[1] == NULL || _strcmp(argv[1], "~") == 0)
	{
		_setenv("OLDPWD", _getenv("PWD"), 1);
		chdir(_getenv("HOME"));
		_setenv("PWD", getcwd(current_wd, 1024 * sizeof(char)), 1);
		free(current_wd);
		return (0);
	}
	else if (_strcmp(argv[1], "-") == 0)
	{
		_puts_string(_getenv("OLDPWD"));
		_putchar('\n');
		chdir(_getenv("OLDPWD"));
		_setenv("OLDPWD", _getenv("PWD"), 1);
		_setenv("PWD", getcwd(current_wd, 1024 * sizeof(char)), 1);
		free(current_wd);
		return (0);
	}
	else if (access(argv[1], F_OK) != -1)
	{
		_setenv("OLDPWD", getcwd(current_wd, 1024 * sizeof(char)), 1);
		chdir(argv[1]);
		_setenv("PWD", getcwd(current_wd, 1024 * sizeof(char)), 1);
		free(current_wd);
		return (0);
	}

	return (1);
}
