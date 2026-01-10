#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "frog.h"
#include "snake.h"
typedef enum { MENU, GAME, GAMEOVER } Screen;
typedef struct {
  Screen currentLayout;
  int score;
  int snakeLength;
  int quit;
  Snake *snake;
  Frog *frog;
} GameState;
#endif
