#include "shell.h"
/**
 * get_build_in - gets the correct build-in
 * @build_in: build in identifier
 * Return: the build in funtion usage
 */
int (*get_build_in(char *build_in))(char **args)
{
	build_in_t array[] = {
	{"cd", _cd},
	{"help", hlp},
	{"exit", ext},
	{"env", _env}
	};

	int i = 0, s_bi = _strlen(build_in), s_abi = 0;

	while (i < 4)
	{
		s_abi = _strlen(array[i].build_in);
		if (s_abi == s_bi)
		{
			if (_strncmp(build_in, array[i].build_in, s_bi) == 0)
				return (array[i].func);
			}
		i++;

	}
	return (0);
}
