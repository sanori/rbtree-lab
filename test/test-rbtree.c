#include <assert.h>
#include <rbtree.h>

int main() {
    rbtree *t = new_rbtree();
    assert(t != NULL);
    assert(t->root == NULL);
    delete_rbtree(t);
}