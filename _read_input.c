#include "shell.h"
/**
 *
 *
 *
 */

char *read_input(void)
{
	char *line;

	if ((line = _getline()) == NULL)
	{
		if (getc(stdin) == EOF)
			exit(EXIT_SUCCESS);
	}
	return line;
}
