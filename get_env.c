#include "shell.h"
#include <stdlib.h>

/**
 * _getenv - Get the value of an environment variable
 * @name: Name of the enviroment variable
 *
 * Return: Value of the environment variable, or NULL if it doesn't exist
 */

char *_getenv(const char *name)
{
	char **env;
	size_t name_len = strlen(name);

	for (env = environ; *env != NULL; env++)
	{
	if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
	{
	return (*env + name_len + 1);
	}
	}

	return (NULL);

}
