#include <stdio.h>

#include "stack.h"

int main()
{
    Stack *stack = initStack();

    printf("stack 1:\n");
    printf("canary 1 : %p\n", stack->before);
    printf("stack :    %p\n", stack);
    printf("canary 2 : %p\n", stack->after);

    return 0;
}