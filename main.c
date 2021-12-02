#include "main.h"

/**
 * main - our shell
 * @ac: number of arguments
 * @av: list of the arguments
 * @env: environement where we are
 * Return: always 0
 */

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)env;

	_prompt(av);

	return (0);
}
