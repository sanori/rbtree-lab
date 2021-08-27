
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

/**
 * Create a new rbtree
 * @return pointer of created rbtree
 */
rbtree* new_rbtree();

/**
 * @brief Remove existing rb tree and reclaim used memory
 */
int delete_rbtree(rbtree*);

int rbtree_insert(rbtree*, key_t);
node_t *rbtree_find(rbtree*, key_t);
node_t *rbtree_min(rbtree*);
node_t *rbtree_max(rbtree*);
int rbtree_erase(rbtree*, node_t*);

int rbtree_to_array(rbtree*, key_t*, int);
