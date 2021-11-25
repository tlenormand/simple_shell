#include <stdio.h>
#include <string.h>

/**
 * main - splits a string and returns an array of each word of the string
 * Return: Always 0.
 */

char *get_strtok(char *str)
{
	const char *delimiters = " ";
	char *strToken = strtok ( str, delimiters);

	while (strToken != NULL )
	{
		strToken = strtok (NULL, delimiters);
	}

	return (strToken);
}
