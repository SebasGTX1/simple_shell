#include "shell.h"
/**
 *
 *
 *
 */

int _cd(char **args)
{
	int error_check;
	if (!args[1])
	{
		fprintf(stderr, "-bash: expected argument to \"cd\"\n");
		return (1);
	}
	error_check = chdir(args[1]);
	if (error_check != 0)
	{
		;/* error sms */
	}
	return (1);
}

int hlp(char **args __attribute__((unused)))
{
	int i = 0;
	char *builtin_str[] = {"cd", "help", "exit"};
	for (; i < 3; i++)
		printf("  %s\n", builtin_str[i]);
	return (1);
}

int ext(char **args __attribute__((unused)))
{
	return (0);
}
