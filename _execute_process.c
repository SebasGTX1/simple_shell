#include "shell.h"
/**
 *
 *
 */

int _execute(char **args)
{
	int (*func)(char **);
	struct stat sb;
	
	if (!args[0])
		return (1);
	func = get_build_in(args[0]);
	if (!func)
	{
	        if (stat(args[0], &sb) == -1)
        	{
                	if (search_no_build_in(args[0]))
                        	return (_process_launcher(args));
			else 
			{
				perror("command not found");
                		return (1);
			}

        	}
	}

	return (func(args));

}
