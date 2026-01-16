#include "gameState.h"
#include "frog.h"
#include "snake.h"
#include <stdio.h>
#include <string.h>
// To check previous game is saved or not
int checkGameState() {
  FILE *file;
  file = fopen("gameState.sav", "r");
  if (file == NULL) {
    return 0;
  }
  int ch = fgetc(file);
  if (ch == EOF) {
    return 0;
  }
  fclose(file);
  return 1;
}
// To save game in the file
void saveGame(GameState *game) {
  FILE *file;
  file = fopen("gameState.sav", "w");
  if (file == NULL) {
    return;
  }
  fprintf(file, "snakeLength=%d\n", game->snakeLength);
  fprintf(file, "score=%d\n", game->score);
  fprintf(file, "snakeX=%d\n", game->snakeX);
  fprintf(file, "snakeY=%d\n", game->snakeY);
  fprintf(file, "frogX=%d\n", game->frogX);
  fprintf(file, "frogY=%d\n", game->frogY);
  fclose(file);
}
// To read save game from the file
void continueGame(GameState *game) {
  FILE *file;
  char key[20];
  int value;
  file = fopen("gameState.sav", "r");
  if (file == NULL) {
    return;
  }
  // It reads the content from the file in key value pair
  while (fscanf(file, "%19[^=]=%d\n", key, &value) == 2) {
    if (strcmp(key, "snakeLength") == 0)
      game->snakeLength = value;
    if (strcmp(key, "score") == 0)
      game->score = value;
    if (strcmp(key, "snakeX") == 0)
      game->snakeX = value;
    if (strcmp(key, "snakeY") == 0)
      game->snakeY = value;
    if (strcmp(key, "frogX") == 0)
      game->frogX = value;
    if (strcmp(key, "frogY") == 0)
      game->frogY = value;
  }
  fclose(file);
}
void setGameState(GameState *game, int flag) {
  if (flag) {
    continueGame(game);
    game->snake = createSnake(game);
    game->frog = createFrog(game);
  } else {
    game->snake = createSnake(game);
    game->frog = createFrog(game);
  }
}
void freeMemory(GameState *game) {
  if (game->snake != NULL && game->frog != NULL) {
    distorySnake(&game->snake);
    distoryFrog(&game->frog);
  }
}
void removePrevGame(){
	FILE *file;
	file = fopen("gameState.sav","w");
	if(file == NULL){
		return;
	}
}
