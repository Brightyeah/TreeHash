#include "hashtab.h"
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>

unsigned int hashtab_hash(char *value, int length)
{
    unsigned int hash = 0;
    int i = 0;
    while (i != length) {
        hash += value[i++];
        hash += hash << 10;
        hash ^= hash >> 6;
    }
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    return hash;
}

void hashtab_init(struct listnode **hashtab)
{
    for (int i = 0; i < HASH_SIZE; i++) {
        hashtab[i] = NULL;
    }
}

void hashtab_add(struct listnode **hashtab, char *value, int key)
{
    struct listnode *add;
    unsigned int index = hashtab_hash(value, strlen(value));
    add = malloc(sizeof(*add));
    if (add != NULL) {
        add->value = value;
        add->key = key;
        add->next = hashtab[index];
        hashtab[index] = add;
    }
}

struct listnode *hashtab_lookup(struct listnode **hashtab, char *value)
{
    unsigned int index = hashtab_hash(value, strlen(value));
    struct listnode *node;
    for (node = hashtab[index]; node != NULL; node = node->next) {
        if (strcmp(node->value, value) == 0) {
            return node;
        }
    }
    return NULL;
}

void hashtab_delete(struct listnode **hashtab, char *value)
{
    int index = hashtab_hash(value, strlen(value));
    struct listnode *p, *res;
    for (p = hashtab[index]; p != NULL; p = p->next) {
        if (strcmp(p->value, value) == 0) {
            if (res == NULL) {
                hashtab[index] = p->next;
            } else {
                res->next = p->next;
            }
            free(p);
            return;
        }
        res = p;
    }
}
