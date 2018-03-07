#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "List.h"

// �ṹ�ľ��嶨��
struct NodeStruct {
    type element;
    Node *next;
};

struct ListStruct {
    int length;
    Node *next;
    Node *tail;
};


// ����������һ�� List
// element ��һ�� int ����
// numberOfElements ������ĳ���
// �� C ������, ����ĳ�����ϢҪ�����ṩ
List *
ListCreate(int *element, int numberOfElements) {
    // assert ������ȷ��һ�������Ķ���
    assert(numberOfElements >= 0);

    // malloc ����һ���ڴ�, ����ʼ��һ��
    List *list = malloc(sizeof(List));
    list->next = NULL;
    list->length = numberOfElements;
    list->tail = NULL;


    // ѭ�������ʼ��Ԫ��
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

// ��һ�� List �����ݴ�ӡ����
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

    // �����½ڵ�
    Node *n = malloc(sizeof(Node));
    n->element = element;
    n->next = NULL;

    // �����½ڵ�
    if(ListLength(list) == 0) {
        list->next = n;
    } else {
        (list->tail)->next = n;
    }


    // ����ͷ�����Ϣ
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

