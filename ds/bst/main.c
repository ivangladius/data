
#include "bst.h"

int main() {

    tree_t tree;
    tree_init(&tree);
    tree_push(&tree, 2);
    tree_push(&tree, 1);
    tree_push(&tree, 3);
    tree_print(&tree);
    return 0;
}