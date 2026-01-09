#include "snake.h"
#include <ncurses.h>
#include <stdlib.h>
struct Snake *createSnake(int length) {
  Snake *head = NULL;
  Snake *tail = NULL;
  for (int i = 0; i < length; i++) {
    Snake *node = malloc(sizeof(Snake));
    node->x = 10;
    node->y = 10 + i;
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
void moveSnake(Snake *head, int dx, int dy) {
  int prevX = head->x;
  int prevY = head->y;
  head->x += dx;
  head->y += dy;
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
void growSnake(Snake *head){
	while(head->next != NULL){
		head = head->next;
	}
	Snake *newNode = malloc(sizeof(Snake));
	newNode->x = head->x;
	newNode->y = head->y;
	newNode->next = NULL;
	head->next = newNode;
}
