#include "shell.h"
/**
 *
 *
 *
 */

int search_no_build_in(char *args)
{
	int j = 0;
        char **env = environ, *copy, *token, *command = calloc(strlen(args) + 3, 1);
        char *dest = NULL;
	size_t command_size;
        struct stat sb;

        for (; env[j]; j++)
        {
                if ((strncmp("PATH", env[j], 4)) == 0)
                {
                        break;
                }
        }

        copy = malloc(strlen(env[j]) + 1);
        strcpy(copy, env[j]);
	strcat(command, "/");
	strcat(command, args);
        token = strtok(copy, ":=");
	command_size = strlen(command) + 1;

        while ((token = strtok(NULL, ":")))
        {
                dest = calloc(strlen(token) + 1 + command_size, 1);
                strcat(dest, token);
                strcat(dest, command);
                if (stat(dest, &sb) != -1)
                {
                        args = strcpy(args, dest); 
			free(dest);
        		free(command);
			free(copy);
        		return (1);
                }
                free(dest);
        }
	free(command);
        free(copy);
	return (0);
}
