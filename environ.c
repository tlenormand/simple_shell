#include "main.h"

/**
 * _printenv - function that print the environment
 * @env: address of the environment to print
 */

void _printenv(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		_puts_string(env[i]);
		_putchar('\0');
	}
}


/**
 * _getenv - function that get the environment of a variable
 * @name: name of the environment variable to get the value
 * Return: a pointer to the value of the variable, NULL if failed
 */

char *_getenv(const char *name)
{
	int i = 0, j = 0, k = 0;

	if (name == NULL)
		return (NULL);

	while (env_cpy[i])
	{
		while (name[k])
		{
			/* if name not found */
			if (!(env_cpy[i]))
			{
				return (NULL);
			}

			/* search for correspondance between env and name */
			if (env_cpy[i][j] == name[k])
				j++, k++;
			else
				j = 0, k = 0, i++;
		}

		/* if env == '=' then name find in env_cpy[i][j] */
		if (env_cpy[i][j] == '=')
		{
			return (env_cpy[i] + ++j);
		}
		j = 0;
		k = 0;
		i++;
	}

	/* if end of env */
	return (NULL);
}


/**
 * _setenv - function that change or add an environment variable
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @overwrite: if 0 then don't change the value, if other overwrite the value
 * Return: 0 on success, -1 on error
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	char *new_env = NULL;

	if (name == NULL || *name == '\0' || value == NULL || strchr(name, '='))
		return (-1);

	if (overwrite && _getenv(name))
		_unsetenv(name);

	/* new variable | +2 for '\0' and '=' */
	new_env = malloc(sizeof(char) * (_strlen((char *)name) +
	_strlen((char *)value) + 2));
	if (new_env == NULL)
	{
		return (-1);
	}

	new_env = _strcat(_strcat(_strcpy(new_env, (char *)name), "="),
	(char *)value);

	_add_value_double_ptr(env_cpy, new_env);

	free(new_env);

	return (0);
}


/**
 * _unsetenv - function that unset an environment variable
 * @name: name of the environment variable to unset
 * Return: 0 on success, -1 on error
 */

int _unsetenv(const char *name)
{
	int i = 0, j = 0, k = 0;

	if (name == NULL || *name == '\0')
		return (-1);

	while (env_cpy[i])
	{
		while (name[k])
		{

			if (!(env_cpy[i]))
			{
				return (-1);
			}

			if (env_cpy[i][j] == name[k])
				j++, k++;
			else
				j = 0, k = 0, i++;
		}

		if (env_cpy[i][j] == '=')
		{
			free(env_cpy[i]);
			env_cpy[i] = NULL;
			break;
		}
		j = 0;
		k = 0;
		i++;
	}

	if (!env_cpy[i])
		return (0);

	return (-1);
}
