#include <assert.h>
#include <rbtree.h>
#include <stdbool.h>

// new_rbtree should return rbtree struct with null root node
void test_init(void) {
  rbtree *t = new_rbtree();
  assert(t != NULL);
  assert(t->root == NULL);
  delete_rbtree(t);
}

// root node's color should be black
void test_insert_single(const key_t key) {
  rbtree *t = new_rbtree();
  node_t *p = rbtree_insert(t, key);
  assert(p != NULL);
  assert(t->root != p);
  assert(p->key == key);
  assert(p->color == RBTREE_BLACK);  // color of root node should be black
  assert(p->left == NULL);
  assert(p->right == NULL);
  delete_rbtree(t);
}

// Test color constraint
// 1. Each node is either red or black. (by definition)
// 2. All NIL nodes are considered black.
// 3. A red node does not have a red child.
// 4. Every path from a given node to any of its descendant NIL nodes goes
// through the same number of black nodes.

bool touch_nil = false;
int max_black_depth = 0;

static void init_color_traverse(void) {
  touch_nil = false;
  max_black_depth = 0;
}

static bool color_traverse(const node_t *p, const color_t parent_color,
                           const int black_depth) {
  if (p == NULL) {
    if (touch_nil) {
      if (black_depth != max_black_depth) {
        return false;
      }
    } else {
      touch_nil = true;
      max_black_depth = black_depth;
    }
    return true;
  }
  if (parent_color == RBTREE_RED && p->color == RBTREE_RED) {
    return false;
  }
  int next_depth = ((p->color == RBTREE_BLACK) ? 1 : 0) + black_depth;
  return color_traverse(p->left, p->color, next_depth) &&
         color_traverse(p->right, p->color, next_depth);
}

void test_color_constraint(const rbtree *t) {
  assert(t != NULL);
  node_t *p = t->root;
  assert(p != NULL);
  assert(p->color == RBTREE_BLACK);

  init_color_traverse();
  assert(color_traverse(p, RBTREE_BLACK, 0));
}

// rbtree should keep search tree and color constraints
void test_rb_constraints(const key_t arr[], const size_t n) {
  rbtree *t = new_rbtree();
  for (int i = 0; i < n; i++) {
    rbtree_insert(t, arr[i]);
  }
  test_color_constraint(t);
  delete_rbtree(t);
}

int main(void) {
  test_init();
  test_insert_single(1024);
  const key_t entries[] = {10, 5, 8, 34, 67, 23, 156, 24, 2, 12};
  const size_t n = sizeof(entries) / sizeof(entries[0]);
  test_rb_constraints(entries, n);
}
