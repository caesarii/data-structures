#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "BinarySearchTree.h"
#include "utils.h"


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
        printf("¿ÕÊ÷ \n");
    } else {

        type e = tree->element;
        if(element < tree->element) {
            printf("left \n");
            tree->leftChild = BSTInsertIterative(tree->leftChild, element);
        } else if(element > tree->element) {
            printf("right %d \n", tree->rightChild == NULL);
            tree->rightChild = BSTInsertIterative(tree->rightChild, element);
        } else {
            printf("element is in the tree already \n");
        }
    }
    return tree;

}

void
preorderTraversal(Node *tree, int n) {
    if(tree != NULL) {
        formattedLog(tree->element, n);
        preorderTraversal(tree->leftChild, n + 1);
        preorderTraversal(tree->rightChild, n + 1);
    }
}

void
BSTLog(Tree *tree) {
    preorderTraversal(tree->root, 0);
}


