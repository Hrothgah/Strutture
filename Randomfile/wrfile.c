#include <stdio.h>

typedef struct clientData {
  unsigned int numeroConto;
  char cognome[25];
  char nome[25];
  double saldo;
} ClientData;

int main(){
  FILE * fp;

  char insert = 'i';
  int count = 0;

  if ((fp = fopen("conti.dat","rb+")) == NULL){
    if ((fp = fopen("conti.dat","wb+")) == NULL){
      puts("Impossibile leggere il file.\n");
      return (-1);
    }
  }

  ClientData cliente = {0, "", "", 0.0};
  puts("Inserisci il numero di conto (da 1 a 100, 0 per terminare): ");
  scanf("%u", &cliente.numeroConto);

  while (cliente.numeroConto != 0) {
    if (insert == 'i'){
      puts("Inserisci cognome, nome e saldo: ");
      fscanf(stdin,"%24s%24s%lf", cliente.cognome, cliente.nome, &cliente.saldo);
      count++;
    } else {
      cliente.cognome[0] = '\0';
      cliente.nome[0] = '\0';
      cliente.saldo = 0;
    }

    fseek(fp, (cliente.numeroConto - 1)*sizeof(ClientData), SEEK_SET);
    fwrite(&cliente, sizeof(ClientData), 1, fp);

    printf("Inseri numero di conto (i o d): ");
    scanf("%d%c", &cliente.numeroConto, &insert);
  }

  fseek(fp, 0, SEEK_END);
  int sz = ftell(fp) / sizeof(ClientData);
  ClientData vettore[sz];

  fseek(fp, 0, SEEK_SET);
  fread(vettore, sizeof(ClientData), sz, fp);

  for (int i = 0; i < sz; i++){
    printf("%-10s%-13s%f\n",vettore[i].cognome, vettore[i].nome, vettore[i].saldo);
  }

  fclose(fp);

}
