#include "stack.h"

Stack *initStack(int log_value)
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

    insertCanariesToBody(nill, log_value);

    if (log_value == 1) {
        LOG_FUN
        LOG_DUMP(nill->bo, nill->top, nill->dy);
    }

    return nill;
}

void insertCanariesToBody(Stack *stack, int log_value)
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

    stack->bo = first;
    stack->dy = second;

    stack->logging = log_value;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        if (stack->logging == 1) {
            printf("Stack is empty!\n");
        }
        return 0;
    }
    BodyCanary *canary = stack->dy;
    free(canary);

    StackNode *cur = stack->top->next;
    free(stack->top);
    stack->top = cur;

    BodyCanary *movingCanary = malloc(sizeof(BodyCanary));
    movingCanary->value = DED;
    movingCanary->node = cur;
    stack->dy = movingCanary;

    if (stack->logging == 1) {
        LOG_FUN
        LOG_DUMP(stack->bo, stack->top, stack->dy);
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

    if (stack->logging == 1) {
        LOG_FUN
        LOG_DUMP(stack->bo, stack->top, stack->dy);
    }

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
    if (isEmpty(stack))
    {
        printf("Stack is empty!\n");
    }
    else 
    {
        StackNode *cur = stack->top;
        while (cur->isNILL != 1)
        {
            printf("%d ", cur->value);
            cur = cur->next;
        }
        printf("\n");
    }
}

void stackStatus(BodyCanary *can1, StackNode *top, BodyCanary *can2)
{
    printf("DATA STACK STATUS:\n");
    printf("canaryBody 1 : %p\n", can1);
    printf("top :          %p\n", top);
    printf("canaryBody 2 : %p\n", can2);
    printf("*******************************\n\n");
}
