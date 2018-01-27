#ifndef __DoublyLinkedList__
#define __DoublyLinkedList__


#include <stdbool.h>

struct NodeStruct;
typedef struct NodeStruct Node;

struct ListStruct;
typedef struct ListStruct List;

typedef int type;

List *
DLListCreate(int *element, int numberOfElements);

void
DLListLog(List *list);

int
DLListLength(List *list);

bool
DLListContains(List *list, type element);

void
DLListAppend(List *list, type element);

void
DLListPrepend(List *list, type element);

int
DLListIndexOfElement(List *list, type element);

void
DLListInsertElementAtIndex(List *list, type element, int index);

type
DLListShift(List *list);

int
DLListElementAtIndex(List *list, int index);

void DLListRemove(List * list);

#endif
