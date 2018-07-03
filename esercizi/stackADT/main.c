#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "stack.h"

int main(){
    char stringa[80];
    puts("Inserisci una parola:");
    gets(stringa);
    puts("");

    stackInit();

    for (size_t i = 0; stringa[i] != '\0'; i++){
      stackPush(stringa[i]);
    }

    puts("La tua parola al contrario è: ");

    while (!stackIsEmpty()){
      printf("%c",stackPop());
    }

    puts("\nFine.\n");


  return 0;
}
