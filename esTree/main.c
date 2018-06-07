#include "item.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(){
  srand(time(NULL));
  int scelta, valore, inserisci = 1;





  do {
    printf("Digita: \n"
           "1 per inserire un valore\n"
           "2 per stampare inOrder\n"
           "3 per stampare postOrder\n"
           "4 per stampare preOrder\n"
           "5 per terminare il programma\n");
    scanf("%d", &scelta);

    switch(scelta){
      case 1:
        while(inserisci){
          printf("Digita il valore da inserire: ");
          scanf("%d", &valore);
          treeInsert(valore);
          puts("Digita 1 per inserire un nuovo valore, 0 per tornare al menu.");
          scanf("%d", &inserisci);
        }
        break;
      case 2:
        puts("L'attraversamento In-Order dell'albero e': ");
        inOrder();
        puts("\n");
        break;
      case 3:
        puts("L'attraversamento Post-Order dell'albero e': ");
        postOrder();
        puts("\n");
        break;
      case 4:
        puts("L'attraversamento Pre-Order dell'albero e': ");
        preOrder();
        puts("\n");
        break;
    }
  } while (scelta != 5);

  printf("Arrivedorci!\n");

  return 0;
}
