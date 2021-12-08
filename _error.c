#include "main.h"

/**
 * _error - display message error if cmd not found
 * @av: name of the program in the main
 * @nb_command: number of the command which was typing
 * @command: name of the command
 * Return: No return.
 */

void _error(char *av, int nb_command, char *command)
{
	write(STDERR_FILENO, av, _strlen(av));
	write(STDERR_FILENO, ": ", 2);
	_puts_integer_error(nb_command);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
 * _error_too_long - display message error if cmd is too long
 * @command: name of the command
 * Return: No return.
 */

void _error_too_long(char *command)
{
	_puts_string(command);
	_puts_string(": File name too long");
}



void _error_separator(char *av, int nb_command, char *command)
{
	write(STDERR_FILENO, av, _strlen(av));
	write(STDERR_FILENO, ": ", 2);
	_puts_integer_error(nb_command);
	write(STDERR_FILENO, ": Syntax error: \"", 17);
	write(STDERR_FILENO, command, 1);
	write(STDERR_FILENO, "\" unexpected\n", 13);
}