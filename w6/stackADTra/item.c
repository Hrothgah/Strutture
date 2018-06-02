#include <stdlib.h>
#include <stdio.h>
#include "item.h"
#include "stack.h"

void acquire(void){
  int value;
  printf("%s","Inserisci un intero: ");
  scanf("%d", &value);
  stackPush(value);
}

void display(void){
  if (!stackIsEmpty()){
    printf("Il valore estratto è %d\n", stackPop());
  }
}
