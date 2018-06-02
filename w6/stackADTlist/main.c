#include <stdio.h>
#include <string.h>
#include "item.h"
#include "stack.h"

void instructions(void);

int main(void){
  stackInit();
  // int value;

  instructions();
  printf("%s", "? ");
  unsigned int choice;
  scanf("%u", &choice);

  while (choice != 3){
    switch (choice){
      case 1:
        acquire();
        break;
      case 2:
        display();
        break;
      default:
        puts("Scelta non valida.\n");
        instructions();
        break;
    }
    printf("%s","? ");
    scanf("%u", &choice);
  }
  puts("Fine del programma.");
}

void instructions(void){
  puts("Inserisci una scelta:\n"
        "1 per inserire un valore nella pila\n"
        "2 per estrarre un valore dalla pila\n"
        "3 per terminare il programma");
}
