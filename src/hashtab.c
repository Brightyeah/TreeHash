#include "hashtab.h"
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

unsigned int hashtab_hash(char *value)
{
    unsigned int h = 0;
    char *p;
    for (p = value; *p != '\0'; p++) {
        h = h * HASH_MUL + (unsigned int)*p;
    }
    return h % HASH_SIZE;
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
    int index = hashtab_hash(value);
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
    int index = hashtab_hash(value);
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
    int index = hashtab_hash(value);
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