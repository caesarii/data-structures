#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

struct NodeStruct;
typedef struct NodeStruct Node;
struct TreeStruct;
typedef struct TreeStruct Tree;

typedef int type;

Tree *
TreeCreate(void);

void
TreeInsert(Tree *tree, char * node);

#endif // TREE_H_INCLUDED
