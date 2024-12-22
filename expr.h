
#ifndef EXPR
#define EXPR

int is_number(char *str,  int *number, int *error);
int is_operator(char *str, char *op, int *error);
void test_is_number_and_is_operator();

#endif
