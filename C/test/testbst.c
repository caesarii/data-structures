#include <stdio.h>
#include "BinarySearchTree.h"


void testBSTInsert(void) {
    Tree *tree = BSTCreate();
    BSTInsert(tree, 5);
    BSTInsert(tree, 2);
    BSTInsert(tree, 8);
    BSTInsert(tree, 1);
    BSTInsert(tree, 4);
    BSTInsert(tree, 3);
    BSTInsert(tree, 7);
    BSTInsert(tree, 6);

    type e = BSTFind(tree, 6);
    printf("target: %d \n", e);

    type min = BSTFindMin(tree);
    printf("min: %d \n", min);

    type max = BSTFindMax(tree);
    printf("max: %d \n", max);

    BSTLog(tree);
}

void testBST(void) {
    testBSTInsert();
}
