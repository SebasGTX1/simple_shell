#include "shell.h"
/**
 * _process_launcher - funtion that excecute a command
 * @args: argument list
 * Return: Always 1, for re-print the prompt after the
 * command excecution
 */
int _process_launcher(char **args)
{
	pid_t pid, wait_pid;
	int status;

	pid = fork();
	if (pid == 0)
		execve(args[0], args, NULL);
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			wait_pid = waitpid(pid, &status, WUNTRACED | WCONTINUED);
			if (wait_pid == -1)
				exit(EXIT_FAILURE);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
