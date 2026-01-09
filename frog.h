#ifndef FROG_H
#define FROG_H
#include <ncurses.h>
typedef struct Frog {
  int x, y;
} Frog;
struct Frog *createFrog(int height, int width);
void drawFrog(Frog *frog, WINDOW *window);
void spawnFrog(Frog *frog, int height, int width);
// void respawnFrog(Frog *frog, int dx, int dy);
#endif
