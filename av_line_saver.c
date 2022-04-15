#include "shell.h"
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

	if (!tokens)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = _strtok(line, DELIMITERS);
	while (token)
	{
		tokens[i] = token;
		i++;
		if (i >= bufsize)
		{
			bufsize += BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = _strtok(NULL, DELIMITERS);
	}
	tokens[i] = NULL;
	free(token);
	return (tokens);
}
