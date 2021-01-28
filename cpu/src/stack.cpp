#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "stack.h"

my_stack *Stack(int stackSize)
{
    my_stack *cur_stack = (my_stack *)calloc(1, sizeof(my_stack));

    if (cur_stack == NULL)
    {
        return NULL;
    }

    cur_stack->stackSize = stackSize;
    cur_stack->objects = (double *)calloc(stackSize, sizeof(*cur_stack->objects));

    if (cur_stack->objects == NULL)
    {
        return NULL;
    }

    cur_stack->head = -1;

    return cur_stack;
}

int desStack(my_stack *Stack)
{
    free(Stack->objects);

    Stack->objects = NULL;
    free(Stack);

    return 0;
}

int isEmpty(my_stack *Stack)
{
    if (Stack->head == -1)
    {
        return 1;
    }

    return 0;
}

int isFull(my_stack *Stack)
{
    if ((Stack->head) == (Stack->stackSize - 1))
    {
        return 1;
    }

    return 0;
}

double pop(my_stack *Stack)
{
    if (isEmpty(Stack) == -1)
        return -1;

    (Stack->head)--;

    return Stack->objects[(Stack->head) + 1];
}

int push(my_stack *Stack, double objects)
{
    if (isFull(Stack) == -1)
        return -1;

    ++(Stack->head);

    Stack->objects[Stack->head] = objects;
    
    return 0;
}
