#include "shell.h"

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
