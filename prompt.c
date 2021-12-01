#include "main.h"

/**
 * main - prints "$ ", wait for the user, prints it on the next line
 * Return: always 0
 */

int main(void)
{
	size_t len = 0;
	char *line = NULL;
	char **argv;

	_initialisation();

	while (1)
	{
		printf("$ ");
		if ((getline(&line, &len, stdin)) == -1)
		{
			perror("./shell");
			break;
		}
		line[strlen(line) - 1] = '\0';
		if (*line != '\0')
		{
			argv = strtow(line);
			fork_main(argv);
			_free_double_pointer(argv);
		}
	}

	_close(line);
	return (0);
}


/**
 * fork_main - fork the main function
 * @line: input string got from the prompt
 * Return: 0 if success, on error -1
 */

int fork_main(char **argv)
{
	pid_t child_pid;
	int *end_child = 0;

	if (*argv[0] == '\0')
		return (0);

	if (strcmp(argv[0], "printlist") == 0)
		print_list(head);

	if (strcmp(argv[0], "env") == 0)
		_printenv(env_cpy);

	if (strcmp(argv[0], "exit") == 0)
	{
		_close(argv[0]);
		exit(98);
	}

	if (access(argv[0], F_OK) != -1)
		;
	else if (_stat(argv[0], head))
		;
	else
	{
		perror(argv[0]);
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
			kill(getpid(), SIGKILL);
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
	if (_stat(argv[1], head))
	{
		printf("1212212\n");
		chdir(_stat(argv[1], head));
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