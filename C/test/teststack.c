#include <stdio.h>
#include "../Stack.h"

void
testGuaStackPush() {
    // create
    Stack *s = StackCreate();
    ensure(StackLength(s) == 0, "test stack length 1 \n");
    printf("s len %i \n", StackLength(s));

    // push 0
    StackPush(s, 0);
    ensure(StackLength(s) == 1, "test stack length 2 \n");
    printf("s len %i \n", StackLength(s));

    // push 1
    StackPush(s, 1);
    ensure(StackLength(s) == 2, "test stack length 3 \n");
    printf("s len %i \n", StackLength(s));


    // push 2
    StackPush(s, 2);
    StackLog(s);
    printf("stack push");
}

void
testGuaStackPop() {

    // create
    Stack *s = StackCreate();
    ensure(StackLength(s) == 0, "test stack length 1 \n");
    printf("s len %i \n", StackLength(s));

    // push 0
    StackPush(s, 0);
    ensure(StackLength(s) == 1, "test stack length 2 \n");
    printf("s len %i \n", StackLength(s));

    // push 1
    StackPush(s, 1);
    ensure(StackLength(s) == 2, "test stack length 3 \n");
    printf("s len %i \n", StackLength(s));


    // push 2
    StackPush(s, 2);
    StackLog(s);

    // pop 2
    ensure(StackPop(s) == 2, "test stack pop 1 \n");
    StackLog(s);

    // pop1
    ensure(StackPop(s) == 1, "test stack pop 2 \n");
    StackLog(s);

    // pop 0
    ensure(StackPop(s) == 0, "test stack pop 3 \n");
    StackLog(s);

    // pop nothing
    ensure(StackPop(s) == -1, "test stack pop 3 \n");
    StackLog(s);

    printf("stack pop \n");
}

void
testStackIsEmpty() {
    Stack *s = StackCreate();
    ensure(StackIsEmpty(s) == true, "test stack isEmpty 1 \n");
    StackPush(s, 0);
    ensure(StackIsEmpty(s) == false, "test stack isEmpty 2 \n");
    printf("stack isEmpty");
}

void testStackClear() {
    Stack *s = StackCreate();
    StackPush(s, 0);
    StackPush(s, 0);
    StackPush(s, 0);
    StackClear(s);
    ensure(StackLength(s) == 0, "stack clear 1");
    printf("stack clear");
}

void testStackRemove() {
    Stack *s = StackCreate();
    StackPush(s, 0);
    StackPush(s, 0);
    StackPush(s, 0);
    StackRemove(s);

    // ensure(GuaStackLength(s) == 0, 'stack clear 1');
    printf("stack Remove");
}

void
testStack() {
    testGuaStackPush();
    testGuaStackPop();
    testStackIsEmpty();
    testStackClear();
    testStackRemove();
}
