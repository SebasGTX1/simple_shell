#include "shell.h"
/**
 * _cd - funtion that recreates the cd build in
 * @args: the argument list
 * Return: always 1
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

/**
 * hlp - funtion that recreates the help build in
 * @args: the argument list
 * Return: always 1
 */

int hlp(char **args __attribute__((unused)))
{
	int i = 0;
	char *builtin_str[] = {"cd", "help", "exit"};

	for (; i < 3; i++)
		printf("  %s\n", builtin_str[i]);
	return (1);
}

/**
 * ext - funtion that recreates the exit build in
 * @args: the argument list
 * Return: always 0
 */
int ext(char **args __attribute__((unused)))
{
	return (0);
}
/**
 * _env - funtion that recreates the env build in
 * @args: the argument list
 * Return: always 0
 */
int _env(char **args __attribute__((unused)))
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
