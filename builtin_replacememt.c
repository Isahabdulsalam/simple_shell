#include "shell.h"


#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10
#define MAX_ALIASES 50
#define MAX_ALIAS_LENGTH 50

void replace_variables(char *input)
{
	char pid[20];
	int last_command = 0;
	char exit_status[20];
	char *pos = strstr(input, "$$");
	sprintf(pid, "%d", getpid());

	if (pos != NULL) 
	{
		memmove(pos + strlen(pid), pos + 2, strlen(pos + 2) + 1);
		memcpy(pos, pid, strlen(pid));
	}
	sprintf(exit_status, "%d", last_command);
	pos = strstr(input, "$?");

	if (pos != NULL) {
		memmove(pos + strlen(exit_status), pos + 2, strlen(pos + 2) + 1);
		memcpy(pos, exit_status, strlen(exit_status));
	}
}

