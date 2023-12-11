#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <errno.h>

#define COMMAND_LENGTH 100
#define ARGUMENT 10

void exe_com(char *com)
{
	char *arg[ARGUMENT];
	char *token = strtok(com, " ");
	int i = 0;

	while (token != NULL && i < ARGUMENT - 1)
	{
		arg[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	arg[i] = NULL;

	pid_t pid = fork();

	if (pid < 0)
	{
		fprintf(stderr, "Fork failed\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(arg[0], arg) == -1)
		{
			fprintf(stderr, "Command not found or failed to execute: %s\n", arg[0]);
			exit(EXIT_FAILURE);
		}
	}
	else 
	{
		int list;
		waitpid(pid, &list, 0);
	}
}
