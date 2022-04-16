#include "shell.h"
/**
 * search_no_build_in - funtions that search if the argument is
 * a not build in funtion
 * @args: the argument list
 * Return: 1 if the funtion finds the command or 0 if fails
 */

int search_no_build_in(char **args)
{
	int j = 0;
	char **env = environ, *copy, *token;
	char *command = calloc(_strlen(args[0]) + 3, 1);
	char *dest = NULL;
	size_t command_size;
	struct stat sb;

	for (; env[j]; j++)
	{
		if ((_strncmp("PATH", env[j], 4)) == 0)
		{
			break;
		}
	}
	copy = malloc(_strlen(env[j]) + 1);
	_strcpy(copy, env[j]);
	_strcat(command, "/");
	_strcat(command, args[0]);
	token = _strtok(copy, DELIMITERS);
	command_size = _strlen(command) + 1;

	while ((token = _strtok(NULL, DELIMITERS)))
	{
		dest = calloc(_strlen(token) + 1 + command_size, 1);
		_strcat(dest, token);
		_strcat(dest, command);
		if (stat(dest, &sb) != -1)
		{
			args[0] = malloc(_strlen(dest) + 1);
			_strcpy(args[0], dest);
			free(dest);
			free(command);
			free(copy);
			return (1);
		}
		free(dest);
	}
	free(command);
	free(copy);
	return (0);
}
