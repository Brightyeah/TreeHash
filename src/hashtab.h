#ifndef HASHTAB_H
#define HASHTAB_H
#define HASH_SIZE 71
#define HASH_MUL 31

struct listnode {
    char *value;
    int key;
    struct listnode *next;
};
struct listnode *hashtab[HASH_SIZE];

unsigned int hashtab_hash(char *value, int length);
void hashtab_init(struct listnode **hashtab);
void hashtab_add(struct listnode **hashtab, char *value, int key);
struct listnode *hashtab_lookup(struct listnode **hashtab, char *value);
void hashtab_delete(struct listnode **hashtab, char *value);
#endif
