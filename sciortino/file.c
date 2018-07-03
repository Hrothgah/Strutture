#include <stdlib.h>
#include <stdio.h>

typedef struct listNode {
  int value;
  struct listNode * next;
} ListNode;

typedef ListNode * ListNodePtr;

ListNodePtr start;

void listInit();
int listIsEmpty();
void listInsert(int number);
void printList();
int funzione(ListNodePtr nodePtr, int soglia);

int main(){
  FILE * fp;
  int appoggio;
  int soglia;

  fp = fopen("numeri.txt","r");

  if (fp != NULL){
    listInit();
    while(!feof(fp)){
      fscanf(fp,"%d",&appoggio);
      listInsert(appoggio);
    }
  } else {
    printf("File non trovato.\n");
    return 0;
  }

  printf("La lista creata e': \n");
  printList();

  printf("Inserisci la soglia minima per la somma:\n");
  scanf("%d",&soglia);

  printf("La somma dei numeri maggiori di %d e': %d.\n",soglia,funzione(start,soglia));

  printf("\n");

  return 0;

} //end of main


void listInit(){
  start == NULL;
}

int listIsEmpty(){
  return start == NULL;
}

void listInsert(int numero){
  ListNodePtr nodo = malloc(sizeof(ListNode));
  nodo->value = numero;

  if (listIsEmpty()){
  nodo->next = NULL;
  start = nodo;
  } else {
    nodo->next = start;
    start = nodo;
  }
}

void printList(){
  if (!listIsEmpty()){
    ListNodePtr cur = start;
    while(cur != NULL){
      printf("%d -> ",cur->value);
      cur = cur->next;
    }
    printf("NULL\n");
  } else {
    printf("La lista e' vuota.\n");
  }
}

int funzione(ListNodePtr nodePtr, int soglia){
  int somma = 0;
  ListNodePtr cur = nodePtr;
  while(cur != NULL){
    if(cur->value > soglia){  
      somma += cur->value;
    }
    cur = cur->next;
  }
  return somma;
}
