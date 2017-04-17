#include "bstree.h"
#include <malloc.h>

struct bstree *bstree_create(char *value, int key)
{
    struct bstree *create;
    create = malloc(sizeof(*create));
    if (create != NULL) {
        create->value = value;
        create->key = key;
        create->left = create->right = create->parent = NULL;
    }
    return create;
}

void bstree_add(struct bstree *tree, char *value, int key)
{
    struct bstree *add;
    if (tree == NULL) {
        return;
    }
    while (tree != NULL) {
        tree->parent = tree;
        if (key < tree->key) {
            tree = tree->left;
        } else if (key > tree->key) {
            tree = tree->right;
        } else {
            return;
        }
    }
    add = bstree_create(value, key);
    if (key < tree->parent->key) {
        tree->left = add;
    } else if (key > tree->parent->key) {
        tree->right = add;
    }
}