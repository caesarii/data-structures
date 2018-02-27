
#include "Stack.h"

struct StackStruct {
    List *list;
};

Stack *
StackCreate(void) {
    Stack *s = malloc(sizeof(Stack));
    List *l = ListCreate(NULL, 0);
    s->list = l;
    return s;
}

void
StackLog(Stack *stack) {
    ListLog(stack->list);
}

int
StackLength(Stack *stack) {
     return ListLength(stack->list);
}


void StackPush(Stack *stack, type element){
    ListPrepend(stack->list, element);
};

int
StackPop(Stack *stack) {
    int deleted = ListShift(stack->list);
    return deleted;
}


bool
StackIsEmpty(Stack *stack) {
    return ListLength(stack->list) == 0;
//    if(ListLength(stack->list) == 0) {
//        return true;
//    } else {
//        return false;
//    }
}

void
StackClear(Stack *stack) {
    while(!StackIsEmpty(stack)) {
        StackPop(stack);
    }
}

void
StackRemove(Stack *stack){
    StackClear(stack);
    free(stack);
}

