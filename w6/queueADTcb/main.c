#include <stdio.h>
#include <string.h>
#include "item.h"
#include "queue.h"

void instructions(void);

int main(void){
  queueInit();
  int value;

  instructions();
  printf("%s","? ");
  unsigned int choice;
  scanf("%u", &choice);

  while (choice != 3){
    switch (choice) {
      case 1:
        printf("%s", "Inserisci un intero: ");
        scanf("%d", &value);
        queueEnqueue(value);
        break;
      case 2:
        if (!queueIsEmpty()){
          printf("Dequeued value is %d.\n", queueDequeue());
        }
        break;
      default:
        puts("Scelta non valida.\n");
        instructions();
        break;
    ;}
    printf("%s", "? ");
    scanf("%u", &choice);
  }
  puts("End of run.");
}

void instructions(void){
  puts("Enter choice:\n"
        "1 to put a value in the queue\n"
        "2 to get a value off the queue\n"
        "3 to end program");
}
