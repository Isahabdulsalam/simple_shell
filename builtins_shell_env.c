#include "shell.h"
#include <unistd.h>
#include <stdio.h>

/**
 * shell_env - Prints all the environment variables
 *
 * Return: void
 */

int shell_env(void)
{
	extern char **environ;

	int i;

	for (i = 0; environ[i]; i++)
	{
	_eputs(environ[i]);
	}

return (0);
}
