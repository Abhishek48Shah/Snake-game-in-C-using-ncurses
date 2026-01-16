#include "exitMenu.h"
#include <ncurses.h>
#define WINDOW_X 70
#define WINDOW_Y 16
WINDOW *drawExitMenu(int height, int width) {
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  WINDOW *menuWindow = newwin(height - 30, width - 150, WINDOW_Y, WINDOW_X);
  wbkgd(menuWindow, COLOR_PAIR(1) | A_BOLD);
  mvwaddstr(menuWindow, 2, 25, "Press key");
  mvwaddstr(menuWindow, 5, 25, "Save Game?");
  mvwaddstr(menuWindow, 9, 15, "Yes \t\t\t \'y\'");
  mvwaddstr(menuWindow, 13, 15, "No \t\t\t \'n\'");
  box(menuWindow, 0, 0);
  wrefresh(menuWindow);
  return menuWindow;
}
