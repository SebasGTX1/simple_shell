#include "shell.h"
/**
 * shell_start - funtion that starts the shell and print the prompt
 *
 * Return: no return
 */
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
/**
 * main - excecute the shell start
 *
 * Return: always 0
 */
int main(void)
{
	shell_start();
	return (0);
}
