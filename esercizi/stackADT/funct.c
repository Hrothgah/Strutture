#include "item.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct listNode {
  Item item;
  struct listNode * nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode * ListNodePtr;

static ListNodePtr start;

void stackInit(){
  start = NULL;
}

int stackIsEmpty(void){
  return eq(start, NULL);
}

void stackPush(Item item){
  ListNodePtr nodo = malloc(sizeof *nodo);
  if (nodo != NULL){
    nodo->item = item;
    nodo->nextPtr = start;
    start = nodo;
  }
}

Item stackPop(){
  if(start != NULL){
    Item prossimo;
    Item temporaneo = start->item;
    ListNodePtr temp = start;
    start = start->nextPtr;
    if (start != NULL){
      prossimo = start->item;
    }

    if (eq(prossimo, ' ')){
      printf("SPAZIO\n");
      free(temp);
      return toupper(temporaneo);
    }

    free(temp);
    return temporaneo;

}


}
