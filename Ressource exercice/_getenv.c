#include "env.h"

/*
int main(void)
{
    const char *name = "PATH";
	char *env_name = NULL;

	env_name = _getenv(name);
	printf("variable %s : %s\n", name, env_name);

	free(env_name);
	return (0);
}*/

char *_getenv(const char *name)
{
	int i = 0, j = 0, k = 0;

	if (name == NULL)
		return (NULL);

	while (environ[i])
	{
		while (name[k])
		{
			/* if name not found */
			if (!(environ[i]))
			{
				return(environ[i]);
			}

			/* search for correspondance between environ and name */
			if (environ[i][j] == name[k])
				j++, k++;
			else
				j = 0, k = 0, i++;
		}

		/* if environ == '=' then name find in environ[i][j] */
		if (environ[i][j] == '=')
		{
			return (environ[i] + ++j);
		}
		j = 0;
		k = 0;
		i++;
	}

	/* if end of environ */
	return (NULL);
}
