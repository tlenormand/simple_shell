#include "main.h"

/**
 * _getline - function that get the user input
 * @line: store the line gets in the char *line
 * Return: number of characteres read
 */

int _getline(char *line)
{
	char *linep = line, *linen = NULL;
	size_t lenmax = 100, len = lenmax;
	int c = 1;
	unsigned int count = 0;

	while (1)
	{
		signal(SIGINT, ctrl_c);
		if (read(STDIN_FILENO, &c, 1) != -1)
		{
			count++;

			if (--len == 0)
			{
				len = lenmax;
				linen = _realloc(linep, lenmax *= 2);
				if (linen == NULL)
				{
					free(linep);
					return (-1);
				}
				line = linen + (line - linep);
				linep = linen;
			}
			*line++ = c;
			if (c == '\n')
			{
				*line = '\0';
				break;
			}
			if (c == 1)
			{
				return (-1);
			}
		}
	}

	line = linep;

	return (count);
}
