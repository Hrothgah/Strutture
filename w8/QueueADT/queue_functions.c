#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "item.h"

struct queue {
  int head;
  int tail;
  int N;
  int maxN;
  Item *s;
};

Q queueInit(int maxN) {
    Q coda = malloc(sizeof(Q));
    coda->s = malloc(maxN*sizeof(Item));
    coda->head = coda->tail = 0;
    coda->maxN = maxN;
    return coda;
}

int queueIsEmpty(Q coda){
  return coda->N == 0;
}

void queueEnqueue(Q coda, Item item) {
  if (coda->N < coda->maxN){
    coda->s[coda->tail] = item;
    coda->tail = (coda->tail + 1)%coda->maxN;
    coda->N++;
  } else {
    puts("Valore non inserito in coda. Queue overflow.\n");
  }
}

Item queueDequeue(Q coda){
  if (coda->N > 0) {
    Item valore = coda->s[coda->head];
    coda->head = (coda->head + 1) % coda->maxN;
    coda->N--;
    return valore;
  } else {
    puts("Valore non inserito in coda. Queue overflow.\n");
  }
  return NULLITEM;
}
