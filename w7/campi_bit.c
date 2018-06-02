#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct cartaBit {
  unsigned int valore : 4;
  unsigned int seme : 2;
  unsigned int colore : 1;
};


typedef struct cartaBit Carta;

void creaMazzo(Carta * const wMazzo);
void mischia(Carta * const wMmazzo);
void servi(const Carta * const wMazzo);

int main(void){
  Carta mazzo[104];
  const char *valori[] = {"Asso", "Due", "Tre", "Quattro", "Cinque", "Sei", "Sette", "Otto", "Nove", "Dieci", "Jack",
                          "Regina", "Re"};
  const char *semi[] = {"Cuori", "Quadri", "Picche", "Fiori"};

  srand(time(NULL));

  creaMazzo(mazzo);
  printf("Il mazzo appena creato e':\n");
  servi(mazzo);
  printf("Dopo averlo mischiato, il risultato e':\n");
  mischia(mazzo);
  servi(mazzo);

  return(0);
}

void creaMazzo(Carta * const wMazzo){
  for (size_t i = 0; i < 104; ++i){
    wMazzo[i].valore = i % (104 / 4);
    wMazzo[i].seme = i / (104 / 4);
    wMazzo[i].colore = i / (104 /2);
  }
}

void mischia(Carta * const wMazzo){
  size_t i;
  size_t j;
  Carta temp;

  for (i = 0; i < 52; ++i){
    j = rand() % 52;
    temp = wMazzo[i];

    wMazzo[i] = wMazzo[j];
    wMazzo[j] = temp;
  }
}

void servi(const Carta * const wMazzo){
  size_t i;
  for (i = 0; i < 52; i++){
    printf("%7s di %-6s%s", wMazzo[i].valore, wMazzo[i].seme, ((i + 1) % 4? " " : "\n"));
  }
  printf("\n");
}
