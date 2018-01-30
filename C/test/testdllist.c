#include <stdio.h>
#include "../DLList.h"

void
testDLListLength() {
    type a1[] = {1, 2, 3};
    int n1 = 3;
    List *l1 = DLListCreate(a1, n1);
    ensure(DLListLength(l1) == n1, "test DL list length 1");

    type a2[] = {};
    int n2 = 0;
    List *l2 = DLListCreate(a2, n2);
    ensure(DLListLength(l2) == n2, "test DL list length 2");

    type a3[] = {1};

    int n3 = 1;
    List *l3 = DLListCreate(a3, n3);
    ensure(DLListLength(l3) == n3, "test DL list length 3");

    printf("length\n");
}

void
testDLListContains() {
    type a1[] = {1, 2, 3};
    int n1 = 3;
    List *l1 = DLListCreate(a1, n1);
    ensure(DLListContains(l1, 1) == true, "test DL list contains 1");

    type a2[] = {};
    int n2 = 0;
    List *l2 = DLListCreate(a2, n2);
    ensure(DLListContains(l2, 1) == false, "test DL list contains 2");

    type a3[] = {1, 2, 3};
    int n3 = 3;
    List *l3 = DLListCreate(a3, n3);
    ensure(DLListContains(l3, 4) == false, "test DL list contains 3");

    printf("contains\n");
}

void
testDLListAppend() {
    type a1[] = {1, 2, 3};
    int n1 = 3;
    List *l1 = DLListCreate(a1, n1);
//    GuaListLog(l1);
    DLListAppend(l1, 4);
    ensure(DLListLength(l1) == 4, "test DL list append 1");
//    GuaListLog(l1);

    type a2[] = {};
    int n2 = 0;
    List *l2 = DLListCreate(a2, n2);
//    GuaListLog(l2);
    DLListAppend(l2, 0);
    ensure(DLListLength(l2) == 1, "test DL list contains 2");
//    GuaListLog(l2);

    type a3[] = {3};
    int n3 = 1;
    List *l3 = DLListCreate(a3, n3);
    DLListAppend(l3, 3);
    ensure(DLListLength(l3) == 2, "test DL list contains 3");

    printf("append\n");
}

void
testDLListPrepend() {
    type a1[] = {1, 2, 3};
    int n1 = 3;
    List *l1 = DLListCreate(a1, n1);
    // GuaListLog(l1);
    DLListPrepend(l1, 0);
    ensure(DLListLength(l1) == 4, "test DL list prepend 1");
    // GuaListLog(l1);

    type a2[] = {};
    int n2 = 0;
    List *l2 = DLListCreate(a2, n2);
    DLListPrepend(l2, 0);
    ensure(DLListLength(l2) == 1, "test DL list prepend 2");

    type a3[] = {3};
    int n3 = 1;
    List *l3 = DLListCreate(a3, n3);
    DLListAppend(l3, 3);
    ensure(DLListLength(l3) == 2, "test DL list prepend 3");

    printf("prepend\n");
}

void
testDLListIndexOfElement() {
    type a1[] = {1, 2, 3};
    int n1 = 3;
    List *l1 = DLListCreate(a1, n1);
    ensure(DLListIndexOfElement(l1, 1) == 0, "test DL list indexOf 1");

    type a2[] = {};
    int n2 = 0;
    List *l2 = DLListCreate(a2, n2);
    ensure(DLListIndexOfElement(l2, 1) == -1, "test DL list indexOf 2");

    type a3[] = {3};
    int n3 = 1;
    List *l3 = DLListCreate(a3, n3);
    ensure(DLListIndexOfElement(l3, 1) == -1, "test DL list indexOf 3");

    printf("indexOf\n");
}

void
testDLListInsertElementAtIndex() {
    type a1[] = {1, 2, 3};
    int n1 = 3;
    List *l1 = DLListCreate(a1, n1);
    DLListInsertElementAtIndex(l1, 11, 1);
    ensure(DLListLength(l1) == 4, "test DL list insert 1");
    DLListLog(l1);

    type a2[] = {};
    int n2 = 0;
    List *l2 = DLListCreate(a2, n2);
    DLListInsertElementAtIndex(l2, 11, 0);
    ensure(DLListLength(l2) == 1, "test DL list insert 2");
    DLListLog(l2);

    type a3[] = {3};
    int n3 = 1;
    List *l3 = DLListCreate(a3, n3);
    DLListInsertElementAtIndex(l3, 4, 0);
    ensure(DLListLength(l3) == 2, "test DL list insert 3");
    DLListLog(l3);

    printf("insert");
}

void
testDLListShift() {
    type a1[] = {1, 2, 3};
    int n1 = 3;
    List *l1 = DLListCreate(a1, n1);
    printf("shift %i \n", ListShift(l1));
}

void
testDLListElementAtIndex() {
    type a1[] = {0, 1, 2, 3};
    int n1 = 4;
    List *l1 = ListCreate(a1, n1);
    printf("element at index %i \n", ListElementAtIndex(l1, 3));
}

void
testDLList() {
    testDLListLength();
    testDLListContains();
    testDLListAppend();
    testDLListPrepend();
    testDLListIndexOfElement();
    testDLListInsertElementAtIndex();
    testDLListShift();
    testDLListElementAtIndex();
}
