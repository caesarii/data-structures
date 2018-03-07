#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "hashtable.h"
#include "utils.h"

struct HashTableKeyValueStruct;
typedef struct HashTableKeyValueStruct KeyValue;

struct HashTableKeyValueStruct {
    char *key;
    int value;
};

struct HashTableStruct {
    int arrayLength;
    List **array;

};

// string 处理函数
int
stringLength(const char *s) {
    int len = 0;
    while(*s != '\0') {
        len++;
        s++;
    }
    return len;
}

char *
stringCopy(const char *string) {
    int len = stringLength(string);
    char *s = malloc(len + 1);
    for(int i = 0; i < len; i++) {
        s[i] = string[i];
    }
    s[len] = '\0';
    return s;
}

bool
stringEqual(const char *s1, const char *s2) {
    int len1 = stringLength(s1);
    int len2 = stringLength(s2);
    if(len1 != len2) {
        return false;
    } else {
        for(int i = 0; i < len1; i++) {
            if(s1[i] != s2[i]) {
                return false;
            }
        }
    }
    return true;
}

// 内部函数

KeyValue *
KeyValueCreate(const char *key, int value) {
    KeyValue *kv = malloc(sizeof(KeyValue));
    kv->key = stringCopy(key);
    kv->value = value;
    return kv;
}

int
KeyValueValue(KeyValue *kv) {
    return kv->value;
}

bool
KeyValueKeyEqual(void *kv1, void *kv2) {
    KeyValue *p1 = kv1;
    KeyValue *p2 = kv2;
    bool eq = stringEqual(p1->key, p2->key);
    return eq;
}

HashTable *
HashTableCreate(void) {
    int length = 107;
    HashTable *h = malloc(sizeof(HashTable));
    h->arrayLength = length;
    
    List **array = malloc(sizeof(List *) * length);
    // 初始化数组中所有元素为 NULL
    for(int i = 0; i < length; i++) {
        array[i] = ListCreate(NULL, 0);
    }
    h->array = array;
    
    return h;
};

//void
//HashTableLog(HashTable * table) {
//    int len =  table->length;
//    int i = 0;
//    while(i < len) {
//        List * l = (table->array)[i];
//        ListLog(l);
//        i++;
//    }
//
//}

static int
hash(const char *key) {
    // gua 计算过程如下
    // 'g' * 1 + 'u' * 10 + 'a' * 100
    int digit = 1;
    int sum = 0;
    const char *p = key;
    while(*p != '\0') {
        sum += *p * digit;
        digit *= 10;
        p++;
    }
    return sum;
};


void
HashTableSet(HashTable * table, const char * key, int value) {
    int index = hash(key) % table->arrayLength;
    List *list = table->array[index];
    if(ListLength(list) == 0) {
        KeyValue *kv = KeyValueCreate(key, value);
        ListAppend(list, kv);
    } else {
        KeyValue *kv = KeyValueCreate(key, value);
        int index = ListIndexOfElement(list, kv, KeyValueKeyEqual);
        if(index != -1) {
            ListChangeElementAtIndex(list, kv, index);
        } else {
            ListAppend(list, kv);
        }
        
    }
};

bool
HashTableHas(HashTable * table, const char * key) {
    int index = hash(key) % table->arrayLength;
    List *list = table->array[index];
    if(ListLength(list) == 0) {
        return false;
    } else {
        KeyValue *kv = KeyValueCreate(key, 0);
        int index = ListIndexOfElement(list, kv, KeyValueKeyEqual);
        return index != -1;
    }
    return true;
    
};

int
HashTableGet(HashTable * table, const char * key, bool *exist) {
    int index = hash(key) % table->arrayLength;
    List *list = table->array[index];
    if(ListLength(list) == 0) {
        // 不存在
        *exist = false;
        return -1;
    } else {
        KeyValue *kv = KeyValueCreate(key, 0);
        int index = ListIndexOfElement(list, kv, KeyValueKeyEqual);
        if(index != -1) {
            *exist = true;
            KeyValue *kv = ListElementAtIndex(list, index);
            return KeyValueValue(kv);
        } else {
            *exist = false;
            return -1;
        }
        
    }
};

void
HashTableRemove(HashTable * table) {
//    int len =  table->length;
//    int i = 0;
//    while(i < len) {
//        List * l = (table->array)[i];
//        ListRemove(l);
//        i++;
//    }
//    free(table);
};


