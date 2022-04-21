#include "shell.h"
/**
 * read_input - funtions that reads the input of the shell
 * @fail: fail status
 * Return: the line readed
 */

char *read_input(int *fail)
{
	char *line = NULL, finish = '\n';
	int tty = 1;
	size_t n = 0;

	isatty(STDIN_FILENO) == 0 ? tty = 0 : tty;
	if (getline(&line, &n, stdin) == -1)
	{
		free(line);
		if (feof(stdin))
		{
			tty == 1 ? write(STDOUT_FILENO, &finish, 1) : tty;
			exit(*fail);
		}
	}
	return (line);
}
