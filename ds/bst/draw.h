
#ifndef DRAW_HEADER
#define DRAW_HEADER

#include "/home/max/libs/raylib/src/raylib.h"

typedef struct Point {
  int x;
  int y;
} point_t;

typedef struct Window {
  int width;
  int height;
  const char * title;
} window_t;

typedef struct Dot {
  point_t position;
  Color color;
} dot_t;

typedef struct Circle {
  point_t position;
  double radius;
  Color color;
} circle_t;

typedef struct CircleNode {
  int value;
  int font_size;
  circle_t circle;
} circle_node_t;

typedef struct Line {
  point_t start;
  point_t end;
  Color color;
} line_t;

void draw_window(window_t * window);

dot_t create_dot(int x, int y, Color color);
void draw_dot(dot_t * dot);

circle_t create_circle(int x, int y, double radius, Color color);
void draw_circle(circle_t * circle);

line_t create_line(int startx, int starty, int endx, int endy, Color color);
void draw_line(line_t * line);

circle_node_t create_circle_node(int x, int y, double radius, Color color, int value, int font_size);
void draw_circle_node(circle_node_t * circle_node);

void connect_circles(circle_t * circle1, circle_t * circle2, Color color);

#endif
