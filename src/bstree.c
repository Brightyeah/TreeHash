#include "bstree.h"
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

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

struct bstree *bstree_lookup(struct bstree *tree, int key)
{
    while (tree != NULL) {
        if (key == tree->key) {
            return tree;
        } else if (key < tree->key) {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }
    return tree;
}

struct bstree *bstree_min(struct bstree *tree)
{
    if (tree == NULL) {
        return NULL;
    }
    while (tree->left != NULL) {
        tree = tree->left;
    }
    return tree;
}

struct bstree *bstree_max(struct bstree *tree)
{
    if (tree == NULL) {
        return NULL;
    }
    while (tree->right != NULL) {
        tree = tree->right;
    }
    return tree;
}