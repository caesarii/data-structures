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
    tree->root = BSTInsertIterative(tree->root, element);

}

Node *
BSTInsertIterative(Node *tree, type element) {
    if(tree == NULL) {
        Node *n = malloc(sizeof(Node));
        n->element = element;
        n->leftChild = NULL; // malloc(sizeof(Node));
        n->rightChild = NULL; //malloc(sizeof(Node));
        tree = n;
        printf("null tree \n");
    } else {

        type e = tree->element;

        printf("%d \n", e);


        if(element < tree->element) {
            printf("left");
            tree->leftChild = BSTInsertIterative(tree->leftChild, element);
        } else if(element > tree->element) {
            printf("right %d \n", tree->rightChild == NULL);
            tree->rightChild = BSTInsertIterative(tree->rightChild, element);
        } else {
            printf("element is in the tree already");
        }
    }
    return tree;

}

void
BSTLog(Tree *tree) {
    printf("element: %d \n", tree->root->element);
    printf("element: %d \n", tree->root->rightChild->element);
    printf("element: %d \n", tree->root->leftChild->element);
}

