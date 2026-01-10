#include "gameOver.h"
#include <ncurses.h>
WINDOW *drawGameOver() {
  WINDOW *gameOverWindow = newwin(0, 0, 0, 0);
  return gameOverWindow;
}
