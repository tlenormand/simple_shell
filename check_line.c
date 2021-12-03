#include "main.h"


/**
 * check_line - check if line don't have separators
 * @line: line given by _getline
 * Return: 0 always
 */

int check_line(char *line)
{
	line_t separators[] = {
		{";", separator_func},
		{"&&", and_if_func},
		{"||", and_if_func},
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
				if (separators[j].separator[k] == '\0')
				{
					return (get_separator_func(line)(line));
				}
				i++;
			}
			else
			{
				k = 0;
				j++;
			}
		}
		k = 0;
		j = 0;
		i++;
	}

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
		{"&&", and_if_func},
		{"||", or_if_func},
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
				if (separators[j].separator[k] == '\0')
				{
					return (separators[j].f);
				}
				i++;
			}
			else
			{
				k = 0;
				j++;
			}
		}
		k = 0;
		j = 0;
		i++;
	}

	return (0);
}


/**
 * checked_line - function that directed the line
 * line has no separator in it. separators was found in get_separator_func
 * @line: line given by _getline
 * Return: 0 if success, -1 otherwise
 */

int checked_line(char *line)
{
	char **argv = NULL;
	int check_acc;

	argv = _strtok(line);

	check_acc = check_access(argv);
	if (check_acc == 0)
	{
		if (fork_process(argv) == -1)
		{
			return (-1);
		}
	}
	else if (check_acc == -1)
	{
		_error("./hsh", 1, argv[0]);
		return (-1);
	}

	_free_double_pointer(argv);

	return (0);
}
