#include "frog.h"
#include <ncurses.h>
#include <stdlib.h>

int getRandomAxis(int max) { return 1 + rand() % (max - 2); }

struct Frog *createFrog(int height, int width) {

  Frog *frog = malloc(sizeof(Frog));
  frog->x = getRandomAxis(width);
  frog->y = getRandomAxis(height);
  return frog;
}
void drawFrog(Frog *frog, WINDOW *window) {
  mvwaddstr(window, frog->y, frog->x, "('-')");
}
void spawnFrog(Frog *frog, int height, int width) {
  frog->x = getRandomAxis(width);
  frog->y = getRandomAxis(height);
}
