#include "shell.h"
/**
 * _gline - my own _getlinefuntion
 * return: readed buffer
 */
char *_getline (void)
{
	int ctr = 0, i = 0, buffsize = BUFSIZE;
	char *buff = calloc(buffsize, 1);

	if (!buff)
	{
		dprintf(STDERR_FILENO,"%s\n", "buffer allocation failed");
		free(buff);
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		ctr = getc(stdin);
		if (i == 0 && ctr == EOF)
		{
			free(buff);
			return (NULL);
		}
		if (ctr == '\n' || ctr == EOF)
		{
			buff[i] = '\0';
			return (buff);
		}
		else
		{
			buff[i] = ctr;
		} i++;
		if (i >= buffsize)
		{
			buffsize += BUFSIZE;
			buff = realloc(buff, buffsize);
			
			if (!buff)
			{
				dprintf(STDERR_FILENO,"%s\n", "buffer allocation failed");
				free(buff);
				exit(EXIT_FAILURE);
			}
		}
	}
	free(buff);
}
