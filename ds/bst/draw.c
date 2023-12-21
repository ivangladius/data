
#include "draw.h"

#include "/home/max/libs/raylib/src/raylib.h"
#include <string.h>
#include <stdio.h>


void draw_window(window_t * window) {
  InitWindow(window->width, window->height, window->title);
  SetTargetFPS(60);
}


dot_t create_dot(int x, int y, Color color) {
  dot_t dot = {
    .position.x = x,
    .position.y = y,
    .color = color
  };
  return dot;
}

void draw_dot(dot_t * dot) {
  DrawPixel(dot->position.x, dot->position.y, dot->color);
}



circle_t create_circle(int x, int y, double radius, Color color) {
  circle_t circle = {
    .position.x = x,
    .position.y = y,
    .radius = radius,
    .color = color
  };
  return circle;
}

void draw_circle(circle_t * circle) {
  for (int i = 0; i < 2; i++) {
    DrawCircleLines(circle->position.x, circle->position.y, circle->radius - i, circle->color);
  }
}


circle_node_t create_circle_node(int x, int y, double radius, Color color, int value, int font_size) {
  circle_t circle = create_circle(x, y, radius, color);
  circle_node_t circle_node = {
    .circle = circle,
    .font_size = font_size,
    .value = value
  };
  return circle_node;
}

void draw_circle_node(circle_node_t * circle_node) {
  draw_circle(&circle_node->circle);
  char number[20];
  snprintf(number, 20, "%d", circle_node->value);
  int font_size_offset = strlen(number) - 1;
  DrawText(number, circle_node->circle.position.x - 10, circle_node->circle.position.y - 12,
	   circle_node->font_size - font_size_offset, circle_node->circle.color);
}


line_t create_line(int startx, int starty, int endx, int endy, Color color) {
  line_t line = {
    .start.x = startx,
    .start.y = starty,
    .end.x = endx,
    .end.y = endy,
    .color = color
  };
  return line;
}

void draw_line(line_t * line) {
  DrawLine(line->start.x, line->start.y, line->end.x, line->end.y, line->color);
}

void connect_circles(circle_t * circle1, circle_t * circle2, Color color) {
  int startx = circle1->position.x;
  int starty = circle1->position.y;
  int endx = circle2->position.x;
  int endy = circle2->position.y;
  DrawLine(startx+2, starty+2, endx+2, endy+2, color);
  DrawLine(startx+1, starty+1, endx+1, endy+1, color);
  DrawLine(startx, starty, endx, endy, color);
  DrawLine(startx-1, starty-1, endx-1, endy-1, color);
  DrawLine(startx-2, starty-2, endx-2, endy-2, color);
}
