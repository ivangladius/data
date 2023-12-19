
#include "bst.h"

int main() {

    tree_t tree;
    tree_init(&tree);
    tree_push(&tree, 6);
    tree_push(&tree, 12);
    tree_push(&tree, 7);
    tree_print(&tree);
    return 0;
}