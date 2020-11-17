#include <stdio.h>
#include "stack.h"

void testCreateStack() {
        Stack *stack = initStack(0);

        pop(stack);

        int stackIsEmpty = isEmpty(stack);
        if (stackIsEmpty == 1) {
            printf("TEST PASSED\n");
        }
        else {
            printf("TEST FAILED\n");
        }
}

void testPushToStack() {
        Stack *stack = initStack(0);

        push(stack, 10);
        push(stack, 20);
        push(stack, 30);

        int stackIsEmpty = isEmpty(stack);
        if (stackIsEmpty == 0) {
            printf("TEST PASSED\n");
        }
        else {
            printf("TEST FAILED\n");
        }
}

void testPopFromStack() {
        Stack *stack = initStack(0);

        push(stack, 10);
        push(stack, 20);
        push(stack, 30);

        pop(stack);
        pop(stack);
        pop(stack);

        int stackIsEmpty = isEmpty(stack);
        if (stackIsEmpty == 1) {
            printf("TEST PASSED\n");
        }
        else {
            printf("TEST FAILED\n");
        }
}

void testStackLogging() {
     Stack *stack = initStack(1);

    printf("Stack pointer:\n");
    printf("canaryHead 1 : %p\n", stack->before);
    printf("stack :        %p\n", stack);
    printf("canaryHead 2 : %p\n\n", stack->after);

    push(stack, 5);
    push(stack, 25);
    push(stack, 13);

    printStack(stack);

    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);

    printStack(stack);
}
