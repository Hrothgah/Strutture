#include <stdlib.h>
#include <stdio.h>
#define SIZE 10

struct listNode {
  int data;
  struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

ListNodePtr merge(ListNodePtr const l1, ListNodePtr const l2);
void displayElement(ListNodePtr const startPtr);
void freeList(ListNodePtr startPtr);

int main(void){
  ListNodePtr cl1, cl2;
  ListNodePtr l1, l2;
  ListNodePtr result;

  cl1 = malloc(sizeof(ListNode));
  if (cl1 == NULL){
    return -1;
  }
  cl1->data = 0;
  cl1->nextPtr = NULL;
  l1 = cl1;
  cl2 = malloc(sizeof(ListNode));
  if (cl2 == NULL){
    return -1;
  }
  cl2->data = 1;
  cl2->nextPtr = NULL;
  l2 = cl2;

  for (size_t i = 2; i < SIZE; i+=2){
    if (cl1->nextPtr = malloc(sizeof(ListNode))){
      cl1 = cl1->nextPtr;
      cl1->data = i;
      cl1->nextPtr = NULL;
    }

    if (cl2->nextPtr = malloc(sizeof(ListNode))){
      cl2 = cl2->nextPtr;
      cl2->data = i+1;
      cl2->nextPtr = NULL;
    }
  }

  puts("First list:");
  displayElement(l1);
  puts("\n");
  puts("Second list:");
  displayElement(l2);
  puts("\n");
  result = merge(l1, l2);
  puts("Merged list:");
  displayElement(result);
  freeList(l1);
  freeList(l2);
  freeList(result);
}

ListNodePtr merge(ListNodePtr const l1, ListNodePtr const l2){
  ListNodePtr cl1, cl2, result, rc;
  cl1 = l1;
  cl2 = l2;
  if ((rc = malloc(sizeof(ListNode))) == NULL){
    return NULL;
  }
  rc->nextPtr = NULL;
  result = rc;
  while ((cl1 != NULL) && (cl2 != NULL)) {
    if ((cl1->data) <= (cl2->data)){
      rc->data = cl1->data;
      cl1 = cl1->nextPtr;
    } else {
      rc->data = cl2->data;
      cl2 = cl2->nextPtr;
    }

    if ((rc->nextPtr = malloc(sizeof(ListNode))) == NULL){
      freeList(result);
      return NULL;
    }
    rc = rc->nextPtr;
    rc->nextPtr = NULL;
  }
  if (cl1 == NULL){
    rc->data = cl2->data;
    while ((cl2 = cl2->nextPtr) != NULL){
      if ((rc->nextPtr = malloc(sizeof(ListNode))) == NULL){
        freeList(result);
        return NULL;
      }
      rc = rc->nextPtr;
      rc->data = cl2->data;
      rc->nextPtr = NULL;
    }
  } else {
    rc->data = cl1->data;
    while ((cl1 = cl1->nextPtr) != NULL){
      if ((rc->nextPtr = malloc(sizeof(ListNode))) == NULL){
        freeList(result);
        return NULL;
      }
      rc = rc->nextPtr;
      rc->data = cl1->data;
      rc->nextPtr = NULL;
    }
  }
  return result;
}

void displayElement(ListNodePtr const startPtr){
  ListNodePtr pp = startPtr;
  while (pp != NULL){
    printf(" ->%d", pp->data);
    pp = pp->nextPtr;
  }
  printf("\n");
}

void freeList(ListNodePtr startPtr){
  ListNodePtr pp = startPtr;
  ListNodePtr ppp;

  while (pp != NULL){
    ppp = pp->nextPtr;
    free(pp);
    pp = ppp;
  }
}
