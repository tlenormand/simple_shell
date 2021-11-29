#include "main.h"

/**
 * exe_func - function that execute a command
 * @argv: argument income
 * Return: nothing if success, -1 on error
 */

int exe_func(char **argv)
{
	if (execve(argv[0], argv, NULL) == -1)
		perror("Error: execve()");

	return (-1);
}
