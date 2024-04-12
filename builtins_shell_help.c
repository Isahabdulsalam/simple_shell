#include "shell.h"

/**
 * shell_help - displays help information for built-in commands
 */
void shell_help(void)
{
	_eputs("\nShell Version 1.0.0\n\n");
	_eputs("Usage: ./hsh\n\n");
	_eputs("Shell built-in commands:\n\n");
	_eputs("help\t\tDisplay this help information\n\n");
	_eputs("cd [dir]\tChange the current working directory\n\n");
	_eputs("env\t\tDisplay the environment variables\n\n");
	_eputs("setenv\t\tSet an environment variable\n\n");
	_eputs("unsetenv\tUnset an environment variable\n\n");
	_eputs("exit\t\tExit the shell\n\n");
}
