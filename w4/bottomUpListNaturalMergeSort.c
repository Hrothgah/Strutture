#define SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

struct listNode {
  int data; 
  struct listNode *nextPtr; 
};

typedef struct listNode ListNode;
typedef ListNode * ListNodePtr;

// function prototypes 
void mergeSort(ListNodePtr *startPtr);
ListNodePtr merge(ListNodePtr const l1, ListNodePtr const l2);
void displayElements(ListNodePtr startPtr);
void freeList(ListNodePtr startPtr);

int main(void)
{
  ListNodePtr cl;
  ListNodePtr ptemp;

  cl = malloc(sizeof(ListNode));
  if (cl == NULL) return -1;
  cl->nextPtr = NULL;
  cl = cl;
  srand(time(NULL)); // seed the rand function 
  for (size_t i = 0; i < SIZE; i++) {
    // cl->data = i; //debug
    cl->data = rand() % 90 + 10; // give each element a value
    if ((ptemp = malloc(sizeof(ListNode)))==NULL)  break;
    ptemp->nextPtr = cl;
    cl = ptemp;
  }
  cl = ptemp->nextPtr;
  free(ptemp);
        
  puts("Unsorted list:");
  displayElements(cl); // print the list
  puts("\n");
  mergeSort(&cl); // merge sort the list 
  puts("Sorted list:");
  displayElements(cl); // print the list 
} 

// function that merge sorts the list 
void mergeSort(ListNodePtr *startPtr) {
  ListNodePtr p;
  int taglia = 0;
  int k, j, lim;

  // determina la taglia dell'array
  p = *startPtr;;
  while (p != NULL) {
    p = p->nextPtr;
    taglia += 1;
  }

  printf("taglia = %d\n", taglia);
  // prepara array di puntatori a lista
  ListNodePtr work[taglia];
  p = *startPtr;
  ListNodePtr prev;
  for ( k = 0; k < taglia; k++ ) { 
         work[k] = p; 
	 if (p != NULL){
	   do {
	     prev = p;
	     p = p->nextPtr; 
	   } while ((p != NULL) && (p->data) > (prev->data));
	   prev->nextPtr = NULL; 
	   displayElements(work[k]);
	 }
  } 
  work[k] = NULL;        

  for ( lim = taglia; lim > 1; lim = (lim+1)/2 ) { 
    for ( j = k = 0; k < lim; j++, k+=2 ) {
      work[j]= merge(work[k], work[k+1]);
      displayElements(work[j]);
    }
    work[j] = NULL; // extra null per casi dispari
  }
  *startPtr = work[0];
} 

// merge two sorted lists into a single sorted list
ListNodePtr merge(ListNodePtr const l1, ListNodePtr const l2) {
  ListNodePtr cl1, cl2;
  ListNodePtr result;
  ListNodePtr rc;

  if ((l1==NULL)&&(l2==NULL)) return NULL; 
  cl1 = l1; cl2 = l2;
  if ((rc = malloc(sizeof(ListNode))) == NULL) return NULL;
  rc->nextPtr = NULL;
  result = rc;
  while ((cl1 != NULL) && (cl2 != NULL)) {
    if ((cl1->data) <= (cl2->data)) {
      rc->data = cl1->data;
      cl1 = cl1->nextPtr;
    }
    else {
      rc->data = cl2->data;
      cl2 = cl2->nextPtr;
    }
    if ((rc->nextPtr = malloc(sizeof(ListNode))) == NULL) {
      freeList(result);
      return NULL;
    }
    rc = rc->nextPtr;
    rc->nextPtr = NULL;
  }
  if ((cl1 == NULL)&&(cl2 != NULL)) {
    rc->data = cl2->data;
    while ((cl2 = cl2->nextPtr) != NULL) {
      if ((rc->nextPtr = malloc(sizeof(ListNode))) == NULL) {
        freeList(result);
        return NULL;
      }
      rc = rc->nextPtr;
      rc->data = cl2->data;
      rc->nextPtr = NULL;
    }
  }
  else if ((cl2 == NULL)&&(cl1 != NULL))
  {
    rc->data = cl1->data;
    while ((cl1 = cl1->nextPtr) != NULL) {
      if ((rc->nextPtr = malloc(sizeof(ListNode))) == NULL) {
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

// display elements in list 
void displayElements(ListNodePtr const startPtr) {
  ListNodePtr pp = startPtr;
  while (pp != NULL) {
    printf(" -> %d", pp->data);
    pp = pp->nextPtr;
  }
  printf("\n");
} 

// free memory of a list 
void freeList(ListNodePtr const startPtr) {
  ListNodePtr pp = startPtr;
  ListNodePtr ppp;
  
  while (pp != NULL) {
    ppp = pp->nextPtr;
    free(pp);
    pp = ppp;
  }
} 

