#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define LENGTH 1000
#define VARIABLE_NAME 20
#define FILE_LINE_LENGTH 1000
#define FILE_LINES 100

/**
 * handle_variables - function that reads a line from a file.
 * @cmd - commands
 */

char variables[VARIABLE_NAME][LENGTH];
int num_variables = 0;

void handle_variables(char *cmd)
{
	char temp[LENGTH];
	int a = 0;
	int b = 0;

	while (cmd[a] != '\0')
	{
		if (cmd[a] == '$' && cmd[a + 1] == '?')
		{
			snprintf(temp, LENGTH, "%d", WEXITSTATUS(system(NULL)));
			strcat(cmd, temp);
			a += 2;
		}
		else if (cmd[a] == '$' && cmd[a + 1] == '$')
		{
			snprintf(temp, LENGTH, "%d", getpid());
			strcat(cmd, temp);
			a += 2;
		}
		else if (cmd[a] == '$' && cmd[a + 1] == '{')
		{
			a += 2;

			char var_name[VARIABLE_NAME];
			int k = 0;

			while (cmd[a] != '\0' && cmd[a] != '}')
			{
				var_name[k++] = cmd[a++];
			}
			var_name[k] = '\0';

			int found = 0;

			for (int idx = 0; idx < num_variables; ++idx)
			{
				if (strcmp(variables[idx], var_name) == 0)
				{
					strcat(cmd, variables[idx]);
					found = 1;
					break;
				}
			}
			if (!found)
			{
				printf("Variable '%s' not found\n", var_name);
			}
			a++;
		}
		else
		{
			cmd[b++] = cmd[a++];
		}
	}
	cmd[b] = '\0';
}

void file_cmd(const char *filename)
{
	FILE *files = fopen(filename, "r");
	if (files == NULL)
	{
		perror("Error while opening file");
		exit(EXIT_FAILURE);
	}
	char line[FILE_LINE_LENGTH];

	while (fgets(line, sizeof(line), files) != NULL)
	{
		line[strcspn(line, "\n")] = '\0';
		handle_variables(line);
		system(line);
		fclose(files);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s [filenames]\n", argv[0]);
		return EXIT_FAILURE;
	}
	file_cmd(argv[1]);
	return 0;
}

