#include "shell.h"
/**
 * read_input - funtions that reads the input of the shell
 *
 * Return: the line readed
 */

char *read_input(void)
{
	char *line = NULL;

	line = _getline();
	if (!line)
	{
		if (getc(stdin) == EOF)
			exit(EXIT_SUCCESS);
	}
	return (line);
}
