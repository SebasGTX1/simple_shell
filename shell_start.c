#include "shell.h"
/**
 * shell_start - funtion that starts the shell and print the prompt
 * @exe: excecutable
 * Return: no return
 */
void shell_start(char *exe)
{
	char *line = NULL, **args = NULL;
	int status = 1, tty = 1, count = 1;

	isatty(STDIN_FILENO) == 0 ? tty = 0 : tty;
	while (status)
	{
		tty == 1 ? write(STDOUT_FILENO, "theHELLshell$ ", 14) : tty;
		fflush(stdin);
		line = read_input();
		args = av_line_saver(line);
		status = _execute(line, args, exe, count);
		count += 1;
		free(line);
		free(args);
	}
}
/**
 * handler - handler funtion
 * @sig_num: signal
 * return: no return
 */

static void handler(int sig_num __attribute__((unused)))
{
	signal(SIGINT, handler);
	fflush(stdout);
}

/**
 * main - excecute the shell start
 * @ac: arguments
 * @av: arguments vector
 * Return: always 0
 */
int main(int ac __attribute__((unused)), char **av)
{

	/*signal(SIGINT, handler);*/
	signal(SIGINT, SIG_IGN);
	shell_start(av[0]);
	return (0);
}
