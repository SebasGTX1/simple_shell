#include "shell.h"
/**
 * shell_start - funtion that starts the shell and print the prompt
 * @exe: excecutable
 * Return: no return
 */
void shell_start(char *exe)
{
	char *line = NULL, **args = NULL;
	int status = 1, tty = 1;

	isatty(STDIN_FILENO) == 0 ? tty = 0 : tty;
	while (status)
	{
		tty == 1 ? write(STDOUT_FILENO, "theHELLshell$ ", 14) : tty;
		line = read_input();
		args = av_line_saver(line);
		status = _execute(line, args, exe);
		free(line);
		free(args);
	}
}
/**
 * handler - handler funtion
 * @sig_num: signal
 * return: no return
 */

void handler(int sig_num)
{
	char interruption __attribute__((unused));
	(void)sig_num;
	interruption = 1;
}
/**
 * main - excecute the shell start
 * @ac: arguments
 * @av: arguments vector
 * Return: always 0
 */
int main(int ac __attribute__((unused)), char **av)
{
	struct sigaction action = { 0 };

	action.sa_handler = handler;
	sigaction(SIGINT, &action, NULL);
	shell_start(av[0]);
	return (0);
}
