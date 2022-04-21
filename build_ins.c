#include "shell.h"
#include <limits.h>
/**
 * _cd - funtion that recreates the cd build in
 * @line: input line
 * @args: the argument list
 * @fail: fail status
 * Return: always 1
 */
int _cd(char *line __attribute__((unused)), char **args, int *fail)
{
	int error_check, j = 0;
	char **env = environ, *home, *new_PWD[4];
	char error[] = "./hsh: 1: cd: can't cd to ", finish = '\n';

	UNUSED(fail);
	new_PWD[0] = "CD_CALL", new_PWD[1] = "PWD", new_PWD[3] = NULL;
	if (!args[1])
	{
		home = _getenv("HOME"), chdir(home); /*set OLDPWD*/
		new_PWD[2] = home, _setenv(line, new_PWD, fail);
		return (1);
	}
	if ((_strncmp("-", args[1], 1)) == 0)
	{
		for (; env[j]; j++)
		{
			if ((_strncmp("OLDPWD", env[j], 6)) == 0)
			{
				home = strtok(env[j], "=");
				home = strtok(NULL, "="), chdir(home);
				new_PWD[2] = home, _setenv(line, new_PWD, fail);
				return (1);
			}
		}
	}
	chdir(args[1]);
	new_PWD[2] = args[1], error_check = chdir(args[1]);
	if (error_check != 0)
	{
		write(STDOUT_FILENO, error, _strlen(error));
		write(1, args[1], _strlen(args[1])), write(STDOUT_FILENO, &finish, 1);
	}
	else
		_setenv(line, new_PWD, fail);
	return (1);
}
/**
 * ext - funtion that recreates the exit build in
 * @line: input line
 * @args: the argument list
 * @fail: fail status
 * Return: always 0
 */
int ext(char *line, char **args, int *fail)
{
	int status;
	char error[] = "./hsh: 1: exit: Illegal number: ", finish = '\n';

	if (args[1])
	{
		status = _atoi(args[1]);
		if (_isalpha(args[1]) == 1 && status >= 0 && status <= INT_MAX)
		{
			free(line), free(args);
			exit(status);
		}
		else
		{
			*fail = 2;
			write(STDOUT_FILENO, error, _strlen(error));
			write(STDOUT_FILENO, args[1], _strlen(args[1]));
			write(STDOUT_FILENO, &finish, 1);
			return (2);
		}
	}
	free(line), free(args);
	exit(*fail);
}
/**
 * _env - funtion that recreates the env build in
 * @l: input line
 * @args: the argument list
 * @fail: fail status
 * Return: always 0
 */
int _env(char *l, char **args __attribute__((unused)), int *fail)
{
	unsigned int i = 0, nbytes;

	UNUSED(l);
	for (; environ[i]; i++)
	{
		nbytes = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], nbytes);
		write(STDOUT_FILENO, "\n", 1);
	}
	*fail = 0;
	return (1);
}
