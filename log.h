
#ifndef LOG
#define LOG

#include <stdio.h>

enum Log_Types {ERROR, EXCEPTION, UPDATE};

void Log(FILE *stream, enum Log_Types type, char *title, char *description, ...);

#endif
