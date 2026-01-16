#ifndef FROG_H
#define FROG_H
#include "gameState.h"
#include <ncurses.h>
typedef struct Frog {
  int x, y;
} Frog;
struct Frog *createFrog(GameState *game);
void drawFrog(Frog *frog, WINDOW *window);
void spawnFrog(GameState *game, int height, int width);
void distoryFrog(Frog **head);
#endif
