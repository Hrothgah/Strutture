#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "item.h"

static Item *s;
static int N;
static int maxN = 2;
static int head, tail;

static void resize(int toN);

void queueInit() {
  s = malloc(maxN*sizeof(Item));
  head = tail = 0;
}

int queueIsEmpty(void) {
  return N == 0;
}

void queueEnqueue(Item item) {
  if (N >= maxN){
    resize(2*maxN);
    maxN = 2*maxN;
  }
  s[tail] = item;
  tail = (tail + 1)%maxN;
  N++;
}

Item queueDequeue() {
  if (N > 0){
    if ((N < maxN/8) && (maxN > 4)){
      resize(maxN/2);
      maxN = maxN/2;
    }
    Item value = s[head];
    head = (head + 1)%maxN;
    N--;
    return value;
  } else {
    puts("Non rimosso dalla coda. Queue underflow.\n");
  }
  return NULLITEM;
}

static void resize(int toN){
  Item *t = malloc(toN*sizeof(Item));
  for (int i = head, j = 0; (j <= N) && (j < toN); i = (i+1)%maxN, j++){
    t[j] = s[i];
  }
  free(s);
  s = t;
  head = 0;
  tail = N;
}
