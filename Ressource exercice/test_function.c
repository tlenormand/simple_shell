#include "main.h"

/* test the env */

int main(void)
{
	env_cpy = _double_pointer_copy(env_cpy, environ);
	_printenv(env_cpy);

	printf("\n\n-----VARIABLE NON PRESENTE-----\n");
	printf("_getenv HELLO : %s\n", _getenv("HELLO"));
	printf(" getenv HELLO : %s\n", getenv("HELLO"));

	printf("\n\n-----VARIABLE PRESENTE-----\n");
	printf("_getenv PATH : %s\n", _getenv("PATH"));
	printf(" getenv PATH : %s\n", getenv("PATH"));

	printf("\n\n-----GETENV MINUSCULE-----\n");
	printf("_getenv PAtH : %s\n", _getenv("PAtH"));
	printf(" getenv PAtH : %s\n", getenv("PAtH"));

	printf("\n\n-----GETENV EMPTY-----\n");
	printf("_getenv EMPTY : %s\n", _getenv(""));
	printf(" getenv EMPTY : %s\n", getenv(""));

	printf("\n\n-----GETENV \\0-----\n");
	printf("_getenv \\0 : %s\n", _getenv("\0"));
	printf(" getenv \\0 : %s\n", getenv("\0"));


	printf("\n\n\n\n-----SETENV NEW VARIABLE OVERWRITE = 0-----\n");
	printf("_setenv BONJOUR : %d\n", _setenv("BONJOUR", "bonjour", 0));
	printf(" setenv RUOJNOB : %d\n", setenv("RUOJNOB", "ruojnob", 0));
	printf("_getenv BONJOUR : %s\n", _getenv("BONJOUR"));
	printf(" getenv RUOJNOB : %s\n", getenv("RUOJNOB"));
	printf("_unsetenv BONJOUR : %d\n", _unsetenv("BONJOUR"));
	printf(" unsetenv RUOJNOB : %d\n", unsetenv("RUOJNOB"));

	printf("\n\n-----SETENV NEW VARIABLE OVERWRITE = 1-----\n");
	printf("_setenv BONJOUR : %d\n", _setenv("BONJOUR", "bonjour", 1));
	printf(" setenv RUOJNOB : %d\n", setenv("RUOJNOB", "ruojnob", 1));
	printf("_getenv BONJOUR : %s\n", _getenv("BONJOUR"));
	printf(" getenv RUOJNOB : %s\n", getenv("RUOJNOB"));
	printf("_unsetenv BONJOUR : %d\n", _unsetenv("BONJOUR"));
	printf(" unsetenv RUOJNOB : %d\n", unsetenv("RUOJNOB"));
	printf("_getenv BONJOUR : %s\n", _getenv("BONJOUR"));
	printf(" getenv RUOJNOB : %s\n", getenv("RUOJNOB"));

	printf("\n\n-----SETENV NEW VARIABLE BONjouR-----\n");
	printf("_setenv BONjouR : %d\n", _setenv("BONjouR", "bonjour", 1));
	printf(" setenv RuojNOB : %d\n", setenv("RuojNOB", "ruojnob", 1));
	printf("_getenv BONjouR : %s\n", _getenv("BONjouR"));
	printf(" getenv RuojNOB : %s\n", getenv("RuojNOB"));
	printf("_unsetenv BONjouR : %d\n", _unsetenv("BONjouR"));
	printf(" unsetenv RuojNOB : %d\n", unsetenv("RuojNOB"));
	printf("_getenv BONjouR : %s\n", _getenv("BONjouR"));
	printf(" getenv RuojNOB : %s\n", getenv("RuojNOB"));

	printf("\n\n-----SETENV NEW VARIABLE NAME NULL-----\n");
	printf("_setenv NAME NULL : %d\n", _setenv("", "bonjour", 1));
	printf(" setenv NAME NULL : %d\n", setenv("", "ruojnob", 1));
	printf("_getenv NAME NULL : %s\n", _getenv(""));
	printf(" getenv NAME NULL : %s\n", getenv(""));
	printf("_unsetenv NAME NULL : %d\n", _unsetenv(""));
	printf(" unsetenv NAME NULL : %d\n", unsetenv(""));
	printf("_getenv NAME NULL : %s\n", _getenv(""));
	printf(" getenv NAME NULL : %s\n", getenv(""));

	printf("\n\n-----SETENV NEW VARIABLE VALUE NULL-----\n");
	printf("_setenv VALUE NULL : %d\n", _setenv("BONJOUR", "bonjour", 1));
	printf(" setenv VALUE NULL : %d\n", setenv("RUOJNOB", "ruojnob", 1));
	printf("_getenv VALUE NULL : %s\n", _getenv("BONJOUR"));
	printf(" getenv VALUE NULL : %s\n", getenv("RUOJNOB"));
	printf("_unsetenv VALUE NULL : %d\n", _unsetenv("BONJOUR"));
	printf(" unsetenv VALUE NULL : %d\n", unsetenv("RUOJNOB"));
	printf("_getenv VALUE NULL : %s\n", _getenv("BONJOUR"));
	printf(" getenv VALUE NULL : %s\n", getenv("RUOJNOB"));

	printf("\n\n-----SETENV NEW VARIABLE WITH '=' IN NAME-----\n");
	printf("_setenv '=' NAME : %d\n", _setenv("BONJOU=R", "bonjour", 1));
	printf(" setenv '=' NAME : %d\n", setenv("RUOJNO=B", "ruojnob", 1));
	printf("_getenv '=' NAME : %s\n", _getenv("BONJOU=R"));
	printf(" getenv '=' NAME : %s\n", getenv("RUOJNO=B"));
	printf("_unsetenv '=' NAME : %d\n", _unsetenv("BONJOU=R"));
	printf(" unsetenv '=' NAME : %d\n", unsetenv("RUOJNO=B"));
	printf("_getenv '=' NAME : %s\n", _getenv("BONJOU=R"));
	printf(" getenv '=' NAME : %s\n", getenv("RUOJNO=B"));

	printf("\n\n-----SETENV NEW VARIABLE WITH '=' IN VALUE-----\n");
	printf("_setenv '=' VALUE : %d\n", _setenv("BONJOUR", "bonj=our", 1));
	printf(" setenv '=' VALUE : %d\n", setenv("RUOJNOB", "ruoj=nob", 1));
	printf("_getenv '=' VALUE : %s\n", _getenv("BONJOUR"));
	printf(" getenv '=' VALUE : %s\n", getenv("RUOJNOB"));
	printf("_unsetenv '=' VALUE : %d\n", _unsetenv("BONJOUR"));
	printf(" unsetenv '=' VALUE : %d\n", unsetenv("RUOJNOB"));
	printf("_getenv '=' VALUE : %s\n", _getenv("BONJOUR"));
	printf(" getenv '=' VALUE : %s\n", getenv("RUOJNOB"));

	printf("\n\n-----SETENV NEW VARIABLE WITH NUMBER IN NAME-----\n");
	printf("_setenv '=' VALUE : %d\n", _setenv("123", "123", 1));
	printf(" setenv '=' VALUE : %d\n", setenv("321", "321", 1));
	printf("_getenv '=' VALUE : %s\n", _getenv("123"));
	printf(" getenv '=' VALUE : %s\n", getenv("321"));
	printf("_unsetenv '=' VALUE : %d\n", _unsetenv("123"));
	printf(" unsetenv '=' VALUE : %d\n", unsetenv("321"));
	printf("_getenv '=' VALUE : %s\n", _getenv("123"));
	printf(" getenv '=' VALUE : %s\n", getenv("321"));

	printf("\n\n-----SETENV NEW VARIABLE WITH LOWERCASE, OVERWRITE = 1-----\n");
	printf("_setenv BONjOUR : %d\n", _setenv("BONjOUR", "bonjour", 1));
	printf(" setenv RUOjNOB : %d\n", setenv("RUOjNOB", "ruojnob", 1));
	printf("_getenv BONjOUR : %s\n", _getenv("BONjOUR"));
	printf(" getenv RUOjNOB : %s\n", getenv("RUOjNOB"));
	printf("_unsetenv BONjOUR : %d\n", _unsetenv("BONjOUR"));
	printf(" unsetenv RUOjNOB : %d\n", unsetenv("RUOjNOB"));
	printf("_getenv BONjOUR : %s\n", _getenv("BONjOUR"));
	printf(" getenv RUOjNOB : %s\n", getenv("RUOjNOB"));

	_free_double_pointer(env_cpy);

	printf("\n\nDONE\n");
	return (0);
}

/* test the linked listh path */

int main(void)
{
	env_cpy = _double_pointer_copy(env_cpy, environ);
	_printenv(env_cpy);

	const char *name = "PATH";
	const char *value = _getenv(name);
	char *path;
	int i = 0, j = 0;
	directory_t *head;

		head = NULL;

	path = malloc(sizeof(char) * strlen(value));
	if (path == NULL)
	{
		printf("Error: malloc()");
		return (-1);
	}

	while (value[i] != '\0')
	{
		path[j] = value[i];
		i++;
		j++;
		if (value[i + 1] == '\0')
			path[j] = value[i];
		if (value[i] == ':' || value[i + 1] == '\0')
		{
			head = add_node_end(&head, name, path);
			free(path);
			path = malloc(sizeof(char) * strlen(value));
			if (path == NULL)
			{
				printf("Error: malloc()");
				return (-1);
			}
			j = 0;
			i++;
		}
	}

	free(path);
	print_list(head);
	free_list(head);
	_free_double_pointer(env_cpy);
	return (0);
}