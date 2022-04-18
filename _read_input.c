#include "shell.h"
/**
 * read_input - funtions that reads the input of the shell
 *
 * Return: the line readed
 */

char *read_input(void)
{
	char *line = NULL, finish = '\n';
	int tty = 1;

	isatty(STDIN_FILENO) == 0 ? tty = 0 : tty;
	line = _getline();
	if (!line)
	{
		tty == 1 ? write(STDOUT_FILENO, &finish, 1) : tty;
		exit(EXIT_SUCCESS);
	}
	return (line);
}
