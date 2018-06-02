#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "item.h"

struct queueNode {
  Item item;
  struct queueNode *next;
};

typedef struct queueNode QueueNode;
typedef QueueNode * QueueNodePtr;

static QueueNodePtr head, tail;

void queueInit() {
  head = NULL;
}

int queueIsEmpty(void) {
  return head == NULL;
}

void queueEnqueue(Item item) {
  QueueNodePtr x = malloc(sizeof *x);
  if (x != NULL){
    x->item = item;
    x->next = NULL;
    if (queueIsEmpty()){
      head = tail = x;
    } else {
      tail->next = x;
      tail = tail->next;
    }
  } else {
    puts("Not enqueued. No memory.\n");
  }
}

Item queueDequeue() {
  if (head != NULL){
    Item value;
    QueueNodePtr temp;
    value = head->item;
    temp = head;
    head = head->next;
    if (queueIsEmpty()){
      tail = NULL;
    }
    free(temp);
    return value;
  } else {
    puts("Not dequeued. Queue underflow.\n");
  }
  return NULLITEM;
}
