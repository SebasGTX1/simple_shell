#include "shell.h"

void shell_start(void)
{
	char *line;
	char **args;
	int status;
	int tty = 1;

	isatty(STDIN_FILENO) == 0 ? tty = 0 : tty;
	while (status)
	{
		tty == 1 ? write(STDOUT_FILENO, "($) ", 4) : tty;
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
