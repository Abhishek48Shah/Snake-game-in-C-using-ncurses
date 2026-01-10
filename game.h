#ifndef GAME_H
#define GAME_H
#include <ncurses.h>
#include "snake.h"
#include "gameState.h"
WINDOW *drawGame(int height,int width,int dx,int dy,GameState *game);
#endif
