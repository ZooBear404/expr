#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "log.h"

struct Stack *initialize_stack(int *error) {
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack) + MAXLINE * sizeof(int));
    if (stack == NULL) {
        *error = ERROR_VALUE;
    }
    stack->top = -1;

    #if DEBUG
    int stack_size = sizeof(*stack);
    Log(stdout, UPDATE, "stack", "%d bytes allocated for stack", stack_size);
    #endif

    return stack;
}

void push(struct Stack *stack, int value, int *error) {
    if (stack == NULL) {
        Log(stdout, ERROR, "stack", "stack pointer null in push()");
        *error = ERROR_VALUE;
        return;
    }
    if (stack->top == MAXLINE) {
        Log(stdout, ERROR, "stack", "stack overflow for %d", value);
        *error = ERROR_VALUE;
        return;
    }

    stack->array[++stack->top] = value;
    #if DEBUG
    Log(stdout, UPDATE, "stack", "%d pushed in to stack->array[%d]", value, stack->top);
    #endif

}

int pop(struct Stack *stack, int *error) {
    if (stack == NULL) {
        Log(stdout, ERROR, "stack", "stack pointer null in pop()");
        *error = ERROR_VALUE;
        return -1;
    }

    if (stack->top < 0) {
        Log(stdout, ERROR, "stack", "stack underflow");
        *error = ERROR_VALUE;
        return -1;
    }

    int value = stack->array[stack->top--];
    #if DEBUG
    Log(stdout, UPDATE, "stack", "%d popped from stack->array[%d]", value, stack->top+1);
    #endif

    return value;
}

void print_stack(struct Stack *stack) {
    if (stack == NULL) {
        Log(stdout, ERROR, "stack", "stack pointer null in print_stack()");
        return;
    }

    int i;

    i = -1;
    while (i++ < stack->top) {
        printf("%d ", stack->array[i]);
    }

    printf("\n");
}
