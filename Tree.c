#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Tree.h"


struct NodeStruct {
    int length;
    Node *firstChild;
};

struct TreeStruct {
    Node *firstChild;
    Node *nextSibling;
};
