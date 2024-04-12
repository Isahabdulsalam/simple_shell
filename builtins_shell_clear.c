#include "shell.h"
#include <stdlib.h>

/**
 * shell_clear - clears the terminal screen.
 * @args: an array of arguments (unused)
 *
 * Return: 1 to continue executing,
 *         or 0 to exit.
*/
int shell_clear(char **args)
{
	(void)args;

	system("clear");

	return (1);
}
