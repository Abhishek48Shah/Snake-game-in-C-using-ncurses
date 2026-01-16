#include <ncurses.h>
#include "gameState.h"
#ifndef SNAKE_H
#define SNAKE_H
typedef struct Snake {
  int x, y;
  struct Snake *next;
} Snake;
struct Snake *createSnake(GameState *game);
void drawSnake(Snake *head, WINDOW *window);
void moveSnake(GameState *game, int dx, int dy);
void growSnake(Snake *head);
void distorySnake(Snake **head);
int checkSelfCollision(Snake *head);
#endif
