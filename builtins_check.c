#include "shell.h"

/**
 * check_for_builtin - checks if the command is a builtin
 * @args: the arguments array
 *
 * Return: 1 if command is a builtin, 0 otherwise
 */

int check_for_builtin(char **args)
{
	if (!args[0])
	return (0);
if (!strcmp(args[0], "exit"))
shell_exit(args);
else if (!strcmp(args[0], "env"))
	shell_env();
else if (!strcmp(args[0], "setenv"))
	shell_setenv(args);
	else if (!strcmp(args[0], "unsetenv"))
	shell_unsetenv(args);
	else if (!strcmp(args[0], "help"))
	shell_help();
	else if (!strcmp(args[0], "cd"))
	shell_cd(args);
	else if (!strcmp(args[0], "clear"))
	shell_clear(args);
	else
	return (0);
	return (1);
}
