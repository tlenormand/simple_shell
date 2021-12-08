#include "main.h"

/**
 * _help - display help
 * @argv: builtin to display
 * Return: no return
 */

void _help(char **argv)
{
	if (argv[2] != NULL)
	{
		_puts_string("Error: too many arguments. Usage: help [builtin]\n");
	}
	if (argv[1] == NULL)
	{
		_puts_string("exit: ______ Exit the simple_shell\n");
		_puts_string("cd: ________ Change work directory\n");
		_puts_string("echo $$: ___ Print the pid of the program\n");
		_puts_string("setenv: ____ Add a new env variable\n");
		_puts_string("unsetenv: __ Remove an env variable\n");
		_puts_string("env: _______ Print the environment\n");
		_puts_string("printlist: _ Print the list of path ");
		_puts_string("contained in env variable PATH\n");
	}
	else
		_help_builtin(argv);
}


/**
 * _help_builtin - display help of builtin
 * @argv: builtin to display
 * Return: no return
 */

void _help_builtin(char **argv)
{
	if (_strcmp(argv[1], "exit") == 0)
		_puts_string("exit: Exit the simple_shell\n");
	else if (_strcmp(argv[1], "cd") == 0)
		_puts_string("cd: change work directory\n");
	else if (_strcmp(argv[1], "env") == 0)
		_puts_string("env: Print the environment\n");
	else if (_strcmp(argv[1], "setenv") == 0)
		_puts_string("setenv: Add a new env variable\n");
	else if (_strcmp(argv[1], "unsetenv") == 0)
		_puts_string("unsetenv: Remove an env variable\n");
	else if (_strcmp(argv[1], "echo") == 0)
		_puts_string("echo $$: print the pid of the program\n");
	else if (_strcmp(argv[1], "printlist") == 0)
	{
		_puts_string("printlist: Print the list of path ");
		_puts_string("contained in env variable PATH\n");
	}
	else
	{
		_puts_string(argv[1]);
		_puts_string(": not found, ");
	}
	_puts_string("\nwrite ‘man ./man_1_simple_shell’ ");
	_puts_string("for more informations\n");
}
