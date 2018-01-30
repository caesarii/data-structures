#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Tree.h"

struct NodeStruct {
    Node *firstChild;
};

struct TreeStruct {
    type element;
    Node *firstChild;
    Node *nextSibling;
};

Tree *
TreeCreate(List *list) {
    Tree *tree = malloc(sizeof(Tree));
    tree->firstChild = NULL;

    int length = list->length;
    for(int i = 0; i < length; i++) {
        Node n = malloc(sizeof(Node));
        n->element = ListElementAtIndex(list, i);
        n->nextSibling = NULL;
        n->firstChild =
    }
}
