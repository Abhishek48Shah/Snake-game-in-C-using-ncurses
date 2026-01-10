#include <ncurses.h>
#ifndef SNAKE_H
#define SNAKE_H
typedef struct Snake {
  int x, y;
  struct Snake *next;
} Snake;
struct Snake *createSnake(int length);
void drawSnake(Snake *head, WINDOW *window);
void moveSnake(Snake *head, int dx, int dy);
void growSnake(Snake *head);
void distorySnake(Snake **head);
int checkSelfCollision(Snake *head);
#endif
