#include <stdlib.h>
#include <stdio.h>
#include "item.h"
#include "tree.h"
#include <time.h>
#define SIZE 20

int main(){
  srand(time(NULL));
  size_t i;

  treeInit();

  for (i = 0; i < SIZE; i++){
    treeInsertNode(rand()%49+1);
  }

  inOrder(&root);
  puts("");

}
