#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

typedef struct listNode{
  int data;
  struct listNode * nextPtr;
} ListNode;

typedef ListNode * ListNodePtr;

void listInit();
int listIsEmpty();
void listInsert(int a);
int listRemove(int a);
void listPrint();
void mergeList();
void mergeSort(ListNodePtr * nodePtr);

ListNodePtr startPtr;

int main(){
  srand(time(NULL));
  int i;
  listInit();

  for (i = 0; i < SIZE; i++){
    listInsert((rand()%100 + 1));
  }

  puts("La lista non ordinata e' la seguente: ");
  listPrint();
  puts("\n");

  mergeList();

  puts("La lista ordinata invece e': ");
  listPrint();
  puts("\n");


} //End of main

void listInit(){
  startPtr = NULL;
}

int listIsEmpty(){
  return startPtr == NULL;
}

void listInsert(int a){
  ListNodePtr newPtr = malloc(sizeof(ListNode));
  newPtr->data = a;
  newPtr->nextPtr = NULL;
  if(listIsEmpty()){
    startPtr = newPtr;
  else{
    ListNodePtr currentPtr = startPtr;
    while(currentPtr->nextPtr != NULL){
      currentPtr = currentPtr->nextPtr;
    }
    currentPtr->nextPtr = newPtr;
    }
  }
}

int listRemove(int a){
  ListNodePtr tempPtr = startPtr;
  int temp;
  if(tempPtr->data == a){
    temp = tempPtr->data;
    startPtr = startPtr->nextPtr;
    free(tempPtr);
    return temp;
  }
  while((tempPtr->nextPtr!=NULL) && ((tempPtr->nextPtr)->data) != a){
      tempPtr = tempPtr->nextPtr;
    }
  if(tempPtr->nextPtr == NULL){
    printf("ERR.01 : ELEMENTO NON TROVATO. xd\n");
    return 0;
  }
  if((tempPtr->nextPtr)->data == a){
    temp = (tempPtr->nextPtr)->data;
    ListNodePtr superTemp = tempPtr->nextPtr;
    tempPtr->nextPtr = superTemp->nextPtr;
    free(superTemp);
    return temp;
  }
}

/*  listRemove Alternate version by Andrea
int listRemove(int a){
	ListNodePtr tempPtr = startPtr;
	int temp;
	if(tempPtr->data == a){
    temp = startPtr->data;
		startPtr  = startPtr->nextPtr;
		free(tempPtr);
		return temp;
	}


else if((tempPtr->nextPtr!=NULL){
 		if(((tempPtr->nextPtr)->data) == a){
		temp = (tempPtr->nextPtr)->data;
		free(tempPtr);
		return temp;
}
	else{
	printf("SUCA\n");
	return 0;
	}
}
}
*/

void listPrint(){
  ListNodePtr cur = start;
  while(cur != NULL){
    printf("%d--> ", cur->data);
    cur = cur->nextPtr;
  }
  puts("NULL");
}

void mergeList(){
  if(!listIsEmpty()){
  mergeSort(&startPtr);
  }
  else{
    printf("Errore, la lista e' vuota \n");
  }
}

void mergeSort(ListNodePtr * nodePtr){

  ListNodePtr a,b,c;

  c = *nodePtr;

  if((c == NULL) || (c->nextPtr) == NULL))
    return;
}
