#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include <stdio.h>

int
hash(const char * key, int length);


int
nextPrime(int length);

void
ensure(bool condition, const char *message);

#endif // UTILS_H_INCLUDED
