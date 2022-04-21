#include "shell.h"
/**
 * _getenv - funtion to get the PATH form the environment variable.
 * @name: the string to find in the environment variable.
 *
 * Return: the PATH directories.
 */

char *_getenv(const char *name)
{
	int len = _strlen((char *)name);
	char **env = environ;

	while (*env != NULL)
	{
		if (_strncmp(*env, (char *)name, len) == 0)
		{
			return (*env + len + 1);
		}
		env++;
	}
	return (NULL);
}
