#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct carta {
  const char *valore;
  const char *seme;
};

typedef struct carta Carta;

void creaMazzo(Carta * const wMazzo, const char * wSemi[], const char * wValori[]);
void mischia(Carta * const wMmazzo);
void servi(const Carta * const wMazzo);

int main(void){
  Carta mazzo[52];
  const char *valori[] = {"Asso", "Due", "Tre", "Quattro", "Cinque", "Sei", "Sette", "Otto", "Nove", "Dieci", "Jack",
                          "Regina", "Re"};
  const char *semi[] = {"Cuori", "Quadri", "Picche", "Fiori"};

  srand(time(NULL));

  creaMazzo(mazzo, semi, valori);
  printf("Il mazzo appena creato e':\n");
  servi(mazzo);
  printf("Dopo averlo mischiato, il risultato e':\n");
  mischia(mazzo);
  servi(mazzo);

  return(0);
}

void creaMazzo(Carta * const wMazzo, const char * wSemi[], const char * wValori[]){
  size_t i;

  for (i = 0; i < 52; ++i){
    wMazzo[i].valore = wValori[i % 13];
    wMazzo[i].seme = wSemi[i / 13];
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
