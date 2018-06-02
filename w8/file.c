#include <stdlib.h>
#include <stdio.h>

struct clientData {
  unsigned int numeroConto;
  char cognome[35];
  char nome[35];
  double saldo;
};

typedef struct clientData ClientData;

int main(void){
  FILE *cfPtr;
  char insert = 'i';
  int count = 0;
  if ((cfPtr = fopen("accounts.dat", "rb+")) == NULL){
    if ((cfPtr = fopen("accounts.dat", "wb+")) == NULL){
      puts("Non riesco ad aprire il file.");
      return (-1);
    }
  }

  struct clientData cliente = {0, "", "", 0.0};
  printf("%s", "Inserisci un numero di conto (da 1 a 100, 0 per terminare): ");
  scanf("%d", &cliente.numeroConto);

  while (cliente.numeroConto != 0){
    if (insert == 'i') {
      printf("%s","Inserisci cognome, nome e saldo: ");
      fscanf(stdin, "%14s%9s%lf", cliente.cognome, cliente.nome, &cliente.saldo);
      count++;
    } else {
      cliente.cognome[0] = '\0';
      cliente.nome[0] = '\0';
      cliente.saldo = 0;
    }

    fseek(cfPtr, (cliente.numeroConto - 1)*sizeof(struct clientData), SEEK_SET);

    fwrite(&cliente, sizeof(struct clientData), 1, cfPtr);

    printf("%s", "Inserisci il numero di conto (i o d): ");
    scanf("%d%c", &cliente.numeroConto, &insert);
  }

  fseek(cfPtr, 0, SEEK_END);
  int sz = ftell(cfPtr) / sizeof(struct clientData);
  ClientData vettore[sz];

  fseek(cfPtr, 0, SEEK_SET);
  fread(vettore, sizeof(struct clientData), sz, cfPtr);

  for (int i = 0; i < sz; i++){
    printf("%-10s%-13s%f \n", vettore[i].cognome, vettore[i].nome, vettore[i].saldo);

    fclose(cfPtr);
  }
}
