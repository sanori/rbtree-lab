#include <malloc.h>
#include "rbtree.h"

rbtree* new_rbtree() {
    rbtree *p = (rbtree *) calloc(sizeof(rbtree), 1);
    return p;
}

void delete_rbtree(rbtree* t) {
    // TODO: reclaim the tree nodes's memory
    free(t);
}

node_t *rbtree_insert(rbtree* t, key_t key) {
    return t->root;
}

node_t *rbtree_find(rbtree* t, key_t key) {
    return t->root;
}

node_t *rbtree_min(rbtree* t) {
    return t->root;
}

node_t *rbtree_max(rbtree* t) {
    return t->root;
}

int rbtree_erase(rbtree* t, node_t* p) {
    return 0;
}

int rbtree_to_array(rbtree* t, key_t* arr, int n) {
    return 0;
}
