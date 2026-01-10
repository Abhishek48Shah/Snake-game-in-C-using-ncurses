#include "frog.h"
#include "game.h"
#include "gameOver.h"
#include "gameState.h"
#include "menu.h"
#include "snake.h"
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
  game->snake = createSnake(game->snakeLength);
  game->frog = createFrog();
  while (game->quit) {

    timeout(DELAY);

    if (currentWindow != NULL) {
      werase(currentWindow);
      wrefresh(currentWindow);
      delwin(currentWindow);
      currentWindow = NULL;
    }

    if (game->currentLayout == MENU) {
      currentWindow = drawMenu(term_height, term_width);
    } else if (game->currentLayout == GAME) {
      currentWindow = drawGame(term_height, term_width, dx, dy, game);
    } else if (game->currentLayout == GAMEOVER) {
      currentWindow = drawGameOver();
    }

    int input = getch();

    switch (input) {
    case 'g':
      game->currentLayout = GAME;
      break;
    case 'q':
      game->quit = 0;
      break;
    case KEY_UP:
      dx = 0;
      dy = -1;
      break;
    case KEY_DOWN:
      dx = 0;
      dy = 1;
      break;
    case KEY_LEFT:
      dx = -1;
      dy = 0;
      break;
    case KEY_RIGHT:
      dx = 1;
      dy = 0;
      break;
    }
    if(game->snake->x >= game->frog->x && game->snake->y == game->frog->y){
	    game->score++;
	    growSnake(game->snake);
    }
  }
  endwin();
}
