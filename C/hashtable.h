#ifndef __HashTable_H__
#define __HashTable_H__

#include <stdbool.h>
#include "List.h"

struct HashTableStruct;
typedef struct HashTableStruct HashTable;

HashTable *
HashTableCreate(void);

void
HashTableSet(HashTable *table, const char *key, int value);

bool
HashTableHas(HashTable *table, const char *key);

int
HashTableGet(HashTable *table, const char *key, bool *exist);

void
HashTableRemove(HashTable *table);

void
ListChangeElementAtIndex(List *list, int element, int index);

void
HashTableLog(HashTable * table);

int
HashTableLength(HashTable * table);

#endif // __HashTable_H__
