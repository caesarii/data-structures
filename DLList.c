#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "DLList.h"

struct NodeStruct {
    type element;
    Node *next;
    Node *prev;
};

struct ListStruct {
    int length;
    Node *next;
    Node *tail;
};


List *
DLListCreate(int *element, int numberOfElements) {
    // assert(numberOfElements >= 0);

    // 分配内存并初始化 list
    List *l = malloc(sizeof(List));
    l->next = NULL;
    l->length = numberOfElements;
    l->tail = NULL;

    // 初始化元素
    for(int i = numberOfElements - 1; i >=0; i--) {
        // 新建 node
        Node *n = malloc(sizeof(Node));
        n->element = element[i];
        n->next = l->next;
        n->prev = NULL;



        // 插入node
        l->next = n;

        if(i == numberOfElements -1) {
            // 插入第一个元素时指定 tail
            l->tail = n;
        } else {
            // 非第一个元素向前链接
            l->next->prev = n;
        }
    }

    return l;

};



void
DLListLog(List *list) {
    Node *l = list->next;
    while(l != NULL) {
        printf("%d ", l->element);
        l = l->next;
    }
    printf("\n");
};

int
DLListLength(List *list) {
    int len = list->length;
    return len;
};

bool
DLListContains(List *list, type element) {
    bool contained = false;
    Node *l = list->next;
    while(l != NULL) {
        if(l->element == element) {
            contained = true;
            break;
        }
        l = l->next;
    }
    return contained;
};


void
DLListAppend(List *list, type element) {
    // new node
    Node *n = malloc(sizeof(Node));
    n->element = element;
    n->next = NULL;
    n->prev = NULL;

    // append
    if(ListLength(list) == 0) {
        list->next = n;
    } else {
        list->tail->next = n;
        n->prev = list->tail;
    }

    // update head info
    list->tail = n;
    list->length ++;
};

void
DLListPrepend(List *list, type element){
    Node *n = malloc(sizeof(Node));
    n->element = element;
    n->next = list->next;
    n->prev = NULL;

    if(list->next != NULL) {
        (list->next)->prev = n;
    }
    list->next = n;

    list->length ++;
};

type
DLListShift(List *list) {
    list->length --;
    Node *first = list->next;
    type e ;
    if(first == NULL) {
        return -1;
    } else {
        e = first->element;
    }
    list->next = list->next->next;
    list->next->prev = NULL;

    free(first);
    return e;
};

int
DLListIndexOfElement(List *list, type element) {
    int index = 0;
    Node *l = list->next;
    while(l != NULL) {
        if((*l).element == element) {
            return index;
        }
        l = l->next;
        index++;
    }
    return -1;
};

void
DLListInsertElementAtIndex(List *list, type element, int index) {
    if(index == 0) {
        ListPrepend(list, element);
        return;
    }

    list->length ++;
    int i = 0;
    index--;

    Node *n = malloc(sizeof(List));
    n->element = element;

    Node *l = list->next;

    while(l != NULL) {
        if(i == index) {
            n->next = l->next;
            l->next->prev = n;
            l->next = n;
        }

        l = l->next;
        i++;
    }

};

void
DLListChangeElementAtIndex(List *list, int element, int index) {
    int i = 0;
    Node *l = list->next;
    while(l != NULL) {
        if(i == index) {
            l->element = element;
        }

        l = l->next;
        i++;
    }
}

int
DLListElementAtIndex(List *list, int index) {

    int e;
    int i = 0;

    Node *l = list->next;

    while(l != NULL) {

        // printf("i,index %i %i \n", i, index);
        if(i == index) {
            e = l->element;
            break;
        }

        l = l->next;
        i++;
    }
    return e;
};


