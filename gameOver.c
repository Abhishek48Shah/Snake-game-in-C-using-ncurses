#include "gameOver.h"
#include "gameState.h"
#include <ncurses.h>
#define WINDOW_X 70
#define WINDOW_Y 16

WINDOW *drawGameOver(int height, int width, GameState *game) {
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  init_pair(3, COLOR_RED, COLOR_BLACK);
  WINDOW *gameOverWindow = newwin(height - 30, width - 150, WINDOW_Y, WINDOW_X);
  wbkgd(gameOverWindow, COLOR_PAIR(1) | A_BOLD);
  mvwaddstr(gameOverWindow, 2, 25, "Game Over");
  wattron(gameOverWindow, COLOR_PAIR(2) | A_BOLD);
  mvwprintw(gameOverWindow, 9, 25, "Score: %d", game->score);
  wattroff(gameOverWindow, COLOR_PAIR(2) | A_BOLD);
  wattron(gameOverWindow, COLOR_PAIR(3) | A_BOLD);
  mvwaddstr(gameOverWindow, 15, 20, "Press \'q\' to exit game");
  wattroff(gameOverWindow, COLOR_PAIR(3) | A_BOLD);
  box(gameOverWindow, 0, 0);
  wrefresh(gameOverWindow);

  return gameOverWindow;
}
