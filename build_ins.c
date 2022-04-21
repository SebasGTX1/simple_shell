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
	int error_check;
	char *home, end = '\n', cwd[PATH_MAX];

	UNUSED(fail);
	if (!args[1])
	{
		home = _getenv("HOME");
		if (home)
		{
			error_check = chdir(home);
		}
		return (1);
	}
	if ((_strncmp("-", args[1], 1)) == 0)
	{
		home = _getenv("OLDPWD");
		if (home)
		{
			error_check = chdir(home);
		}
		write(STDOUT_FILENO, home, _strlen(home));
		write(STDOUT_FILENO, &end, 1);
		return (1);
	}
	error_check = chdir(args[1]);
	if (error_check == -1)
	{
		perror("hsh");
		return (1);
	}
	else
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
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
			write(STDERR_FILENO, error, _strlen(error));
			write(STDERR_FILENO, args[1], _strlen(args[1]));
			write(STDERR_FILENO, &finish, 1);
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
	if (i == 10)
		free(environ[i - 1]);
	return (1);
}
