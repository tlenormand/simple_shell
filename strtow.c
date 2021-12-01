#include "main.h"

/**
 * strtow - function that splits a string into words
 * @str: string
 * Return: array of string
 */

char **strtow(char *str)
{
	char **argv = NULL;
	int i = 0, idx = 0, lenght = 0, row = 0;

	if (str == NULL || *str == '\0' || *str == '\n')
		return (NULL);

	row = nb_word(i, str);
	argv = (char **)calloc(sizeof(char *), (nb_word(i, str) + 1));
	if (argv == NULL || row == 0)
	{
		free(argv);
		return (NULL);
	}

	row = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			argv[row] = (char *)calloc(sizeof(char), (nb_letter(i, str) + 1));
			if (argv[row] == NULL)
			{
				for (idx = 0; idx <= row; idx++)
					free(argv[idx]);
				free(argv);
				return (NULL);
			}
			lenght = 0;
			for (idx = i; str[idx] != ' ' && str[idx] != '\0'; idx++)
			{
				argv[row][lenght] = str[idx];
				lenght++, i++;
			}
			row++;
		}
		else
			i++;
	}

	return (argv);
}


/**
 * nb_letter - count the number of letter in the word
 * @i: idx of str
 * @str: string
 * Return: the number of letter
 */

int nb_letter(int i, char *str)
{
	int letter = 0;

	while (str[i] != ' ' && str[i] != '\0' && str[i] != '\0')
		letter++, i++;

	return (letter);
}


/**
 * nb_word - count the number of words in str
 * @i: idx of str
 * @str: string
 * Return: the number of words
 */

int nb_word(int i, char *str)
{
	int row = 0;

	while (str[i] && str[i] != '\n')
	{
		if (str[i] != ' ')
			row++, i += nb_letter(i, str);
		else
			i++;
	}

	return (row);
}
