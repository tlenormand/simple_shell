#include "main.h"

/**
 * check_line - check if line don't have separators
 * @line: line given by _getline
 * @nb_command: number of command previously executed
 * @program: name of the current program
 * Return: 0 always
 */

int check_line(char *line, int nb_command, char *program)
{
	line_t separators[] = {
		{";", separator_func},
		{"&&", and_if_func},
		{"||", or_if_func},
		{NULL, NULL}
	};

	int i = 0, j = 0, k = 0;

	check_comment(line);

	while (line[i] != '\0')
	{
		while (separators[j].separator != NULL)
		{
			if (separators[j].separator[k] == line[i])
			{
				k++;
				if (separators[j].separator[k] == '\0')
				{
					return (check_separator(line)(line, nb_command, program));
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

	checked_line(line, nb_command, program);

	return (0);
}


/**
 * check_comment - check if there is a comment (#) in line
 * @line: line to control given by _getline
 * Return: 0 if not comment, 1 otherwise
 */

int check_comment(char *line)
{
	int i;

	for (i = 0; line[i] != '\0' && line[i] != '#'; i++)
		;

	while (line[i])
	{
		line[i] = '\0';
		return (1);
	}

	return (0);
}


/**
 * check_separator - check if line have a separator
 * @line: line to control given by _getline
 * Return: function to appropritate calculation, 0 if not
 */

int (*check_separator(char *line))(char *line, int nb_command, char *prog)
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
 * line has no separator in it. separators was found in check_separator
 * @line: line given by _getline
 * @nb_command: number of command previously executed
 * @program: name of the current program
 * Return: 0 if success, -1 otherwise
 */

int checked_line(char *line, int nb_command, char *program)
{
	char **argv = NULL;
	int check_acc, forked;

	argv = _strtok(line);

	check_acc = check_access(argv);
	if (check_acc == 0)
	{
		forked = fork_process(argv);
		if (forked == 1)
		{
			return (-1);
		}
	}
	else if (check_acc == -1)
	{
		_error(program, nb_command, argv[0]);
		_free_double_pointer(argv);
		return (-1);
	}

	_free_double_pointer(argv);

	return (0);
}
