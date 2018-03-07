#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "BinarySearchTree.h"
#include "utils.h"


struct TreeStruct {
    type element;
    Tree *leftChild;
    Tree *rightChild;
};


Tree *
BSTCreate(void) {
    Tree *tree = malloc(sizeof(Tree));
    tree->element = 0;
    tree->leftChild = NULL;
    tree->rightChild = NULL;
    return tree;

}

Tree *
BSTInsert(Tree * tree, type element) {
    if (tree == NULL) {
        Tree *n = malloc(sizeof(Tree));
        n->element = element;
        n->leftChild = NULL;
        n->rightChild = NULL;
        tree = n;
    } else if(tree->element == NULL) {
        tree->element = element;
        printf("first element \n");
    } else {
        if(element < tree->element) {
            tree->leftChild = BSTInsert(tree->leftChild, element);
        } else if(element > tree->element) {
            tree->rightChild = BSTInsert(tree->rightChild, element);
        } else {
            printf("element is in the tree already \n");
        }
    }
    return tree;
}

type
BSTFind(Tree *tree, type element) {
    if(tree == NULL) {
        return 0;
    } else if(element < tree->element) {
        return BSTFind(tree->leftChild, element);
    } else if(element > tree->element) {
        return BSTFind(tree->rightChild, element);
    } else {
        return tree->element;
    }
}

type
BSTFindMin(Tree *tree) {
    if(tree == NULL) {
        return 0;
    } else {
        if(tree->leftChild == NULL) {
            return tree->element;
        } else {
            return BSTFindMin(tree->leftChild);
        }
    }
}

type
BSTFindMax(Tree *tree) {
    if(tree == NULL) {
        return 0;
    } else {
        if(tree->rightChild == NULL) {
            return tree->element;
        } else {
            return BSTFindMax(tree->rightChild);
        }
    }
}

void
preorderTraversal(Tree *tree, int n) {
    if(tree != NULL) {
        formattedLog(tree->element, n);
        preorderTraversal(tree->leftChild, n + 1);
        preorderTraversal(tree->rightChild, n + 1);
    }
}

void
BSTLog(Tree *tree) {
    preorderTraversal(tree, 0);
}


