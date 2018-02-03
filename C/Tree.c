#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Tree.h"

typedef int type;

struct NodeStruct {
    type element;
    Node *firstChild;
    Node *nextSiblings;
};

struct TreeStruct {
    Node *root;
};

Tree *
TreeCreate(void) {
    Tree *tree = malloc(sizeof(Tree));
    tree->root = NULL;

    return tree;
}


void
TreeInsert(Tree * tree, int *elements, int numberOfElements) {


    Node *parent = tree.root;
    for(int i = 0; i < numberOfElements; i++) {
        // ÐÂ½Úµã
        Node *n = malloc(sizeof(Node));
        n->element = elements[i];
        n->firstChild = NULL;
        n->nextSiblings = NULL;

       // todo


        list->next = n;
        if(i == numberOfElements - 1) {
            list->tail = n;
        }
    }



    return void;
}

