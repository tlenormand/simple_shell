#include "main.h"

/**
 * separator_func - function pointed by get_separator_func
 * do the appropriate calculation corresponding to the separator
 * @line: line given by _getline, separated if separators are found
 * @nb_command: number of command previously executed
 * @program: name of the current program
 * Return: 1 always
 */

int separator_func(char *line, int nb_command, char *program)
{
	int i = 0, j = 0;
	char *line_bis;
	int len = 0;

	while (line[i] == ' ' && line[i])
		line = &line[i + 1];

	i = 0;
	while (line[i])
	{
		if (line[i] == ';')
			return(-1);
		while (line[len] != ';' && line[len] != '\0')
			len++;
		line_bis = malloc(sizeof(char) * ++len);

		j = 0;
		while (line[i] != ';' && line[i] != '\0')
		{
			line_bis[j] = line[i];
			i++, j++;
		}
		line_bis[j] = '\0';
		i++;

		checked_line(line_bis, nb_command, program);
		free(line_bis);
	}

	return (1);
}


/**
 * and_if_func - function pointed by get_separator_func
 * do the appropriate calculation until it fail
 * @line: line given by _getline, separated if && is found
 * @nb_command: number of command previously executed
 * @program: name of the current program
 * Return: 1 if success, -1 otherwise
 */

int and_if_func(char *line, int nb_command, char *program)
{
	int i = 0, idx = 0;
	char *line_bis;
	int len = 0;

	while (line[idx])
	{
		len = 0;
		while (line[idx] != '&' && line[idx] != '\0')
			len++, idx++;

		line_bis = malloc(sizeof(char) * ++len);

		i = 0;
		idx -= (len - 1);
		while (i < len - 1)
		{
			line_bis[i] = line[idx];
			idx++, i++;
		}
		line_bis[i] = '\0';

		if (line[idx] != '\0')
			idx += 2;

		if (checked_line(line_bis, nb_command, program) == 0)
		{
			free(line_bis);
			return (-1);
		}

		if (access(line_bis, F_OK) == 0)
		{
			free(line_bis);
			return (1);
		}

		free(line_bis);
	}

	return (1);
}


/**
 * or_if_func - function pointed by get_separator_func
 * do the appropriate calculation until it success
 * @line: line given by _getline, separated if || is found
 * @nb_command: number of command previously executed
 * @program: name of the current program
 * Return: 1 if success, -1 otherwise
 */

int or_if_func(char *line, int nb_command, char *program)
{
	int i = 0, idx = 0;
	char *line_bis;
	int len = 0;

	while (line[idx])
	{
		len = 0;
		while (line[idx] != '|' && line[idx] != '\0')
			len++, idx++;

		line_bis = malloc(sizeof(char) * ++len);

		i = 0;
		idx -= (len - 1);
		while (i < len - 1)
		{
			line_bis[i] = line[idx];
			idx++, i++;
		}
		line_bis[i] = '\0';

		if (line[idx] != '\0')
			idx += 2;

		if (checked_line(line_bis, nb_command, program) == 0)
		{
			free(line_bis);
			return (-1);
		}

		if (access(line_bis, F_OK) == 0)
		{
			free(line_bis);
			return (1);
		}

		free(line_bis);
	}

	return (1);
}
