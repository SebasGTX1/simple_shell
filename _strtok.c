#include "shell.h"

unsigned int check_d(char c, char *d)
{
	while (*d != '\0')
	{
		if (c == *d)
			return (1);
		d++;
	}
	return (0);
}
/**
 *
 *
 *
 */
char * _strtok(char *str, char *d)
{
	static char *input_backup;
	char *ret;

	if (!str)
		str = input_backup;
	if (!str)
		return (NULL);
	while (check_d(*str, d))
		str++;
	if (*str == '\0')
		return (NULL);

	ret = str;

	while (1)
	{
		if (*str == '\0')
		{
			input_backup = str;
			return (ret);
		}
		if (check_d(*str, d))
		{
			*str = '\0';
			input_backup = str + 1;
			return (ret);
		}
		str++;
	}
}
