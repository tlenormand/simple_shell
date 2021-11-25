#include <stdio.h>
#include <string.h>

/**
 * main - splits a string and returns an array of each word of the string
 * Return: Always 0.
 */

int get_strtok(void)
{
	char str[] = "bla bli blo";
	const char *delimiters = " ";
	char *strToken = strtok ( str, delimiters);

	while (strToken != NULL )
	{
		printf ("%s\n", strToken);
		strToken = strtok (NULL, delimiters);
	}

	return (0);
}
