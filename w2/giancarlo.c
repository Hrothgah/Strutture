#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define SIZE 120

int main(void){
  int scelta;

  srand(time(NULL));

  printf("Ciao, mi chiamo Giancarlo.\n"
          "Cosa vuoi che faccia?\n"
          "Premi 1 per salutare\n"
          "Premi 2 per sflippare\n"
          "Premi 3 per raccontare una barzelletta\n"
          "Premi 4 per esclamazione generica\n"
          "Premi 5 per espressione random\n"
          "Premi 9 per uscire.\n");

  scanf("%d", &scelta);

while (scelta != 9){
  switch (scelta) {
    case 1:
      printf("Bella piccio'!");
      break;
    case 2:
      printf("*passa il dito tra le labbra* ... plop-plup");
      break;
    case 3:
      printf("");
      break;
    case 4:
      int n = random;
      break;
    case 5:
      printf("");
      break;
  }
}


}
