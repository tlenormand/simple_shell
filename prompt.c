#include "main.h"

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)env;

	_prompt(av);

	return (0);
}

/**
 * main - prints "$ ", wait for the user, prints it on the next line
 * Return: always 0
 */

int _prompt(char **av)
{
	size_t len = 0;
	char *line;
	char **argv;
	int loop = 1;

	_initialisation();

	while (1)
	{
		line = malloc(sizeof(char) * 126);
		printf("%s%s%s$ ", KMAG, _getenv("PWD"), KNRM);
		if ((getline(&line, &len, stdin)) == -1)
		{
			line[strlen(line) - 1] = '\0';
			argv = strtow(line);
			_error(av[0], loop, argv[0]);
			break;
		}
		line[strlen(line) - 1] = '\0';
		if (*line != '\0')
		{
			argv = strtow(line);
			fork_main(argv, av, loop);
			_free_double_pointer(argv);
		}
		loop++;
		free(line);
	}

	_close(line);
	return (0);
}





void _error(char *av, int loop, char *command)
{
	printf("%s: %d: %s: not found\n", av, loop, command);
}







/**
 * fork_main - fork the main function
 * @line: input string got from the prompt
 * Return: 0 if success, on error -1
 */

int fork_main(char **argv, char **av, int loop)
{
	pid_t child_pid;
	int *end_child = 0;

	if (strcmp(argv[0], "cd") == 0)
	{
		_change_wd(argv, head);
		return (0);
	}

	if (strcmp(argv[0], "whatcolor") == 0)
	{
		whatcolor();
		return (0);
	}

	if (strcmp(argv[0], "printlist") == 0)
		print_list(head);

	/*if (strcmp(argv[0], "env") == 0)
	{
		_printenv(env_cpy);
		return (0);
	}*/

	if (strcmp(argv[0], "exit") == 0)
	{
		if (argv)
			_free_double_pointer(argv);
		if (env_cpy)
			_free_double_pointer(env_cpy);
		if (head)
			free_list(head);
		exit(EXIT_SUCCESS);
	}

	if (access(argv[0], F_OK) != -1)
		;
	else if (_stat(argv[0], head))
		;
	else
	{
		_error(av[0], loop, argv[0]);
		/*_free_double_pointer(argv);*/
		return(-1);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: fork()");
		return (-1);
	}

	if (child_pid == 0)
	{
		/* child process */
		if (exe_func(argv) == -1)
		{
			_error(av[0], loop, argv[0]);
		}
	}
	else
	{
		/*_free_double_pointer(argv);*/
		wait(end_child);
	}

	return (0);
}







int _change_wd(char **argv, directory_t *head)
{
	char *current_wd = calloc(1024, sizeof(char));
	(void) head;

	if (argv[1] == NULL || strcmp(argv[1], "~") == 0)
	{
		_setenv("OLDPWD", _getenv("PWD"), 1);
		chdir(_getenv("HOME"));
		_setenv("PWD", getcwd(current_wd, 1024 * sizeof(char)), 1);
		free(current_wd);
		return(0);
	}
	else if (strcmp(argv[1], "-") == 0)
	{
		printf("%s\n", _getenv("OLDPWD"));
		chdir(_getenv("OLDPWD"));
		_setenv("OLDPWD", _getenv("PWD"), 1);
		_setenv("PWD", getcwd(current_wd, 1024 * sizeof(char)), 1);
		free(current_wd);
		return(0);
	}
	else if (access(argv[1], F_OK) != -1)
	{
		_setenv("OLDPWD", getcwd(current_wd, 1024 * sizeof(char)), 1);
		chdir(argv[1]);
		_setenv("PWD", getcwd(current_wd, 1024 * sizeof(char)), 1);
		free(current_wd);
		return(0);
	}

	return (1);
}







/**
 * exe_func - function that execute a command
 * @argv: argument income
 * Return: nothing if success, -1 on error
 */

int exe_func(char **argv)
{
	char *file;

	if (access(argv[0], F_OK) != -1)
		file = argv[0];
	else if (_stat(argv[0], head))
		file = _stat(argv[0], head);

	if (file != NULL)
		if (execve(file, argv, env_cpy) == -1)
			perror("./shell");
	printf("bonjour\n");
	return (-1);
}








/**
 * _stat - function that fin the path of a file
 * @file: file to find the path
 * @buf: linked list of all path in environment
 * Return: path, NULL if failled or don't find
 */

char *_stat(const char *file, directory_t *buf)
{
	char *path;
	buf = head;

	while (buf)
	{
		path = malloc(sizeof(char) * (strlen(file) + strlen(buf->value) + 2));
		if (path == NULL)
			return (NULL);
		path = strcat(strcat(strcpy(path, buf->value), "/"), file);

		if (access(path, F_OK) != -1)
		{
			return(path);
		}
		free(path);

		buf = buf->next;
	}

	return (NULL);
}







void whatcolor(void)
{
	printf("%sKRED red\n", KRED);
    printf("%sKGRN green\n", KGRN);
    printf("%sKYEL yellow\n", KYEL);
    printf("%sKBLU blue\n", KBLU);
    printf("%sKMAG magenta\n", KMAG);
    printf("%sKCYN cyan\n", KCYN);
    printf("%sKWHT white\n", KWHT);
    printf("%sKNRM normal\n", KNRM);
}
