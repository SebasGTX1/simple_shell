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
		if (getc(stdin) == -1)
			exit(EXIT_SUCCESS);
	else
	{
		/* error sms*/
		exit(EXIT_FAILURE);
	}
	return line;
}
