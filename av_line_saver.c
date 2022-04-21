#include "shell.h"
#include <string.h>
/**
 * av_line_saver - save the arguments of the line in a buffer
 * @line: the line to be saved
 * Return: a buffer with all the tokens saved from the line input
 */

char **av_line_saver(char *line)
{
	int bufsize = BUFSIZE, i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	while (*line == ' ')
		line++;
	if (!tokens)
	{
		free(tokens);
		exit(EXIT_FAILURE);
	}
	token = strtok(line, DELIMITERS);
	while (token)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, DELIMITERS);
	}
	tokens[i] = NULL;
	free(token);
	return (tokens);
}
