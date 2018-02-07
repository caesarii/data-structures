#include <stdio.h>
#include <stdlib.h>
#include "./test/testlist.c"
#include "./test/testhashtable.c"
#include "./test/testqueue.c"
#include "./test/teststack.c"
#include "./test/testdllist.c"
#include "./test/testtree.c"
#include "./test/testbst.c"
int main()
{
    testList();
    testQueue();
    testStack();
    testHashTable();

    testDLList();

    testBST();

    printf("\nHello world!\n");
    return 0;
}
