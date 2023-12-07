#include "shell.h"

/**
 * _getenv - Get the value of an environment variable
 * @envp: Array of environment variables
 * @name: Name of the environment variable
 *
 * Return: Value of the environment variable, or NULL if it doesn't exist
 */

char *_getenv(char **envp, const char *name)
{
	size_t name_len = strlen(name);

	for (; *envp != NULL; envp++)
	{
	if (strncmp(*envp, name, name_len) == 0 && (*envp)[name_len] == '=')
	{
	return (*envp + name_len + 1);
	}
	}

return (NULL);
}
