#include "shell.h"
/**
 * shell_start - funtion that starts the shell and print the prompt
 * @exe: excecutable
 * Return: no return
 */
void shell_start(char *exe)
{
	char *line = NULL, **args = NULL, *prompt = NULL, *dir = NULL;
	char *dircolor = NULL;
	int status = 1, tty = 1, count = 1, dir_size, fail = 0;

	isatty(STDIN_FILENO) == 0 ? tty = 0 : tty;
	while (status)
	{
		dir = getcwd(NULL, 0);
		dir_size = _strlen(dir) + 1;
		dircolor = _calloc(dir_size + 15, 1);
		_strcat(dircolor, "\x1b[94m");
		_strcat(dircolor, dir);
		_strcat(dircolor, "\x1b[0m");
		prompt = calloc(44 + dir_size, 1);
		_strcat(prompt, "\x1b[92mSeRi_Shell\x1b[0m:");
		_strcat(prompt, dircolor);
		_strcat(prompt, "$ ");
		tty == 1 ? write(STDOUT_FILENO, prompt, 44 + dir_size) : tty;
		free(prompt);
		free(dircolor);
		free(dir);
		fflush(stdin);
		line = read_input();
		args = av_line_saver(line);
		status = _execute(line, args, exe, count, &fail);
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
	char finish = '\n';
	char *prompt = NULL, *dir = NULL;
	char *dircolor = NULL;
	int dir_size;

	write(STDOUT_FILENO, &finish, 1);
	dir = getcwd(NULL, 0);
	dir_size = _strlen(dir) + 1;
	dircolor = _calloc(dir_size + 15, 1);
	_strcat(dircolor, "\x1b[94m");
	_strcat(dircolor, dir);
	_strcat(dircolor, "\x1b[0m");
	prompt = calloc(44 + dir_size, 1);
	_strcat(prompt, "\x1b[92mSeRi_Shell\x1b[0m:");
	_strcat(prompt, dircolor);
	_strcat(prompt, "$ ");
	write(STDOUT_FILENO, prompt, 44 + dir_size);
	free(prompt);
	free(dircolor);
	free(dir);
}

/**
 * main - excecute the shell start
 * @ac: arguments
 * @av: arguments vector
 * Return: always 0
 */
int main(int ac __attribute__((unused)), char **av)
{

	signal(SIGINT, handler);
	shell_start(av[0]);
	return (0);
}
