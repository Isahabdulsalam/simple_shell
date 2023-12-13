#include "shell.h"

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * get_line - Read input from the standard input.
 *
 * Return: The string entered by the user.
 */

char *get_line(void)
{
	char *buffer = NULL;
	size_t buf_size = 0;
	ssize_t buf_read;

	buf_read = getline(&buffer, &buf_size, stdin);

	if (buf_read == -1)
	{
	perror("getline");
	free(buffer);
	return (NULL);
	}

	if (buf_read > 0 && buffer[buf_read - 1] == '\n')
	{
		buffer[buf_read - 1] = '\0';
	}

	return (buffer);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_eputs("\n");
	_eputs("$ ");
	_eputchar(BUF_FLUSH);
}
