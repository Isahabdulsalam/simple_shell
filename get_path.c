#include "shell.h"

/**
 * get_path - Returns the value of the PATH enviroment variable.
 *
 * Return: Pointer to the value of $PATH.
 */

char *get_path(void)
{
	return (_getenv("PATH"));
}

#include "shell.h"

/**
 * find_in_path - Looks for a command in each directory specified in the PATH
 *                environment variable
 * @command: pointer to `command` string to look for.
 *
 * Return: pointer to string containing the full path (success) if it is found,
 *         or NULL if it is not found (failure).
*/

char *find_in_path(char *command)
{
	struct stat st;
	int i, stat_ret = -1;
	char buf[PATH_MAX_LENGTH], *path, *ret, **dir;

	path = get_path();
	if (!path)
	return (NULL);
dir = tokensize(path, PATH_SEPARATOR);
if (!dir)
{
	free(path);
	return (NULL);
}
for (i = 0; dir[i]; i++)
{
	_memset(buf, 0, PATH_MAX_LENGTH);
	_strcpy(buf, dir[i]);
	_strcat(buf, "/");
	_strcat(buf, command);
	stat_ret = stat(buf, &st);
	if (stat_ret == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
	{
	free_tokens(dir);
	ret = malloc(sizeof(char) * (strlen(buf) + 1));
	if (!ret)
	{
	free(path);
	return (NULL);
	}
	strcpy(ret, buf);
	return (ret);
	}
}
free_tokens(dir);
free(path);
return (NULL);
}
