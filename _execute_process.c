#include "shell.h"
/**
 *
 *
 */

int _execute(char **args)
{
	int (*func)(char **);
	
	if (!args[0])
		return (1);
	func = get_build_in(args[0]);
	
	if (!func)
		return (_process_launcher(args));

	return (func(args));

}
