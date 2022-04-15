#include "shell.h"
/**
 * _execute - funtion that check if the input is
 * a command (build in, non build in, a path of a
 * non build in or not a command at all)
 * @args: the argument list
 * Return: always 1 (exception: the excecution of the
 * exit build in)
 */

int _execute(char **args)
{
	int (*func)(char **);
	struct stat sb;

	if (!args[0])
		return (1);

	if (stat(args[0], &sb) != -1)
		return (_process_launcher(args));
	func = get_build_in(args[0]);
	if (!func)
	{
		if (search_no_build_in(args))
		{
			_process_launcher(args);
			free(args[0]);
			return (1);
		}
		else
		{
			perror("command not found");
			return (1);
		}
	}
	return (func(args));
}
