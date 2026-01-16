#include "exitMenu.h"
#include "game.h"
#include "gameOver.h"
#include "gameState.h"
#include "menu.h"
#include <ncurses.h>
#include <stdlib.h>
#define DELAY 200
WINDOW *currentWindow = NULL;

int term_height, term_width;
int dx = 1, dy = 0;

int main() {
  GameState *game = malloc(sizeof(GameState));
  game->currentLayout = MENU;
  game->quit = 1;
  game->snakeLength = 3;
  game->frogX = 5;
  game->frogY = 3;
  game->snakeX = 10;
  game->snakeY = 10;
  game->score = 0;
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);
  start_color();
  getmaxyx(stdscr, term_height, term_width);
  box(stdscr, 0, 0);
  wrefresh(stdscr);
  int gameStatus = checkGameState();
  while (game->quit) {

    timeout(DELAY);

    if (currentWindow != NULL) {
      werase(currentWindow);
      wrefresh(currentWindow);
      delwin(currentWindow);
      currentWindow = NULL;
    }

    if (game->currentLayout == MENU) {
      currentWindow = drawMenu(term_height, term_width, gameStatus);
    } else if (game->currentLayout == GAME) {
      currentWindow = drawGame(term_height, term_width, dx, dy, game);
    } else if (game->currentLayout == GAMEOVER) {
      currentWindow = drawGameOver(term_height, term_width, game);
    } else if (game->currentLayout == SAVE) {
      currentWindow = drawExitMenu(term_height, term_width);
    }

    int input = getch();

    switch (input) {
      // To update game layout
    case 'g':
      if (game->currentLayout != GAME) {
        setGameState(game, 0);
        game->currentLayout = GAME;
      }
      break;
    case 'c':
      if (game->currentLayout != GAME && game->currentLayout != GAMEOVER) {
        setGameState(game, 1);
        game->currentLayout = GAME;
      }
      break;
      // TO exit from the game
    case 'q':
      if (game->currentLayout == GAME) {
        game->currentLayout = SAVE;
      } else {
        game->quit = 0;
      }
      break;
    case 'y':
      if (game->currentLayout == SAVE) {
        saveGame(game);
        game->quit = 0;
      }
      break;
    case 'n':
      if (game->currentLayout == SAVE) {
        removePrevGame();
        game->quit = 0;
      }
      break;
    case KEY_UP:
      if (dy != 1) {

        dx = 0;
        dy = -1;
      }
      break;
    case KEY_DOWN:
      if (dy != -1) {
        dx = 0;
        dy = 1;
      }
      break;
    case KEY_LEFT:
      if (dx != 1) {
        dx = -1;
        dy = 0;
      }
      break;
    case KEY_RIGHT:
      if (dx != -1) {
        dx = 1;
        dy = 0;
      }
      break;
    }
  }
  freeMemory(game);
  free(game);
  endwin();
}
