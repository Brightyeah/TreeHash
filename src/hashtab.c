#include "hashtab.h"
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

unsigned int kp_hash(char *value)
{
    unsigned int kp = 0;
    char *pkey;
    for (pkey = key; *pkey != '\0'; pkey++) {
        kp = kp * HASH_MUL + (unsigned int)*pkey;
    }
    return kp % HASH_SIZE;
}

void hashtab_init(struct listnode **hashtab)
{
    for (int i = 0; i < HASH_SIZE; i++) {
        hashtab[i] = NULL;
    }
}