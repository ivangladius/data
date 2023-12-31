
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "bst.h"

#define handle(str) \
do {perror(str);exit(EXIT_FAILURE);}while(0)

node_t * node_make(int value) {
    node_t * new_node = malloc(sizeof(node_t));
    if (!new_node) handle("create_node: malloc");

    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;

    return new_node;
}


int tree_init(tree_t * tree) {
    tree->root = NULL;
    tree->size = 0;
    return 0;
}


node_t * traverse(node_t * node, int value) {
    if (node->right && node->value < value)
        return traverse(node->right, value);
    if (node->left && value < node->value)
        return traverse(node->left, value);
    return node;
}

int tree_push(tree_t * tree, int value) {
    if (!tree->root) {
        tree->root = node_make(value);
        tree->size = 1;
        return 0;
    }

    node_t * new_node = node_make(value);

    node_t * target_node = traverse(tree->root, value);
    if (!target_node) handle("traverse: not found");
    
    if (value < target_node->value) {
        target_node->left = new_node;
    }
    else  {
        target_node->right = new_node;
    }

    new_node->parent = target_node;

    return 0;
}

bool is_leaf(node_t * node) {
  return (node->left == NULL && node->right == NULL);
}

bool has_left(node_t * node) {
  return node->left != NULL;
}

bool has_right(node_t * node) {
  return node->right != NULL;
}

bool has_parent(node_t * node) {
  return node->parent != NULL;
}


node_t * successor(node_t * node) {
  // case 1: has right node
  node_t * current = node;
  while (current->right) {
    current = current->right;
    if (current->left)
      return current->left;
    return current;
  }
  // case 2: has no right subtree
  if (!current->right)
    return current->parent;

  return NULL;
}

/* node_t * predecessor(node_t * node) { */
/* } */


node_t * min(tree_t *tree) {
  node_t * current = tree->root;
  for (; has_left(current); current = current->left);
  return current;
}

node_t * max(tree_t *tree) {
  node_t * current = tree->root;
  for (; has_right(current); current = current->right);
  return current;
}


/* int tree_delete_node(tree_t * tree, int value) { */
/*   // TODO: soon */
/* } */

#define OFFSET_VALUE 10 

void tree_print_helper(node_t * root, int offset) {
    if (!root)
        return;

    tree_print_helper(root->right, offset + OFFSET_VALUE);

    for (int i = 0; i < offset; i++)
        printf(" ");
    printf("%d\n", root->value);

    tree_print_helper(root->left, offset + OFFSET_VALUE);
}

void tree_print(tree_t * tree) {
    tree_print_helper(tree->root, 0);
}
