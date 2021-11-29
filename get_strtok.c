#include <stdio.h>
#include <string.h>

/**
 * main - splits a string and returns an array of each word of the string
 * Return: Always 0.
 */

char **get_strtok(char *str)
{
	const char *delimiters = " ";
	char *strToken = strtok ( str, delimiters);
	char **argv = NULL;
	int i = 0;

	argv[i] = strToken;
	i++;
	while (strToken != NULL)
	{
		strToken = strtok (NULL, delimiters);
		argv[i] = strToken;
		i++;
	}

	return (argv);
}
