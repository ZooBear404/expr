#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "expr.h"
#include "log.h"


int is_number(char *str, int *number, int *error) {
    int i;

    i = 0;
    while(str[i] != '\0') {
        if (!isdigit(str[i])) {
            return 0;
        }
        i++;
    }

    *number = atoi(str);

    return 1;
}

int is_operator(char *str, char *op, int *error) {
    if (strcmp(str, "+\0") == 0) {
        *op = '+';
        return 1;
    } else if (strcmp(str, "-\0") == 0) {
        *op = '-';
        return 1;
    } else if (strcmp(str, "*\0") == 0) {
        *op = '*';
        return 1;
    } else if (strcmp(str, "/\0") == 0) {
        *op = '/';
        return 1;
    }

    if (isalpha(str)) {
        *error = 1;
    }

    return 0;
}

void test_is_number_and_is_operator() {
    int error;

    Log(stdout, UPDATE, "testing", "testing the is_number and is_operator functions");
    printf("is_number\n");


    int number;
    char *str = "12343\0";
    int result = is_number(str, &number, &error);
    printf("%s %s a number\n", str, (result) ? "is" : "is not");
    printf("%d\n", number);

    if (error) {
        printf("an error occurred with is_number\n");
        error = 0;
        return;
    }

    printf("is_operator\n");

    char op;
    char *string = "+\0";
    int result_op = is_operator(string, &op, &error);
    printf("%s %s is an operator\n", string, (result_op) ? "is" : "is not");
    printf("%c\n", op);
}
