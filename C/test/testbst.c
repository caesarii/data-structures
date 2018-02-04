#include <stdio.h>
#include "../BinarySearchTree.h"


void testBSTInsert(void) {
    Tree *tree = BSTCreate();
    BSTInsert(tree, 5);
    BSTInsert(tree, 6);
    BSTInsert(tree, 4);
    BSTLog(tree);
}

void testBST(void) {
    testBSTInsert();

}
