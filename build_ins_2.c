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

	return (1);
}
/**
 * _setenv - funtion that recreates the setenv build in
 * @line: input line
 * @args: the argument list
 * Return: always 1
 */

int _setenv(char *line __attribute__((unused)), char **args)
{
	char **env = environ, *new_env_var, *update_env_var;
	int i = 0, overwrite = 0;
	size_t s_var_name = _strlen(args[1]);
	size_t s_value = _strlen(args[2]) + 1;
	size_t env_len;

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
		_strcat(new_env_var, args[1]);
		_strcat(new_env_var, "=");
		_strcat(new_env_var, args[2]);
		return (add_env(new_env_var));
	}
	else
	{
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
	}
	return (1);
}
