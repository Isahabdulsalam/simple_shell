#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_LINE_LENGTH 1024

int main(void);
void print_prompt(void);
int execute_command(char *line);
void replace_variables(char *input);
void exe_com(char *com);
#endif
