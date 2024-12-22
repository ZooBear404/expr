#include <stdio.h>

#include "log.h"
#include "stack.h"
#include "expr.h"

int main(int argc, char **argv) {

  int i, error;
  long result;
  struct Stack *stack = initialize_stack(&error);

  i = 0;
  while (++i < argc) {
    int number;
    char operator;

    if (is_number(argv[i], &number, &error)) {
      push(stack, number, &error);
      if (error) {
        return 1;
      }
    } else if (is_operator(argv[i], &operator, &error)) {
        int number1 = pop(stack, &error);
        if (error) {
          return 1;
        }
	  
        int number2 = pop(stack, &error);
        if (error) {
          return 1;
        }

        switch(operator) {
          case '+':
            result = number1 + number2;
            break;
          case '-':
            result = number1 - number2;
            break;
          case '*':
            result = number1 * number2;
            break;
          case '/':
            result = number1 / number2;
            break;
          default:
            Log(stdout, ERROR, "operator", "invalid operator");
        }

        push(stack, result, &error);
        if (error) {
          return 1;
        }
      }
      }

    int final_result = pop(stack, &error);
    if (error) {
      return 1;
      }

      printf("result: %d\n", final_result);
  


  return 0;
}
