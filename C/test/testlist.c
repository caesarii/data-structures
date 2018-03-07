#include <stdio.h>
#include "../List.h"

void
testListLength() {
    type a1[] = {1, 2, 3};
    int n1 = 3;
    List *l1 = ListCreate(a1, n1);
    ensure(ListLength(l1) == n1, "test list length 1");

    type a2[] = {};
    int n2 = 0;
    List *l2 = ListCreate(a2, n2);
    ensure(ListLength(l2) == n2, "test list length 2");

    type a3[] = {1};

    int n3 = 1;
    List *l3 = ListCreate(a3, n3);
    ensure(ListLength(l3) == n3, "test list length 3");

    printf("length\n");
}

void
testListContains() {
//    type a1[] = {1, 2, 3};
//    int n1 = 3;
//    List *l1 = ListCreate(a1, n1);
//    ensure(ListContains(l1, 1) == true, "test list contains 1");
//
//    type a2[] = {};
//    int n2 = 0;
//    List *l2 = ListCreate(a2, n2);
//    ensure(ListContains(l2, 1) == false, "test list contains 2");
//
//    type a3[] = {1, 2, 3};
//    int n3 = 3;
//    List *l3 = ListCreate(a3, n3);
//    ensure(ListContains(l3, 4) == false, "test list contains 3");
//
//    printf("contains\n");
}

void
testListAppend() {
    type a1[] = {1, 2, 3};
    int n1 = 3;
    List *l1 = ListCreate(a1, n1);
//    GuaListLog(l1);
    ListAppend(l1, 4);
    ensure(ListLength(l1) == 4, "test list append 1");
//    GuaListLog(l1);

    type a2[] = {};
    int n2 = 0;
    List *l2 = ListCreate(a2, n2);
//    GuaListLog(l2);
    ListAppend(l2, 0);
    ensure(ListLength(l2) == 1, "test list contains 2");
//    GuaListLog(l2);

    type a3[] = {3};
    int n3 = 1;
    List *l3 = ListCreate(a3, n3);
    ListAppend(l3, 3);
    ensure(ListLength(l3) == 2, "test list contains 3");

    printf("append\n");
}

void
testListPrepend() {
    type a1[] = {1, 2, 3};
    int n1 = 3;
    List *l1 = ListCreate(a1, n1);
    // GuaListLog(l1);
    ListPrepend(l1, 0);
    ensure(ListLength(l1) == 4, "test list prepend 1");
    // GuaListLog(l1);

    type a2[] = {};
    int n2 = 0;
    List *l2 = ListCreate(a2, n2);
    ListPrepend(l2, 0);
    ensure(ListLength(l2) == 1, "test list prepend 2");

    type a3[] = {3};
    int n3 = 1;
    List *l3 = ListCreate(a3, n3);
    ListAppend(l3, 3);
    ensure(ListLength(l3) == 2, "test list prepend 3");

    printf("prepend\n");
}

void
testListIndexOfElement() {
//    type a1[] = {1, 2, 3};
//    int n1 = 3;
//    List *l1 = ListCreate(a1, n1);
//    ensure(ListIndexOfElement(l1, 1) == 0, "test list indexOf 1");

//    type a2[] = {};
//    int n2 = 0;
//    GuaList *l2 = GuaListCreate(a2, n2);
//    ensure(GuaListIndexOfElement(l2, 1) == -1, "test list indexOf 2");
//
//    type a3[] = {3};
//    int n3 = 1;
//    GuaList *l3 = GuaListCreate(a3, n3);
//    ensure(GuaListIndexOfElement(l3, 1) == -1, "test list indexOf 3");

    printf("indexOf\n");
}

void
testListInsertElementAtIndex() {
    type a1[] = {1, 2, 3};
    int n1 = 3;
    List *l1 = ListCreate(a1, n1);
    ListInsertElementAtIndex(l1, 11, 1);
    ensure(ListLength(l1) == 4, "test list insert 1");
    ListLog(l1);

    type a2[] = {};
    int n2 = 0;
    List *l2 = ListCreate(a2, n2);
    ListInsertElementAtIndex(l2, 11, 0);
    ensure(ListLength(l2) == 1, "test list insert 2");
    ListLog(l2);

    type a3[] = {3};
    int n3 = 1;
    List *l3 = ListCreate(a3, n3);
    ListInsertElementAtIndex(l3, 4, 0);
    ensure(ListLength(l3) == 2, "test list insert 3");
    ListLog(l3);

    printf("insert");
}

void
testListShift() {
    type a1[] = {1, 2, 3};
    int n1 = 3;
    List *l1 = ListCreate(a1, n1);
    printf("shift %i \n", ListShift(l1));

}

void
testListElementAtIndex() {
    type a1[] = {0, 1, 2, 3};
    int n1 = 4;
    List *l1 = ListCreate(a1, n1);
    printf("element at index %i \n", ListElementAtIndex(l1, 3));
}

void
testList() {
    testListLength();
    testListContains();
    testListAppend();
    testListPrepend();
    testListIndexOfElement();
    testListInsertElementAtIndex();
    testListShift();
    testListElementAtIndex();
}
