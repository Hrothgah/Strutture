#include <stdlib.h>
#include <stdio.h>
#include "item.h"
#include <time.h>
#include "list.h"
#define SIZE 20

void istruzioni();

int scelta;

int main(){
  srand(time(NULL));
  Item temp;

  istruzioni();

  while (scelta != 4){
    switch (scelta) {
      case 1:
        puts("Digita l'elemento da inserire: ");
        scanf("%d",&temp);
        listIns(temp);
        listPrint();
        puts("\n");
        istruzioni();
        break;
      case 2:
        puts("Digita l'elemento da rimuovere: ");
        scanf("%d",&temp);
        listRem(temp);
        listPrint();
        puts("\n");
        istruzioni();
        break;
      case 3:
        puts("La lista attualmente e':");
        listPrint();
        puts("La lista ordinata e':");
        //merge();
        listPrint();
        puts("\n");
        istruzioni();
        break;
      case 4:
        return 0;
        break;
    }
  }


  for (size_t i = 0; i < SIZE; i++){
    temp = rand()%50 + 1;
    listIns(temp);
  }

  listPrint();

  //merge();

  puts("La lista ordinata e': ");
  listPrint();
  puts("\n");

}

void istruzioni(){
  puts("Digita 1 per inserire un elemento, 2 per rimuovere un elemento, 3 per ordinare la lista, 4 per terminare: ");
  scanf("%d", &scelta);
}
