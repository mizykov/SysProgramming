#include <stdio.h>

#include "stack.h"

int main()
{
    Stack *stack = initStack();

    printf("Stack pointer:\n");
    printf("canaryHead 1 : %p\n", stack->before);
    printf("stack :        %p\n", stack);
    printf("canaryHead 2 : %p\n\n", stack->after);

    push(stack, 5);
    push(stack, 25);
    push(stack, 13);

    return 0;
}