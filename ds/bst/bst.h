
#ifndef BST_HEADER
#define BST_HEADER

#include <stdlib.h>

typedef struct Node node_t;
typedef struct Tree tree_t;

struct Node {
    int value;
    node_t * left;
    node_t * right;
    node_t * parent;
};

struct Tree {
    node_t * root;
    size_t size;
};

node_t * node_make(int value);

int tree_init(tree_t * tree);
node_t * traverse(node_t * node, int value);
int tree_push(tree_t * tree, int value);

bool is_leaf(node_t * node);
bool has_left(node_t * node);
bool has_right(node_t * node);
bool has_parent(node_t * node);
int tree_delete_node(tree_t * tree, int value);
node_t * succressor(node_t * node);
node_t * predecessor(node_t * node);

void tree_print(tree_t * tree);

#endif
