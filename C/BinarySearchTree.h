#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

struct NodeStruct;
typedef struct NodeStruct Node;
struct TreeStruct;
typedef struct TreeStruct Tree;

typedef int type;

Tree *
BSTCreate(void);

void
BSTInsert(Tree * tree, type element);

Node *
BSTInsertIterative(Node *tree, type element);

#endif // BINARYSEARCHTREE_H_INCLUDED
