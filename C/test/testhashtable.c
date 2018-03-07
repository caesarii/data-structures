
#include <stdio.h>
#include "../HashTable.h"
void
testHashTable() {

    HashTable *h = HashTableCreate();
    HashTableSet(h, "name", 1);
    HashTableSet(h, "name", 2);
    // GuaHashTableLog(t);

//    HashTableSet(t, "11", 1);
//    HashTableSet(t, "a", 2);
//    HashTableSet(t, "abc", 3);
//    HashTableSet(t, "14a", 4);
//
//    ensure(HashTableGet(t, "11") == 1, "test get 1");
//    ensure(HashTableGet(t, "a") == 2, "test get 2");
//    ensure(HashTableGet(t, "abc") == 3, "test get 3");
//    ensure(HashTableGet(t, "14a") == 4, "test get 4");
//
//    ensure(HashTableHas(t, "11") == true, "test has 1");
//    ensure(HashTableHas(t, "5") == false, "test has 2");
//
//    // GuaHashTableRemove(t);
//     HashTableLog(t);

}
