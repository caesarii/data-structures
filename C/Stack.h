#ifndef __GuaStack_H__
#define __GuaStack_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "List.h"

struct StackStruct;
typedef struct StackStruct Stack;


Stack *
StackCreate(void);

void
StackLog(Stack *stack);

int
StackLength(Stack *stack);

void
StackPush(Stack *stack, type element);

int
StackPop(Stack *stack);

bool
StackIsEmpty(Stack *stack);

void
StackClear(Stack *stack);

void
StackRemove(Stack *stack);

#endif // GUASTACK_H_INCLUDED
