#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "queue.h"

#define TIME 720

int main(){
  //puts("Inizio l'esecuzione");
  srand(time(NULL));

  int numero = 1;

  int i, prossimo;

  prossimo = rand()%3+1;

  queueInit();

  for (i = 0; i < TIME; i++){
    printf(">%d :", i);

    if (franco(i)){
      printQueue();
      queueDequeue(i);
    }

    if (i == prossimo){
      queueEnqueue(i, numero);
      numero++;
      prossimo = prossimo + (rand()%3+1);
    }

    if ((i > 0) && ((i%10) == 0)){
      printQueue();
    }

    printf("\n");
  }

  printf("La coda alla fine dei %d minuti, e' lunga %d cliente/i.\n", TIME, countQueue());

}
