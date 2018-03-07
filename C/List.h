
#ifndef __GuaList_H__
#define __GuaList_H__

#include <stdbool.h>
#include "utils.h"


// ���� �ṹ��, ����
struct NodeStruct;
typedef struct NodeStruct Node;


struct ListStruct;
typedef struct ListStruct List;

typedef int type;

List *
ListCreate(int *element, int numberOfElements);

void
ListLog(List *list);

/*
����һ�� GuaList �ĳ���
*/
int
ListLength(List *list);

/*
���һ�� GuaList ���Ƿ����ĳ��Ԫ��
*/
typedef bool (*FunctionElementEqual)(void *, void *);
bool
ListContains(List *list, type element, FunctionElementEqual equal);

/*
�� GuaList ��ĩβ���һ��Ԫ��
*/
void
ListAppend(List *list, type element);

/*
�� GuaList ��ͷ�����һ��Ԫ��
*/
void
ListPrepend(List *list, type element);

/*
��һ�� GuaList �в���ĳ��Ԫ��, �����±�(���)
���������, ���� -1
*/
int
ListIndexOfElement(List *list, type element, FunctionElementEqual equal);

/*
��һ�� GuaList �в���һ��Ԫ��, �±�(���) Ϊ index
�����ǷǷ����(�±���ڳ���)
*/
void
ListInsertElementAtIndex(List *list, type element, int index);

// ɾ����һ��Ԫ��
type
ListShift(List *list);

// �ı�ָ��Ԫ��
void
ListChangeElementAtIndex(List *list, int element, int index);

// ��ȡָ���������� Ԫ��
int
ListElementAtIndex(List *list, int index);


// ɾ��ȫ��Ԫ��
void ListRemove(List * list);

#endif
