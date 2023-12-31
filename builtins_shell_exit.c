#include "shell.h"

void free_last_input(void);

/**
 * shell_exit - Exit the shell.
 * @args: Arguments.
 *
 * Return: Nothing.
 */

void shell_exit(char **args)
{
	int status = 0;

	if (args[1] != NULL)
	{
	status = atoi(args[1]);
	}

free_tokens(args);
free_last_input();
exit(status);
}
