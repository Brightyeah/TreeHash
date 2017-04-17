#ifndef BSTREE_H
#define BSTREE_H

//typedef struct tree tree;
struct bstree{
    char *value;
    int key;
    struct bstree *left;
    struct bstree *right;
	struct bstree *parent;
};

struct bstree *bstree_create(char *value, int key);
void bstree_add(struct bstree *tree, char *value, int key);
struct bstree *bstree_lookup(struct bstree *tree, int key);
struct bstree *bstree_min(struct bstree *tree);
struct bstree *bstree_max(struct bstree *tree);
#endif