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