#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "item.h"
#include "albero.h"
#define SIZE 20

int main(void){
  treeInit();

  srand(time(NULL));
  puts("I numeri immessi nell'albero sono: ");

  for (unsigned int i = 1; i <= SIZE; ++i){
    Item item = rand() % 98 + 1;
    printf("%3d", item);
    treeInsertNode(item);
  }

  puts("\n\nL'attraversamento inOrder e':");
  treeInOrder();

  puts("\n\nL'attraversamento preOrder e':");
  treePreOrder();

  puts("\n\nL'attraversamento postOrder e':");
  treePostOrder();

  puts("\n");

  puts("Stampo l'albero in orizzontale");
  stampaAlbero();
  puts("\n");

  puts("Stampo l'albero per livelli:");
  stampaLivelli();
  puts("\n");
}
