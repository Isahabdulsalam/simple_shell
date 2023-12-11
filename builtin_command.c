#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <errno.h>

#define LENGTH 100
#define ARGUMENT 10

int main(void)
{
	char max[LENGTH];
	char *arg[ARGUMENT];

	while (1)
	{
		printf("team_project_shell$ ");
		fflush(stdout);

		if (fgets(max, sizeof(max), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		max[strcspn(max, "\n")] = '\0';

		char *token = strtok(max, " ");
		int a = 0;

		while (token != NULL && a < ARGUMENT - 1)
		{
			arg[a] = token;
			token = strtok(NULL, " ");
			a++;
		}
		arg[a] = NULL;

		if (strcmp(arg[0], "exit") == 0)
		{
			int status = 0;

			if (arg[1] != NULL)
			{
				status = atoi(arg[1]);
			}

			exit(status);
		} 
		else if (strcmp(arg[0], "cd") == 0)
		{
			char new_direc[PATH_MAX];

			if (arg[1] == NULL || strcmp(arg[1], "~") == 0)
			{
				const char *home_direc = getenv("HOME");

				if (home_direc == NULL)
				{
					fprintf(stderr, "HOME environment variable not found\n");
					continue;
				}

				strcpy(new_direc, home_direc);
			}

			else if (strcmp(arg[1], "-") == 0) 
			{
				const char *prev_direc = getenv("OLDPWD");

				if (prev_direc == NULL)
				{
					fprintf(stderr, "OLDPWD not found\n");
					continue;
				}
				strcpy(new_direc, prev_direc);
			}
			else
			{
				strcpy(new_direc, arg[1]);
			}

			char old_direc[PATH_MAX];
			if (getcwd(old_direc, sizeof(old_direc)) == NULL)
			{
				perror("getcwd");
				continue;
			}

			if (chdir(new_direc) != 0)
			{
				perror("chdir");
				continue;
			}

			if (setenv("OLDPWD", old_direc, 1) != 0)
			{
				perror("setenv");
				continue;
			}
			if (setenv("PWD", new_direc, 1) != 0)
			{
				perror("setenv");
				continue;
			}
		}
		else
		{
			pid_t pid = fork();

			if (pid < 0)
			{
				fprintf(stderr, "Fork failed\n");
				return EXIT_FAILURE;
			}
			else if (pid == 0)
			{
				if (execvp(arg[0], arg) == -1)
				{
					fprintf(stderr, "failed to execute: %s\n", arg[0]);
					return EXIT_FAILURE;
				}
			}
			else
			{
				int list;
				waitpid(pid, &list, 0);
			}
		}
	}
	return EXIT_SUCCESS;
}
