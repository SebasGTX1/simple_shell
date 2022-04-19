#include "shell.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/**
 * hlp - funtion that recreates the help build in
 * @l: input line
 * @args: the argument list
 * Return: always 1
 */

int hlp(char *l __attribute__((unused)), char **args __attribute__((unused)))
{
	char *file_name, finish = '\n';
	int fd, read_val, write_val, i = 0;
	char *buffer;
	char *build_ins[] = {"env", "help", "cd", "setenv", "unsetenv", "exit", NULL};
	char *help_files[] = {"env_help", "help_help", "cd_help",
		"setenv_help", "unsetenv_help", "exit_help", NULL};

	for (; build_ins[i]; i++)
	{
		if (!args[1])
		{
			write(STDOUT_FILENO, build_ins[i], _strlen(build_ins[i]));
			write(STDOUT_FILENO, &finish, 1);
		}
			else if (_strcmp(args[1], build_ins[i]) == 0)
		{
			file_name = help_files[i];
			fd = open(file_name, O_RDWR);
			buffer = malloc(BUFSIZE);
			if (buffer == NULL)
				return (-1);
			while ((read_val = read(fd, buffer, BUFSIZE)) > 0)
			{
				write_val = write(STDOUT_FILENO, buffer, read_val);
				if  (write_val == -1)
					return (-1);
			}
			free(buffer);
			close(fd);
			return (1);
		}
	}


	return (1);
}
