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

	for (; environ[i]; i++)
		;
	new_env = malloc((i + 1) * sizeof(char *));
	free(new_env);
	new_env = env;
	new_env[i] = malloc(_strlen(new_env_var) + 1);
	_strcpy(new_env[i], new_env_var);
	environ = new_env;
	environ[i + 1] = NULL;
	free(new_env[i]);
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
		new_env_var = malloc(s_var_name + s_value + 1);
		memcpy(new_env_var, args[1], s_var_name);
		new_env_var[s_var_name] = '=';
		memcpy(&new_env_var[s_var_name + 1], args[2], s_value);
		return (add_env(new_env_var));
	}

	else
	{
	env_len = _strlen(env[i]);
	if (env_len < (s_var_name + s_value + 1))
	{
		update_env_var = malloc(s_var_name + s_value + 1);
		env[i] = update_env_var;

	}
	memcpy(env[i], args[1], s_var_name);
	env[i][s_var_name] = '=';
	memcpy(&env[i][s_var_name + 1], args[2], s_value);
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

	UNUSED(fail);
	if (!args[1])
	{
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
