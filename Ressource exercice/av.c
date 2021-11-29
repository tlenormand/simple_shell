#include <stdio.h>

/**
 * main - print all arguments without using ac
 * @ac: number of character, character can be more than one
 * @av: name of the string
 * Return: Always 0.
 */

int main(int ac, char **av)
{
	(void) ac;
	int i = 0, j = 0, nbchar;

	while (av[i] != NULL)
	{
		while (av[i][j] != '\0')
		{
			nbchar++;
			j++;
		}
		printf("%s", av[i]);
		if (av[i + 1] != NULL)
		{
			printf(" ");
			nbchar++;
		}
		i++;
		j = 0;
	}
	printf("\n");
	return (nbchar);
}
