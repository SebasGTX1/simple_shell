#include "shell.h"
/**
 *
 *
 *
 */

char *read_input(void)
{
	char *line = NULL;

	if (!(line = _getline()))
	{
		if (getc(stdin) == EOF)
			exit(EXIT_SUCCESS);
	}
	return line;
}
