#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "HashTable.h"
#include "utils.h"

struct HashTableStruct {
    int length;
    List * array[100];

};

HashTable *
HashTableCreate(int length) {
    int len = nextPrime(length);
    HashTable * table = malloc(sizeof(HashTable));
    table->length = len;

    int i = 0;
    while(i < len) {
        (table->array)[i] = ListCreate(NULL, 0);
        i++;
    }

    return table;
};

void
HashTableLog(HashTable * table) {
    int len =  table->length;
    int i = 0;
    while(i < len) {
        List * l = (table->array)[i];
        ListLog(l);
        i++;
    }

}

void
HashTableSet(HashTable * table, const char * key, int value) {
    int index = hash(key, table->length);
    printf("index %i \n", index);
    List * l = (table->array)[index];
    ListAppend(l, value);
};

bool
HashTableHas(HashTable * table, const char * key) {
    int index = hash(key, table->length);

    bool has = true;
    List * l = (table->array)[index];
    if(ListLength(l) == 0) {
        has = false;
    }
    return has;
};

int
HashTableGet(HashTable * table, const char * key) {
    int index = hash(key, table->length);
    List * l = (table->array)[index];
    return ListElementAtIndex(l, 0);
};

void
HashTableRemove(HashTable * table) {
    int len =  table->length;
    int i = 0;
    while(i < len) {
        List * l = (table->array)[i];
        ListRemove(l);
        i++;
    }
    free(table);
};


