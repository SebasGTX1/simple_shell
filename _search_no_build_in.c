#include "shell.h"
/**
 * search_no_build_in - funtions that search if the argument is
 * a not build in funtion
 * @args: the argument list
 * Return: 1 if the funtion finds the command or 0 if fails
 */

int search_no_build_in(char **args)
{
	char *copy, *token;
	char *command = calloc(_strlen(args[0]) + 3, 1);
	char *dest = NULL, *path = NULL;
	size_t command_size;
	struct stat sb;

	path = _getenv("PATH");
	copy = malloc(_strlen(path) + 1);
	_strcpy(copy, path);
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
