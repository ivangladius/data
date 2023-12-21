
#include "bst.h"

#include <stdio.h>

#include "/home/max/libs/raylib/src/raylib.h"
#include "draw.h"

void test_min(tree_t * tree) {
  node_t * min_node = min(tree);
  printf("min: %d\n", min_node->value);
}

void test_max(tree_t * tree) {
  node_t * max_node = max(tree);
  printf("max: %d\n", max_node->value);
}


int main() {

  window_t window = {
    .width = 600,
    .height = 400,
    .title = "BST"
  };

  draw_window(&window);

  circle_node_t circle_node_left =
    create_circle_node((window.width / 2) / 2, window.height / 2 , 50.0f, BLACK, 8, 40);
  circle_node_t circle_node_right =
    create_circle_node(window.width - ((window.width / 2) / 2),
		       window.height / 2, 50.0f, BLACK, 4, 40);

  circle_node_t circle_node_mid =
    create_circle_node(window.width / 2,
		       window.height / 2, 50.0f, BLACK, 3, 40);

  /*   { */
  /*   .position.x = (window.width / 2) / 2, */
  /*   .position.y = window.height / 2, */
  /*   .radius = 50.0f, */
  /*   .color = BLACK */
  /* }; */

  /* circle_t circle_right = { */
  /*   .position.x = window.width - ((window.width / 2)  / 2), */
  /*   .position.y = window.height / 2, */
  /*   .radius = 50.0f, */
  /*   .color = BLACK */
  /* }; */

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    draw_circle_node(&circle_node_left);
    draw_circle_node(&circle_node_right);
    draw_circle_node(&circle_node_mid);

    connect_circles(&circle_node_left.circle, &circle_node_mid.circle, BLACK);
    EndDrawing();
  }

  CloseWindow();
  
  /* tree_t tree; */
  /* tree_init(&tree); */
  /* tree_push(&tree, 8); */
  /* tree_push(&tree, 3); */
  /* tree_push(&tree, 1); */
  /* tree_push(&tree, 6); */
  /* tree_push(&tree, 4); */
  /* tree_push(&tree, 7); */
  /* tree_push(&tree, 10); */
  /* tree_push(&tree, 14); */
  /* tree_push(&tree, 13); */

  /* tree_print(&tree); */

  /* test_min(&tree); */
  /* test_max(&tree); */
  return 0;
}
