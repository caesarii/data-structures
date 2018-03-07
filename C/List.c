#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "List.h"

// 结构的具体定义
struct NodeStruct {
    type element;
    Node *next;
};

struct ListStruct {
    int length;
    Node *next;
    Node *tail;
};


// 创建并返回一个 List
// element 是一个 int 数组
// numberOfElements 是数组的长度
// 在 C 语言中, 数组的长度信息要额外提供
List *
ListCreate(int *element, int numberOfElements) {
    // assert 是用于确保一定条件的断言
    assert(numberOfElements >= 0);

    // malloc 申请一块内存, 并初始化一下
    List *list = malloc(sizeof(List));
    list->next = NULL;
    list->length = numberOfElements;
    list->tail = NULL;


    // 循环插入初始化元素
    // prepend
    for(int i = numberOfElements - 1; i >= 0; i--) {
        Node *n = malloc(sizeof(Node));
        n->element = element[i];
        n->next = list->next;

        list->next = n;
        if(i == numberOfElements - 1) {
            list->tail = n;
        }
    }

    return list;
}

// 把一个 List 的数据打印出来
void
ListLog(List *list) {
    Node *l = list->next;
    while(l != NULL) {
        printf("%d  ", l->element);
        l = l->next;
    }
    printf("\n");
}

int
ListLength(List *list) {
    int len = list->length;
    return len;
}

bool
ListContains(List *list, type element, FunctionElementEqual equal) {
    bool contained = false;
    Node *l = list->next;
    while(l != NULL) {
        if(equal(l->element, element)) {
            contained = true;
            break;
        }
        l = l->next;
    }

    return contained;
}

void
ListAppend(List *list, type element) {

    // 创建新节点
    Node *n = malloc(sizeof(Node));
    n->element = element;
    n->next = NULL;

    // 插入新节点
    if(ListLength(list) == 0) {
        list->next = n;
    } else {
        (list->tail)->next = n;
    }


    // 更新头结点信息
    list->tail = n;
    list->length ++;

}

void
ListPrepend(List *list, type element) {
    Node *n = malloc(sizeof(Node));
    n->element = element;
    n->next = list->next;

    list->next = n;
    list->length++;
}

int
ListIndexOfElement(List *list, type element, FunctionElementEqual equal) {
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
}

void
ListInsertElementAtIndex(List *list, type element, int index) {
    if(index == 0) {
        ListPrepend(list, element);
    }

    int i = 0;
    index--;

    Node *n = malloc(sizeof(List));
    n->element = element;

    Node *l = list->next;

    while(l != NULL) {

        if(i == index) {
            n->next = l->next;
            l->next = n;
        }

        l = l->next;
        i++;
    }
}


int
ListShift(List *list) {
    list->length --;
    Node *first = list->next;
    int e;


    if(first == NULL) {
        return -1;
    } else {
        e = first->element;
    }

    list->next = (list->next)->next;

    free(first);
    return e;
}


void
ListChangeElementAtIndex(List *list, int element, int index) {
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
ListElementAtIndex(List *list, int index){
    int e;
    int i = 0;

    Node *l = list->next;

    while(l != NULL) {

        // printf("i,index %i %i \n", i, index);
        if(i == index) {
            e = l->element;
        }

        l = l->next;
        i++;
    }
    return e;
}

void ListRemove(List * list) {
    while(list->length != 0) {
        ListShift(list);
    }
}

