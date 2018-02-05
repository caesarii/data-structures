#include <stdbool.h>

#include "utils.h"

int
hash(const char * key, int length) {
    int hash = 0;
    while(*key != '\0') {
        hash += *key++;
    }

    return (hash % length);
}


int
nextPrime(int length) {
    if(length % 2 == 0) {
        length++;
    }
    int i;
    bool isPrime = false;
    while(true) {
        length += 2;
        for(i = 3; i*i <= length; i+= 2) {
            if(length % i == 0) {
                isPrime = true;
                break;
            }
        }
        if(!isPrime) {
            return length;
        }
    }
}

void
ensure(bool condition, const char *message) {
    if(!condition) {
        printf("test failed: %s\n", message);
    } else {
        printf("test sucessed %s \n", message);
    }
}

void formattedLog(int element, int n) {
    for(int i = 0; i < n; i++) {
        printf("___|");
    }
    printf("%d \n", element);
}
