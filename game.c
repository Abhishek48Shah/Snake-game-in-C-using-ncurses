#include "game.h"
#include "frog.h"
#include "gameState.h"
#include "snake.h"
#include <ncurses.h>
#define WINDOW_X 55
#define WINDOW_Y 5
WINDOW *drawGame(int height, int width, int dx, int dy, GameState *game) {
  int gameFrameHeight, gameFrameWidth;
  int gameWindowHeight, gameWindowWidth;

  // color macro
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);

  // Parent window
  WINDOW *gameFrame = newwin(height - 10, width - 106, WINDOW_Y, WINDOW_X);
  getmaxyx(gameFrame, gameFrameHeight, gameFrameWidth);
  wbkgd(gameFrame, COLOR_PAIR(1) | A_BOLD);
  wrefresh(gameFrame);

  // child window
  WINDOW *scoreWindow =
      derwin(gameFrame, gameFrameHeight - 35, gameFrameWidth - 2, 1, 1);
  wattron(scoreWindow, COLOR_PAIR(2) | A_BOLD);
  mvwprintw(scoreWindow, 2, 2, "Score: %d", game->score);
  wattroff(scoreWindow, COLOR_PAIR(2) | A_BOLD);
  box(scoreWindow, 0, 0);
  wrefresh(scoreWindow);

  WINDOW *gameWindow =
      derwin(gameFrame, gameFrameHeight - 8, gameFrameWidth - 2, 7, 1);
  getmaxyx(gameWindow, gameWindowHeight, gameWindowWidth);
  box(gameWindow, 0, 0);
  drawSnake(game->snake, gameWindow);
  moveSnake(game->snake, dx, dy);
  drawFrog(game->frog, gameWindow);
  spawnFrog(game->frog, gameFrameHeight, gameWindowWidth);
  wrefresh(gameWindow);
  return gameFrame;
}
