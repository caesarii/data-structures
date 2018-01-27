#ifndef GUAHASHTABLE_H_INCLUDED
#define GUAHASHTABLE_H_INCLUDED

#include <stdbool.h>

struct HashTableStruct;
typedef struct HashTableStruct HashTable;

HashTable *
HashTableCreate(int length);

void
HashTableSet(HashTable * table, const char * key, int value);

bool
HashTableHas(HashTable * table, const char * key);

int
HashTableGet(HashTable * table, const char * key);

void
HashTableRemove(HashTable * table);

void
ListChangeElementAtIndex(List *list, int element, int index);

void
HashTableLog(HashTable * table);

int
HashTableLength(HashTable * table);

#endif // GUAHASHTABLE_H_INCLUDED
