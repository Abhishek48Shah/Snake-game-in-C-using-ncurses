#include "frog.h"
#include "snake.h"
#include <ncurses.h>
#define WINDOW_X 10
#define WINDOW_Y 5
#define DELAY 200
int quit = 1;
int dx = 0, dy = -1;
int length = 3;
int term_height, term_width;
int min_window_height, min_window_width;
int frogWidth = 5;
int score = 0;
int main() {
  int input;
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);
  start_color();

  getmaxyx(stdscr, term_height, term_width);
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
  wattron(stdscr, COLOR_PAIR(1) | A_BOLD);
  mvaddstr(2, 10, "Snake Game");
  mvaddstr(4, 10, "Press q to Quit game");
  wattroff(stdscr, COLOR_PAIR(1) | A_BOLD);
  box(stdscr, 0, 0);
  refresh();
  Snake *snake = createSnake(length);
  WINDOW *minWindow =
      newwin(term_height - 10, term_width - 20, WINDOW_Y, WINDOW_X);
  getmaxyx(minWindow, min_window_height, min_window_width);
  Frog *frog = createFrog(min_window_height, min_window_width);
  box(minWindow, 0, 0);
  wrefresh(minWindow);
  timeout(DELAY);
  while (quit) {
    werase(minWindow);
    mvwprintw(stdscr, 2, 100, "Score: %d", score);
    wattron(minWindow, COLOR_PAIR(1) | A_BOLD);
    drawSnake(snake, minWindow);
    wattroff(minWindow, COLOR_PAIR(1) | A_BOLD);
    wattron(minWindow, COLOR_PAIR(2) | A_BOLD);
    drawFrog(frog, minWindow);
    wattroff(minWindow, COLOR_PAIR(2) | A_BOLD);
    box(minWindow, 0, 0);
    wrefresh(minWindow);
    input = getch();
    if (input == 'q') {
      quit = 0;
    }
    switch (input) {
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
    if (snake->x >= frog->x && snake->x < frog->x + frogWidth &&
        snake->y == frog->y) {
      score += 1;
      spawnFrog(frog, min_window_height, min_window_width);
      growSnake(snake);
    }
    // snake->x < 3 left side
    // snake->y < 2 up side
    // snake->y >= min_window_height-2 -> down side
    // snake->x >= min_window_weidth-3->right_size
    if (snake->x < 2 || snake->y < 1 || snake->x >= min_window_width - 2 ||
        snake->y >= min_window_height - 1) {
      int go_y = min_window_height / 2;
      int go_x = (min_window_width - 9) / 2;
      mvwaddstr(minWindow, go_y, go_x, "GAME OVER");
      box(minWindow, 0, 0);
      wrefresh(minWindow);
    int flage = 1;
      while (flage) {

      }
      break;
    }
    moveSnake(snake, dx, dy);
  }
  endwin();
}
