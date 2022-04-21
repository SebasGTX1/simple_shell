#include "shell.h"
/**
 * _getline - futions that gets a line from the stdin
 *
 * Return: readed buffer
 */
char *_getline()
{
	int ctr = 0, i = 0, r = 0, buffsize = BUFSIZE;
	char *buff = _calloc(buffsize, 1);

	if (!buff)
	{
		free(buff);
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		r = read(STDIN_FILENO, &ctr, 1);
		if (r == 0)
		{
			free(buff);
			return (NULL);
		}
		if (ctr == '\n' || r == 0 || ctr == ';')
		{
			i++;
			buff[i] = '\0';
			return (buff);
		}
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
