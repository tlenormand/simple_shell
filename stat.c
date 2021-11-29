#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>

/**
 * main - stat example
 *
 * Return: 0, or 1 on error
 */
int main(int ac, char **av)
{
	unsigned int i;
	struct stat st;
	char cwd[PATH_MAX];
	char *curr = getcwd(cwd, sizeof(cwd));

	if (ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (1);
	}
	i = 1;
	while (av[i])
	{
		if (stat(av[i], &st) == 0)
		{
			printf("%s/%s\n", curr, av[i]);
		}
		else
		{
			printf("file not found : \'%s\'\n", av[i]);
		}
		i++;
	}
	return (0);
}
