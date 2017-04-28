#include "hashtab.h"
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#define FUNK 0

unsigned int hashtab_hash(char *value, int len)
{
    unsigned int hash;
    if (FUNK == 1) {
        hash = jenkins_one_at_a_time_hash(value, len);
    } else {
        hash = hash_kp(value);
    }
    return hash % HASH_SIZE;
}

unsigned int hash_kp(char *value)
{
    unsigned int hash = 0;
    char *p;
    for (p = value; *p != '\0'; p++) {
        hash = hash * HASH_MUL + (unsigned int)*p;
    }
    return hash;
}

uint32_t jenkins_one_at_a_time_hash(char *value, int len)
{
    uint32_t hash = 0;
    int i = 0;
    while (i != len) {
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
    uint32_t index = hashtab_hash(value, strlen(value));
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
    int index = hashtab_hash(value, strlen(value) - 1);
    struct listnode *node;
    for (node = hashtab[index]; node != NULL; node = node->next) {
        if (strcmp(node->value, value) == 0) {
            return node;
        }
    }
    return NULL;
}
/*
void hashtab_delete(struct listnode **hashtab, char *value)
{
    unsigned index = hashtab_hash(value);
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
}*/
