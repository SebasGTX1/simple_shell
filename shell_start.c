#include "shell.h"

void shell_start(void)
{
	char *line;
	char **args;
	int status;

	while (status)
	{
		printf("$ ");
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
