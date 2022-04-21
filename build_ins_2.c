#include "shell.h"
/**
 * add_env - funtion that adds a new env variable
 * to the current enviroment
 * @new_env_var: the new variable to be add
 * Return: always 1
 */

int add_env(char *new_env_var)
{
	char **new_env, **env = environ;
	int i = 0;

	for (; env[i]; i++)
		;
	new_env = malloc((i + 1) * sizeof(char *));
	new_env = env;
	new_env[i] = malloc(_strlen(new_env_var) + 1);
	new_env[i] = _strcpy(new_env[i], new_env_var);
	environ = new_env;
	environ[i + 1] = NULL;
	free(new_env_var);

	return (1);
}
/**
 * _setenv - funtion that recreates the setenv build in
 * @line: input line
 * @args: the argument list
 * @fail: fail status
 * Return: always 1
 */

int _setenv(char *line __attribute__((unused)), char **args, int *fail)
{
	char **env = environ, *new_env_var, *update_env_var;
	int i = 0, overwrite = 0, s_var_name, s_value, env_len;

	UNUSED(fail);
	if (!args[1] || !args[2])
	{
		return (1);
	}
	s_var_name = _strlen(args[1]), s_value = _strlen(args[2]) + 1;
	for (; env[i]; i++)
	{
		if (_strncmp(env[i], args[1], s_var_name) == 0)
		{
			overwrite = 1;
			break;
		}
	}
	if (!overwrite)
	{
		new_env_var = _calloc(s_var_name + s_value + 3, 1);
		_strcat(new_env_var, args[1]), _strcat(new_env_var, "=");
		_strcat(new_env_var, args[2]);
		return (add_env(new_env_var));
	}
	env_len = _strlen(env[i]) + 1;
	if (env_len < (s_var_name + s_value + 3))
	{
		update_env_var = _calloc(s_var_name + s_value + 3, 1);
		env[i] = update_env_var;
	}
	else
	{
		update_env_var = _calloc(s_var_name + s_value + 3, 1);
		env[i] = update_env_var;
		_strcat(update_env_var, args[1]), _strcat(update_env_var, "=");
		_strcat(update_env_var, args[2]);
	}
	return (1);
}
/**
 * _unsetenv - funtion that recreates the setenv build in
 * @line: input line
 * @args: the argument list
 * @fail: fail status
 * Return: always 1
 */

int _unsetenv(char *line __attribute__((unused)), char **args, int *fail)
{
	char **env = environ;
	int i = 0, size = 0;
	char error[] = "Invalid input for unsetenv. Please check: help unsetenv\n";

	UNUSED(fail);
	if (!args[1])
	{
		write(STDOUT_FILENO, error, _strlen(error));
		return (1);
	}
	for (; env[size]; size++)
		;
	for (; env[i]; i++)
	{
		if (_strncmp(env[i], args[1], _strlen(args[1])) == 0)
		{
			for (; i < size - 1; i++)
				env[i] = env[i + 1];
			env[i] = NULL;
		}
	}
	return (1);
}
