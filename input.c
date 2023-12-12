#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

static char *last_input;

/**
 * get_input - Read a line of input from the user.
 *
 * Return: Pointer to a buffer containing the user's input.
 */
char *get_input(void)
{
    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t characters;

    
    printf("Shell $ ");

    
    characters = getline(&buffer, &bufsize, stdin);

    
    if (characters == -1)
    {
        perror("getline");
        exit(EXIT_FAILURE);
    }

   
    if (buffer[characters - 1] == '\n')
    {
        buffer[characters - 1] = '\0';
    }

   
    last_input = buffer;

    return (buffer);
}

int main(void)
{
    char *input;

    input = get_input();


    printf("You entered: %s\n", input);

    free(input);

    return (0);
}
