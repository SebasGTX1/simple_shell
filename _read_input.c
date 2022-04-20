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

	isatty(STDIN_FILENO) == 0 ? tty = 0 : tty;
	line = _getline(fail);
	if (!line)
	{
		tty == 1 ? write(STDOUT_FILENO, &finish, 1) : tty;
		exit(*fail);
	}
	return (line);
}
