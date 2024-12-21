#include <stdio.h>
#include <stdarg.h>

#include "log.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void Log(FILE *stream, enum Log_Types type, char *title, char *description, ...) {
    switch (type) {
        case ERROR:
            fprintf(stream, ANSI_COLOR_RED);
            break;
        case EXCEPTION:
            fprintf(stream, ANSI_COLOR_MAGENTA);
            break;
        case UPDATE:
            fprintf(stream, ANSI_COLOR_GREEN);
            break;
    }

    fprintf(stream, "%s: ", title);

    va_list args;
    va_start(args, description);

    while (*description != '\0') {
        if (*description == '%') {
            description++;
            if (*description == 'd') {
                int arg = va_arg(args, int);
                printf("%d", arg);
            } else if (*description == 's') {
                char *arg = va_arg(args, char *);
                printf("%s", arg);
            } else if (*description == 'f') {
                double arg = va_arg(args, double);
                printf("%f", arg);
            }
            description++;
        } else {
            printf("%c", *description);
            description++;
        }
    }

    va_end(args);

    fprintf(stream, "\n");
    fprintf(stream, ANSI_COLOR_RESET);
}
