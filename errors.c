#include "shell.h"
#include <stdio.h>
#include <unistd.h>  

#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

static int write_to_fd(char c, int fd, char *buf, int *i) {
    if (c == BUF_FLUSH || *i >= WRITE_BUF_SIZE) {
        write(fd, buf, *i);
        *i = 0;
    }

    if (c != BUF_FLUSH) {
        buf[(*i)++] = c;
    }

    return 1;
}

void _eputs(char *str) {
    static char buf[WRITE_BUF_SIZE];
    static int i;

    if (!str) {
        return;
    }

    i = 0;
    while (str[i] != '\0') {
        write_to_fd(str[i], 2, buf, &i);
        i++;
    }
    write_to_fd('\n', 2, buf, &i);
}

int _eputchar(char c) {
    static char buf[WRITE_BUF_SIZE];
    static int i;

    return write_to_fd(c, 2, buf, &i);
}

int _putfd(char c, int fd) {
    static char buf[WRITE_BUF_SIZE];
    static int i;

    return write_to_fd(c, fd, buf, &i);
}

int _putsfd(char *str, int fd) {
    if (!str) {
        return 0;
    }

    int count = 0;
    while (*str) {
        count += _putfd(*str++, fd);
    }
    return count;
}

