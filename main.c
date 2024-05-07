#include "shell.h"

void print_prompt(void) {
    printf("simple_shell$ ");
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
