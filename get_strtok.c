#include "main.h"

/**
 * strtow - function that splits a string into words
 * @str: string
 * Return: array of string
 */

char **strtow(char *str)
{
	char **list = NULL;
	int i = 0, idx = 0, lenght = 0, row = 0;

	if (str == NULL || *str == '\0' || *str == '\n')
		return (NULL);

	row = nb_word(i, str);
	list = (char **)malloc((sizeof(char *) * nb_word(i, str)));
	if (list == NULL || row == 0)
	{
		free(list);
		return (NULL);
	}

	row = 0;
	while (str[i] != '\n')
	{
		if (str[i] != ' ')
		{
			list[row] = (char *)malloc((2 + nb_letter(i, str) * sizeof(char)));
			if (list[row] == NULL)
			{
				for (idx = 0; idx <= row; idx++)
					free(list[idx]);
				free(list);
				return (NULL);
			}
			lenght = 0;
			for (idx = i; str[idx] != ' ' && str[idx] != '\n' && str[idx]; idx++)
			{
				list[row][lenght] = str[idx];
				lenght++, i++;
			}
			row++;
		}
		else
			i++;
	}

	return (list);
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

	while (str[i] != ' ' && str[i] != '\0' && str[i] != '\n')
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
		if (str[i] != ' ')
			row++, i += nb_letter(i, str);
		else
			i++;

	return (row);
}
