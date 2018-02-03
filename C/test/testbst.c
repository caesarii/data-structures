#include <stdio.h>
#include "../BinarySearchTree.h"


void testBSTInsert(void) {
    Tree *tree = BSTCreate();
    BSTInsert(tree, 5);
}

void testBST(void) {
    testBSTInsert();

}
