#include "shell.h"
/**
 *
 *
 *
 */

char **av_line_saver(char *line)
{
  int bufsize = BUFSIZE, i = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
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
      tokens = realloc(tokens, bufsize * sizeof(char*));
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
  return tokens;
}
