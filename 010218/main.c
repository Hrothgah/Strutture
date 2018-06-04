#include <stdlib.h>
#include <stdio.h>

struct nodo {
  unsigned int value;
  struct nodo * next;
  struct nodo * last;
};

typedef struct nodo Nodo;
typedef Nodo * NodoPtr;
NodoPtr start;

void initList();
int listIsEmmpty();
void insList(unsigned int item);
unsigned int remList(unsigned int item);
void printList();
void istruzioni();

int scelta = 0;

int main(){
  unsigned int a = 0;

istruzioni();

  while (scelta != 3){
    switch(scelta) {
      case 1:
        puts("Digita il numero da inserire:");
        scanf("%u",&a);
        insList(a);
        istruzioni();
        break;
      case 2:
        printList();
        istruzioni();
        break;
    }
  }

  return 0;
}


void istruzioni(){
  unsigned int a;
  puts("Digita:\n"
        "1 per inserire un valore\n"
        "2 per stampare la lista\n"
        "3 per terminare il programma.\n");
  scanf("%d",&scelta);
}

void initList(){
  start = NULL;
}

int listIsEmmpty(){
  return start == NULL;
}

void insList(unsigned int a){
  if (start == NULL){
    NodoPtr nodo = malloc(sizeof(Nodo));
    NodoPtr ultimo = malloc(sizeof(Nodo));
    nodo->value = a;
    printf("il valore della root e': %u\n", nodo->value);
    nodo->next = ultimo;
    nodo->last = ultimo;
    ultimo-> value = a;
    printf("Il valore dell'ultimo e': %u\n", ultimo->value);
    ultimo->next = NULL;
    ultimo->last = NULL;
    start = nodo;
  } else {
    NodoPtr cur = start;
    while(cur->next != cur->last){
      cur = cur->next;
    }
    NodoPtr temp = malloc(sizeof(Nodo));
    temp->value = a;
    temp->last = cur->next;
    temp->next = cur->next;
    cur->next = temp;
    (cur->last)->value += a;
  }
}

void printList(){
  NodoPtr cur = start;
  while (cur != NULL){
    printf("%d -> ", cur->value);
    cur = cur->next;
  }
  printf("NULL");
  puts("\n");
}
