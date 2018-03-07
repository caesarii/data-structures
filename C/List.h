
#ifndef __GuaList_H__
#define __GuaList_H__

#include <stdbool.h>
#include "utils.h"


// 声明 结构名, 类型
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
返回一个 GuaList 的长度
*/
int
ListLength(List *list);

/*
检查一个 GuaList 中是否存在某个元素
*/
typedef bool (*FunctionElementEqual)(void *, void *);
bool
ListContains(List *list, type element, FunctionElementEqual equal);

/*
在 GuaList 的末尾添加一个元素
*/
void
ListAppend(List *list, type element);

/*
在 GuaList 的头部添加一个元素
*/
void
ListPrepend(List *list, type element);

/*
在一个 GuaList 中查找某个元素, 返回下标(序号)
如果不存在, 返回 -1
*/
int
ListIndexOfElement(List *list, type element, FunctionElementEqual equal);

/*
往一个 GuaList 中插入一个元素, 下标(序号) 为 index
不考虑非法情况(下标大于长度)
*/
void
ListInsertElementAtIndex(List *list, type element, int index);

// 删除第一个元素
type
ListShift(List *list);

// 改变指定元素
void
ListChangeElementAtIndex(List *list, int element, int index);

// 获取指定索引处的 元素
int
ListElementAtIndex(List *list, int index);


// 删除全部元素
void ListRemove(List * list);

#endif
