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
	char **env = environ, *home;

	if (!args[1])
	{
		for (; env[j]; j++)
		{
			if ((_strncmp("HOME", env[j], 4)) == 0)
			{
				home = _strtok(env[j], "=");
				home = _strtok(NULL, "=");
				chdir(home);
				return (1);
			}
		}
	}
	if ((_strncmp("-", args[1], 1)) == 0)
	{
		for (; env[j]; j++)
		{
			if ((_strncmp("OLDPWD", env[j], 6)) == 0)
			{
				home = _strtok(env[j], "=");
				home = _strtok(NULL, "=");
				chdir(home);
				return (1);
			}
		}
	}
	chdir(args[1]);
	error_check = chdir(args[1]);
	if (error_check != 0)
	{
		perror(args[1]);
	}
	return (1);
}
/**
 * hlp - funtion that recreates the help build in
 * @l: input line
 * @args: the argument list
 * Return: always 1
 */

int hlp(char *l __attribute__((unused)), char **args __attribute__((unused)))
{
	int i = 0;
	char *builtin_str[] = {"cd", "help", "exit"};

	for (; i < 3; i++)
		printf("  %s\n", builtin_str[i]);
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
		status = atoi(args[1]);
		free(line);
		free(args);
		exit(status);
	}
		return (0);

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
