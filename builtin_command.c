#include "shell.h"

/**
 * shell_cd - changes the current working directory of the shell
 * @args: array of arguments
 */
void shell_cd(char **args)
{
    char *dir = args[1];
    int ret;

    if (dir == NULL || strcmp(dir, "~") == 0)
    {
        dir = _getenv("HOME");
        if (dir == NULL)
        {
            _eputs("cd: No HOME directory found\n");
            return;
        }
    }
    else if (strcmp(dir, "-") == 0)
    {
        dir = _getenv("OLDPWD");
        if (dir == NULL)
        {
            _eputs("cd: OLDPWD not found\n");
            return;
        }
    }

    ret = chdir(dir);
    if (ret == -1)
    {
        perror("cd");
        return;
    }

    if (setenv("OLDPWD", _getenv("PWD"), 1) != 0)
    {
        perror("setenv");
        return;
    }

    if (setenv("PWD", getcwd(NULL, 0), 1) != 0)
    {
        perror("setenv");
        return;
    }
}
