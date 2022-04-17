#include "shell.h"
/**
 * read_input - funtions that reads the input of the shell
 *
 * Return: the line readed
 */

char *read_input(void)
{
	char *line = NULL, finish = '\n';

	line = _getline();
	if (!line)
	{
		write(STDOUT_FILENO, &finish, 1);
		exit(EXIT_SUCCESS);
	}
	return (line);
}
