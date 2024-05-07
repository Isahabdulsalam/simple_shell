#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    char line[MAX_LINE_LENGTH];
    while (1) {
        print_prompt();
        if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
            printf("\n");
            break;
        }
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, "exit") == 0) {
            break;
        } else if (strcmp(line, "env") == 0) {
            extern char **environ;
            char **env = environ;
            while (*env != NULL) {
                printf("%s\n", *env);
                env++;
            }
        } else {
            if (execute_command(line) == -1) {
                printf("%s: command not found\n", line);
            }
        }
    }
    return 0;
}

void print_prompt(void) {
    printf("#cisfun$ ");
}

int execute_command(char *line) {
    pid_t pid;
    int status;
    
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        if (execlp(line, line, NULL) == -1) {
            perror("execlp");
            return -1;
        }
    } else {
        waitpid(pid, &status, 0);
    }
    return 0;
}

