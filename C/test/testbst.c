#include <stdio.h>
#include "../BinarySearchTree.h"


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
    BSTLog(tree);
}

void testBST(void) {
    testBSTInsert();

}
