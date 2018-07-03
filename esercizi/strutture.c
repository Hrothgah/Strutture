#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

struct scatola {
  int intero;
  double virgola;
  struct scatola * puntaScatola;
  char * bomba;
};

typedef struct scatola Scatola;
typedef Scatola *ScatolaPtr;

int main(void){
  int a, b, c, d, e, i;

  char stringa[SIZE];

  srand(time(NULL));

  puts("Ora stampa l'array di supporto\n");
  for (size_t i = 0; i < SIZE; i++){
    stringa[i] = rand()%25 + 97;
    printf("%c ", stringa[i]);
  }

  puts("\n");


  // Scatola pippo = malloc(sizeof(Scatola));

  Scatola pippo;

  pippo.intero = 69;
  pippo.virgola = 6.9;
  pippo.puntaScatola = NULL;
  pippo.bomba = malloc(SIZE*sizeof(char));
  puts("Ora stampa il contenuto di pippo.bomba\n");
  for (i = 0; i < SIZE; i++){
    pippo.bomba[i] = stringa[i] + 1;
  }

  for (i = 0; i< SIZE; i++){
    printf("%c ", pippo.bomba[i]);
  }
  puts("\n");

  ScatolaPtr baudo = malloc(sizeof(Scatola));

  baudo->intero = 199;
  baudo->virgola = 19.9;

  pippo.puntaScatola = baudo;





  puts("\n");
}
