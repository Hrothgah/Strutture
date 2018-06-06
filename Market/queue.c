#include "item.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct client {
  Item nome;
  Item servizio;
  Item uscita;
  struct client * nextClient;
};

typedef struct client Client;
typedef Client * ClientPtr;

static ClientPtr head;
static ClientPtr tail;

void queueInit(){
  head = tail = NULL;
  //puts("Ho inizializzato la coda");
}

int queueIsEmpty(){
  return head == NULL;
}

void queueEnqueue(int i, int numero, FILE * file){
  //puts("Entro in enqueue");
  ClientPtr cliente = malloc(sizeof(Client));
  //puts("puntatore allocato");
  cliente->nome = numero;
  cliente->servizio = rand()%3+1;
  cliente->uscita = 0;
  cliente->nextClient = NULL;
  fprintf(file,"E' arrivato il cliente %d.",cliente->nome);
  if (queueIsEmpty()){
    //puts("Entro nel ramo queue is empty");
    cliente->uscita = i + cliente->servizio;
    head = tail = cliente;
  } else {
    tail->nextClient = cliente;
    tail = cliente;
  }
}

void queueDequeue(int i, FILE * file){
  fprintf(file,"Ho servito il cliente %d.",head->nome);
  ClientPtr temp = head;
    if (head->nextClient == NULL){
      head = NULL;
      tail = NULL;
      free(temp);
      return;
    } else {
    head = head->nextClient;
    head->uscita = i + (head->servizio);
    free(temp);
    }
}

void printQueue(FILE * file){
  ClientPtr cur = head;
  fprintf(file,"Cassa -> ");
  while (cur != NULL) {
    fprintf(file,"%d -> ", cur->nome);
    cur = cur->nextClient;
  }
  fprintf(file,"FINE\n");
}

int countQueue(){
  ClientPtr cur = head;
  int coda = 0;
  while (cur != NULL){
    coda++;
    cur = cur->nextClient;
  }
  return coda;
}

int franco(int i){

  if (head != NULL){
  return head->uscita == i;
} else {
  return 0;
}
}
