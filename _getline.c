#include "shell.h"
/**
 * _getline - futions that gets a line from the stdin
 *
 * Return: readed buffer
 */
char *_getline(void)
{
	int ctr = 0, i = 0, buffsize = BUFSIZE;
	char *buff = _calloc(buffsize, 1);

	if (!buff)
	{
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
		else if (ctr == '\t')
			continue;
		else
			buff[i] = ctr;
		i++;
		if (i >= buffsize)
		{
			buffsize += BUFSIZE;
			_realloc(buff, buffsize);
			if (!buff)
			{
				free(buff);
				exit(EXIT_FAILURE);
			}
		}
	}
}
