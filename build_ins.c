#include "shell.h"
/**
 * _cd - funtion that recreates the cd build in
 * @line: input line
 * @args: the argument list
 * Return: always 1
 */
int _cd(char *line __attribute__((unused)), char **args)
{
	int error_check, j = 0;
	char **env = environ, *home, *new_PWD[4];
	char error[] = "./hsh: 1: cd: can't cd to ", finish = '\n';

	new_PWD[0] = "CD_CALL", new_PWD[1] = "PWD", new_PWD[3] = NULL;
	if (!args[1])
	{
		home = _getenv("HOME"), chdir(home); /*set OLDPWD*/
		new_PWD[2] = home, _setenv(line, new_PWD);
		return (1);
	}
	if ((_strncmp("-", args[1], 1)) == 0)
	{
		for (; env[j]; j++)
		{
			if ((_strncmp("OLDPWD", env[j], 6)) == 0)
			{
				home = _strtok(env[j], "=");
				home = _strtok(NULL, "="), chdir(home);
				new_PWD[2] = home, _setenv(line, new_PWD);
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
		_setenv(line, new_PWD);
	return (1);
}
/**
 * ext - funtion that recreates the exit build in
 * @line: input line
 * @args: the argument list
 * Return: always 0
 */
int ext(char *line, char **args)
{
	int status;

	if (args[1])
	{
		char error[] = "Invalid exit status\n";

		if (_isalpha(args[1]) == 1)
		{
			status = _atoi(args[1]);
			free(line), free(args);
			exit(status);
		}
		else
		{
			write(STDOUT_FILENO, error, _strlen(error));
			return (1);
		}
	}
	free(line), free(args);
	exit(127);

}
/**
 * _env - funtion that recreates the env build in
 * @l: input line
 * @args: the argument list
 * Return: always 0
 */
int _env(char *l __attribute__((unused)), char **args __attribute__((unused)))
{
	unsigned int i = 0, nbytes;

	for (; environ[i]; i++)
	{
		nbytes = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], nbytes);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}
