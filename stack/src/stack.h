#include <stdlib.h>
#include <stdio.h>

#define LOG_FUN printf("*******************************\nExecute %s()\n", __FUNCTION__);
#define LOG_DUMP(p1, p2, p3) stackStatus(p1, p2, p3);

static const unsigned long long DED = 0xDEADBEEFBADF00DUL;

typedef struct StackNode
{
    int isNILL;
    int value;
    struct StackNode *next;
} StackNode;

typedef struct Stack
{
    int logging;
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

Stack *initStack(int log_value);

void insertCanariesToBody(Stack *stack, int log_value);

int pop(Stack *stack);

int push(Stack *stack, int value);

int isEmpty(Stack *stack);

void printStack();

void stackStatus(BodyCanary *can1, StackNode *top, BodyCanary *can2);
