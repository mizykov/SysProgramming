#include <stdlib.h>
#include <stdio.h>


#define LOG_FUN printf("Execute %s()\n", __FUNCTION__);
#define LOG_DUMP(p1, p2, p3) stackStatus(p1, p2, p3);

static const unsigned long long DED = 0xDEADBEEFBADF00DUL;

typedef struct StackNode
{
    int isNILL;
    int value;
    struct StackNode *next;
    // usign for canaries.
    struct StackNode *prev;
} StackNode;

typedef struct Stack
{
    struct BodyCanary *bo;
    struct BodyCanary *dy;
    struct HeadCanary *before;
    struct HeadCanary *after;
    struct StackNode *top;
} Stack;

typedef struct HeadCanary
{
    unsigned long long value;
    struct Stack *stack;
} HeadCanary;

typedef struct BodyCanary
{
    unsigned long long value;
    struct StackNode *node;
} BodyCanary;

Stack *initStack();

int pop(Stack *stack);

int push(Stack *stack, int value);

int isEmpty(Stack *stack);

void printStack();

void stackStatus(BodyCanary *can1, StackNode *top, BodyCanary *can2);
