#include "shell.h"

void _free(char **args)
{
	int i = 0;

	for (; args[i]; i++)
		;
	for (i--; i > 0; i--)
		free(args[i]);
	free(args);
}
void shell_start(void)
{
	char *line = NULL;
	char **args = NULL;
	int status = 1;
	int tty = 1;

	isatty(STDIN_FILENO) == 0 ? tty = 0 : tty;
	while (status)
	{
		tty == 1 ? write(STDOUT_FILENO, "theHELLshell$ ", 14) : tty;
		line = read_input();
		args = av_line_saver(line);
		status = _execute(args);
		free(line);
		free(args);
		
	}
}

int main(void)
{
	shell_start();
	return (0);
}
