#include <stdlib.h>
#include <stdio.h>

#define LOG_TRACE printf("Entering %s\n", __FUNCTION__);

static const unsigned long long DED = 0xDEADBEEFBADF00DUL;

typedef struct StackNode
{
    int value;
    struct StackNode* next;
} StackNode;

typedef struct Stack
{
    struct HeadCanary* before;
    struct HeadCanary* after;
    struct StackNode* top;
} Stack;

typedef struct HeadCanary
{
    unsigned long long value;
    struct Stack* stack;
} HeadCanary;

typedef struct BodyCanary
{
    unsigned long long value;
    struct StackNode* node;
} BodyCanary;

Stack* initStack();

int pop(Stack *stack);

int push(Stack *stack, int value);

int isEmpty(Stack * stack);

void printStack();
