#ifndef GAMESTATE_H
#define GAMESTATE_H
typedef enum { MENU, GAME, GAMEOVER,SAVE } Screen;
typedef struct Snake Snake;
typedef struct Frog Frog;
typedef struct {
  Screen currentLayout;
  int score;
  int snakeLength;
  int quit;
  int snakeX, snakeY;
  int frogX, frogY;
  Snake *snake;
  Frog *frog;
} GameState;
int checkGameState();
void saveGame(GameState *game);
void continueGame(GameState *game);
void setGameState(GameState *game, int flage);
void freeMemory(GameState *game);
void removePrevGame();
#endif
