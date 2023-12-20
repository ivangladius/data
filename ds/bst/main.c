
#include "bst.h"

#include <stdio.h>


void test_min(tree_t * tree) {
  node_t * min_node = min(tree);
  printf("min: %d\n", min_node->value);
}

void test_max(tree_t * tree) {
  node_t * max_node = max(tree);
  printf("max: %d\n", max_node->value);
}


int main() {

    tree_t tree;
    tree_init(&tree);
    tree_push(&tree, 8);
    tree_push(&tree, 3);
    tree_push(&tree, 1);
    tree_push(&tree, 6);
    tree_push(&tree, 4);
    tree_push(&tree, 7);
    tree_push(&tree, 10);
    tree_push(&tree, 14);
    tree_push(&tree, 13);

    tree_print(&tree);

    /* test_min(&tree); */
    /* test_max(&tree); */
    return 0;
}
