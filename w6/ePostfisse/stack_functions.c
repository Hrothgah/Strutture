#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "item.h"

struct stackNode {
    Item item;
    struct stackNode *next;
};

typedef struct stackNode StackNode;
typedef StackNode * StackNodePtr;

static StackNodePtr top;

void stackInit(){
  top = NULL;
}

int stackIsEmpty(void){
  return eq(top, NULL);
}

void stackPush(Item item){
  StackNodePtr x = malloc(sizeof *x);
  if (x != NULL){
    x->item = item;
    x->next = top;
    top = x;
  } else {
    puts("Valore non inserito. Memoria esaurita\n");
  }
}

Item stackPop(){
  if (top != NULL){
    StackNodePtr t = top;
    Item item = top->item;
    top = top->next;
    free(t);
    return item;
  } else {
    puts("Valore non estratto. Stack underflow.\n");
  }
  return NULLITEM;
}
