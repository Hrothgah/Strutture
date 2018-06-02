#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "item.h"
#include <time.h>

static Item *s;
static int N;
static int maxN = 2;

static void resize(int toN);

void stackInit(){
  s = malloc(maxN*sizeof(Item));
}

int stackIsEmpty(void){
  return N == 0;
}

void stackPush(Item item){
  if (N >= maxN){
    resize(maxN=2*maxN);
  }
  s[N++] = item;
  for (size_t i = 0; i < N; i++ ){
    printf("%d",s[i]);
    if (i != N-1){
      printf(" - ");
    }
  }
  printf("\n");
}

Item stackPop(){
  if (N > 0){
    if ((N < maxN/4) && (maxN > 4)){
      resize(maxN = maxN/2);
    }
    for (size_t i = 0; i < N-1; i++ ){
      printf("%d",s[i]);
      if (i != N-2){
        printf(" - ");
      }
    }
    printf(" \n");
    return s[--N];
  } else {
    puts("Valore non estratto. Stack underflow.\n");
  }
  return NULLITEM;
}

static void resize(int toN){
  printf("nuova dimensione: %d\n", toN);
  s = realloc(s, toN*sizeof(Item));
}
