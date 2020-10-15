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

    insertCanariesToBody(nill);

    LOG_FUN
    LOG_DUMP(nill->bo, nill->top, nill->dy);

    return nill;
}

void insertCanariesToBody(Stack *stack)
{
    BodyCanary *first = malloc(sizeof(BodyCanary));
    StackNode *node = malloc(sizeof(StackNode));
    BodyCanary *second = malloc(sizeof(BodyCanary));

    stack->top = node;
    stack->top->isNILL = 1;

    first->value = DED;
    first->node = stack->top;
    second->value = DED;
    second->node = stack->top;

    stack->top->next = first;
    stack->top->prev = second;
    stack->bo = first;
    stack->dy = second;
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
    // move canary after stack elements.
    BodyCanary *canary = stack->dy;
    free(canary);

    StackNode *newel = malloc(sizeof(StackNode));

    BodyCanary *movingCanary = malloc(sizeof(BodyCanary));
    movingCanary->value = DED;
    movingCanary->node = newel;

    if (newel == NULL)
        return 0;

    newel->value = value;
    newel->next = stack->top;
    newel->isNILL = 0;

    stack->top = newel;
    stack->dy = movingCanary;

    LOG_FUN
    LOG_DUMP(stack->bo, stack->top, stack->dy);

    return 1;
}

int isEmpty(Stack *stack)
{
    if (stack->top->isNILL == 1)
        return 1;
    return 0;
}

void printStack(Stack *stack)
{
    StackNode *cur = stack->top;
    while (cur->isNILL != 1)
    {
        printf("%d ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}

void stackStatus(BodyCanary *can1, StackNode *top, BodyCanary *can2)
{
    printf("DATA STACK STATUS:\n");
    printf("canaryBody 1 : %p\n", can1);
    printf("top :          %p\n", top);
    printf("canaryBody 2 : %p\n\n", can2);
}
