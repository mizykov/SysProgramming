#include "stack.h"

Stack *initStack()
{
    HeadCanary *first = malloc(sizeof(HeadCanary));
    Stack *nill = malloc(sizeof(Stack));
    HeadCanary *last = malloc(sizeof(HeadCanary));

    first->stack = nill;
    first->value = DED;
    nill->after = last;
    nill->before = first;
    last->stack = nill;
    last->value = DED;

    return nill;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        return 0;
    }
    else
    {
        StackNode *cur = stack->top;
        stack->top = cur->next;
        cur->next = NULL;
        free(cur);
    }
    return 1;
}

int push(Stack *stack, int value)
{
    StackNode *newel = malloc(sizeof(StackNode));

    if (newel == NULL)
        return 0;

    newel->value = value;
    newel->next = stack->top;
    stack->top = newel;

    return 1;
}

int isEmpty(Stack *stack)
{
    if (stack->top == NULL)
        return 1;
    return 0;
}

void printStack(Stack *stack)
{
    StackNode *cur = stack->top;
    while (cur != NULL)
    {
        printf("%d ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}
