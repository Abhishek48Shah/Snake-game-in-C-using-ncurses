#include "snake.h"
#include "gameState.h"
#include <ncurses.h>
#include <stdlib.h>
struct Snake *createSnake(GameState *game) {
  Snake *head = NULL;
  Snake *tail = NULL;
  for (int i = 0; i < game->snakeLength; i++) {
    Snake *node = malloc(sizeof(Snake));
    node->x = game->snakeX;
    node->y = game->snakeY + i;
    node->next = NULL;
    if (head == NULL) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      tail = node;
    }
  }
  return head;
}
void drawSnake(struct Snake *head, WINDOW *window) {
  if (head == NULL) {
    return;
  }
  while (head) {
    mvwaddch(window, head->y, head->x, 'O');
    head = head->next;
  }
}
void moveSnake(GameState *game, int dx, int dy) {
  Snake *head = game->snake;
  int prevX = head->x;
  int prevY = head->y;
game->snakeX =  head->x += dx;
 game->snakeY = head->y += dy;
  Snake *current = head->next;
  while (current) {
    int tempX = current->x;
    int tempY = current->y;
    current->x = prevX;
    current->y = prevY;
    prevX = tempX;
    prevY = tempY;
    current = current->next;
  }
}
void growSnake(Snake *head) {
  while (head->next != NULL) {
    head = head->next;
  }
  Snake *newNode = malloc(sizeof(Snake));
  newNode->x = head->x;
  newNode->y = head->y;
  newNode->next = NULL;
  head->next = newNode;
}
void distorySnake(Snake **head) {
  if (!head || !*head)
    return;
  Snake *current = *head;
  while (current) {
    Snake *temp = current;
    current = current->next;
    free(temp);
  }
  head = NULL;
}
int checkSelfCollision(Snake *head) {
  int xHead = head->x;
  int yHead = head->y;
  Snake *current = head->next;
  while (current) {
    if (current->x == xHead && current->y == yHead) {
      return 1;
    }
    current = current->next;
  }
  return 0;
}
