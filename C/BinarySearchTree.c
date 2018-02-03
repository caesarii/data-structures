#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BinarySearchTree.h"


struct NodeStruct {
    type element;
    Node *leftChild;
    Node *rightChild;
};

struct TreeStruct {
    Node *root;
};

Tree *
BSTCreate(void) {
    Tree *tree = malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;

}

void
BSTInsert(Tree * tree, type element) {
    tree->root = BSTInsertIterative(tree, element);

}

Node *
BSTInsertIterative(Node *tree, type element) {
    if(tree == NULL) {
        Node *n = malloc(sizeof(Node));
        n->element = element;
        n->leftChild = NULL;
        n->rightChild = NULL;
        tree = n;
        printf("null tree");
    } else {
        if(element < tree->element) {
            tree->leftChild = BSTInsertIterative(tree->leftChild, element);
        } else if(element > tree->element) {
            tree->rightChild = BSTInsertIterative(tree->rightChild, element);
        } else {
            printf("element is in the tree already");
        }
    }
    return tree;

}
