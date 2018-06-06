#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "queue.h"

#define TIME 720

int main(){
  //puts("Inizio l'esecuzione");
  srand(time(NULL));
  char scelta;

  FILE * fp;

  fp = fopen("log.txt","w");

  if (fp == NULL){
    printf("Non ho potuto aprire il file di log, continuo lo stesso? (S/N):");
    scanf("%c",&scelta);
    if ((scelta == 'n') || (scelta == 'N')){
      return 1;
    }
  }

  int numero = 1;

  int i, prossimo, ora, minuto;

  prossimo = rand()%3+1;

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  fprintf(fp, "Data: %d-%d-%d Ore: %d:%d:%d\n", tm.tm_mday, tm.tm_mon + 1,
   tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
   ora = tm.tm_hour;
   minuto = tm.tm_min;

  queueInit();

  for (i = 0; i < TIME; i++){
    fprintf(fp, ">%d :", i);

    if (franco(i)){
      queueDequeue(i, fp);
    }

    if (i == prossimo){
      queueEnqueue(i, numero, fp);
      numero++;
      prossimo = prossimo + (rand()%3+1);
    }

    if ((i > 0) && ((i%10) == 0)){
      printQueue(fp);
    }

    fprintf(fp,"\n");
  }

  printf("La coda alla fine dei %d minuti, e' lunga %d cliente/i.\n", TIME, countQueue());
  fprintf(fp,"La coda alla fine dei %d minuti, e' lunga %d cliente/i.\n", TIME, countQueue());
  fclose(fp);

}
