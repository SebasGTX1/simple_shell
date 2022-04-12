#include "shell.h"
/**
 *
 *
 *
 */
int _process_launcher(char **args)
{
	pid_t pid, wait_pid;
	int status;

  	pid = fork();
  	if (pid == 0)
	{
		if (execv(args[0], args) == -1) 
			perror("error");
		exit(EXIT_FAILURE);
  	}

	else if (pid < 0) 
	    perror("error");
	else
	{
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
		{
			wait_pid = waitpid(pid, &status, WUNTRACED | WCONTINUED);
			if (wait_pid == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
		}
	}
  	return (1);
}
