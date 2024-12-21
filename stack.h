
#ifndef STACK
#define STACK

#define MAXLINE 1000
#define ERROR_VALUE 1

struct Stack {
    int array[MAXLINE];
    int top;
};

struct Stack *initialize_stack(int *error);
void push(struct Stack *stack, int value, int *error);
int pop(struct Stack *stack, int *error);




#endif
