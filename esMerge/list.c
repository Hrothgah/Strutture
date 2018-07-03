#include "item.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct listNode {
  Item numero;
  struct listNode * next;
};

typedef struct listNode ListNode;
typedef ListNode * ListNodePtr;

static ListNodePtr start;

void listInit(){
  start = NULL;
}

int listIsEmpty(){
  return start == NULL;
}

void listIns(Item item){
  ListNodePtr nodo = malloc(sizeof(ListNode));
  nodo->numero = item;
  nodo->next = NULL;

  if (listIsEmpty()){
    start = nodo;

  } else {

    ListNodePtr curr = start;

    while (curr->next != NULL){
      curr = curr->next;
    }

    curr->next = nodo;
  }
}

void listPrint(){
  ListNodePtr curr = start;
  while (curr != NULL) {
    printf("%d -> ", curr->numero);
    curr = curr->next;
  }
  printf("NULL");
  puts("\n");
}

Item listRem(Item item){
  Item temp;
  ListNodePtr cur = start;
  while (cur != NULL) {
    if (cur->numero == item) {
      temp = cur->numero;
      start = cur->next;
      free(cur);
      return temp;
    } else {
      cur = cur->next;
    }
  }

  printf("Numero non trovato nella lista.\n");
  return temp;
}
