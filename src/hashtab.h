#ifndef HASHTAB_H
#define HASHTAB_H
#define HASH_SIZE 71
#define HASH_MUL 31
#include <inttypes.h>
struct listnode {
    char *value;
    int key;
    struct listnode *next;
};
struct listnode *hashtab[HASH_SIZE];

uint32_t hashtab_hash(char *value, int len);
void hashtab_init(struct listnode **hashtab);
void hashtab_add(struct listnode **hashtab, char *value, int key);
struct listnode *hashtab_lookup(struct listnode **hashtab, char *value);
void hashtab_delete(struct listnode **hashtab, char *value);
#endif
