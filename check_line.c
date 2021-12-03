#include "main.h"


/**
 * check_line - check if line don't have separators
 * @line: line given by _getline
 * Return: 0 always
 */

int check_line(char *line)
{
	if (get_separator_func(line)(line) == 0)
		checked_line(line);

	return (0);
}


/**
 * get_separator_func - check if line have a separator
 * @line: line to control given by _getline
 * Return: function to appropritate calculation, 0 if not
 */

int (*get_separator_func(char *line))(char *)
{
	line_t separators[] = {
		{";", separator_func},
		{NULL, NULL}
	};

	int i = 0, j = 0, k = 0;

	while (line[i] != '\0')
	{
		while (separators[j].separator != NULL)
		{
			if (separators[j].separator[k] == line[i])
			{
				k++;
				i++;
			}
			else
			{
				if (separators[j].separator[k + 1] == '\0')
				{
					return (separators[i].f);
				}
				else
				{
					k = 0;
					j++;
				}
			}
		}
		i++;
	}

	return (0);
}


/**
 * separator_func - function pointed by get_separator_func
 * do the appropriate calculation corresponding to the separator
 * @line: line given by _getline, separated if separators are found
 * Return: 1 always
 */

int separator_func(char *line)
{
	int i = 0, j = 0;
	char *line_bis;
	int len = 0;

	while (line[i])
	{
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

		checked_line(line_bis);
	}

	return (1);
}


/**
 * checked_line - function that directed the line
 * line has no separator in it. separators was found in get_separator_func
 * @line: line given by _getline
 * Return: 0 always
 */

int checked_line(char *line)
{
	char **argv = NULL;
	int check_acc;

	argv = _strtok(line);
	free(line);

	check_acc = check_access(argv);
	if (check_acc == 0)
	{
		fork_process(argv);
	}
	else if (check_acc == -1)
		_error("Bonjour", 1, argv[0]);

	_free_double_pointer(argv);

	return (0);
}
