#include <stddef.h>

typedef enum {RED, BLACK} color_t;
typedef int key_t; 
typedef struct node_t {
    color_t color;
    key_t key;
    struct node_t *parent, *left, *right;
} node_t;

typedef struct {
  node_t *root;
} rbtree;

rbtree* new_rbtree();
void delete_rbtree(rbtree*);

node_t *rbtree_insert(rbtree*, key_t);
node_t *rbtree_find(rbtree*, key_t);
node_t *rbtree_min(rbtree*);
node_t *rbtree_max(rbtree*);
int rbtree_erase(rbtree*, node_t*);

int rbtree_to_array(rbtree*, key_t*, int);
