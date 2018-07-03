#include "item.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct listNode {
  Item lastName[50];
  struct listNode * next;
} ListNode;

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
  strcpy(nodo->lastName,item);
  nodo->next = NULL;
  if (listIsEmpty()){
    start = nodo;
  } else {
    ListNodePtr cur = start;
    if (strcmp(nodo->lastName,cur->lastName) < 0){
      nodo->next = cur;
      start = nodo;
    } else if (strcmp(nodo->lastName,cur->lastName) == 0){
      nodo->next = cur->next;
      cur->next = nodo;
    } else {
      while ((cur->next != NULL) && (strcmp((cur->next)->lastName, nodo->lastName) < 0)) {
          cur = cur->next;
      }
      nodo->next = cur->next;
      cur->next = nodo;
    }
    }
  }

  void printList(){
    if (!listIsEmpty()){
      ListNodePtr cur = start;
      while (cur != NULL){
        printf("%s\n",cur->lastName);
        cur = cur->next;
      }
    }
  }
