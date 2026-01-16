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
  init_pair(3, COLOR_RED, COLOR_BLACK);

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
  wattron(scoreWindow, COLOR_PAIR(3));
  mvwaddstr(scoreWindow, 2, gameFrameWidth-30, "Press \'q\' to quit");
  wattroff(scoreWindow, COLOR_PAIR(3));
  box(scoreWindow, 0, 0);
  wrefresh(scoreWindow);

  WINDOW *gameWindow =
      derwin(gameFrame, gameFrameHeight - 8, gameFrameWidth - 2, 7, 1);
  getmaxyx(gameWindow, gameWindowHeight, gameWindowWidth);
  box(gameWindow, 0, 0);
  drawSnake(game->snake, gameWindow);
  moveSnake(game, dx, dy);
  drawFrog(game->frog, gameWindow);
  wrefresh(gameWindow);
  if (game->snake->x >= game->frog->x && game->snake->x < game->frog->x + 5 &&
      game->snake->y == game->frog->y) {
    game->score += 1;
    game->snakeLength+=1;
    growSnake(game->snake);
    spawnFrog(game, gameWindowHeight, gameWindowWidth);
  }
  if (game->snake->x < 1 || game->snake->y < 0 ||
      game->snake->x >= gameWindowWidth - 1 ||
      game->snake->y >= gameWindowHeight) {
    game->currentLayout = GAMEOVER;
  }
  if (checkSelfCollision(game->snake)) {
    game->currentLayout = GAMEOVER;
  }

  return gameFrame;
}
