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
	printf("%s: %d: %s: not found\n", av, nb_command, command);
}
