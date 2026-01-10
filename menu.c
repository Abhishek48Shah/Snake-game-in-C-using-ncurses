#include "menu.h"
#include <ncurses.h>
#define WINDOW_X 70
#define WINDOW_Y 16
WINDOW *drawMenu(int height, int width) {
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  WINDOW *menuWindow = newwin(height - 30, width - 150, WINDOW_Y, WINDOW_X);
  wbkgd(menuWindow, COLOR_PAIR(1) | A_BOLD);
  mvwaddstr(menuWindow, 2, 25, "Press key");
  mvwaddstr(menuWindow, 7, 15, "Game \t\t\t \'g\'");
  mvwaddstr(menuWindow, 9, 15, "Quit \t\t\t \'q\'");
  box(menuWindow, 0, 0);
  wrefresh(menuWindow);
  return menuWindow;
}
