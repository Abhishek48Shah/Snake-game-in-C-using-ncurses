#include "frog.h"
#include "gameState.h"
#include <ncurses.h>
#include <stdlib.h>

int getRandomAxis(int max) { return 1 + rand() % (max - 2); }

struct Frog *createFrog(GameState *game) {

  Frog *frog = malloc(sizeof(Frog));
  frog->x = game->frogX;
  frog->y = game->frogY;
  return frog;
}
void drawFrog(Frog *frog, WINDOW *window) {
  mvwaddstr(window, frog->y, frog->x, "('-')");
}
void spawnFrog(GameState *game, int height, int width) {
  game->frogX = game->frog->x = getRandomAxis(width);
 game->frogY = game->frog->y = getRandomAxis(height);
}
void distoryFrog(Frog **head) {
  if (!head || !*head)
    return;
  free(*head);
  *head = NULL;
}
