#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

struct TreeStruct;
typedef struct TreeStruct Tree;

typedef int type;

Tree *
BSTCreate(void);

Tree *
BSTInsert(Tree * tree, type element);

Tree *
BSTInsertIterative(Tree *tree, type element);

void
preorderTraversal(Tree *tree, int n);

type
BSTFind(Tree *tree, type element);

type
BSTFindMin(Tree *tree);

type
BSTFindMax(Tree *tree);

void
BSTLog(Tree *tree);

#endif // BINARYSEARCHTREE_H_INCLUDED
