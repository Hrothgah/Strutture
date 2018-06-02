#include <stdlib.h>
#include <stdio.h>

void pot(int n, int e);
int reqVal(void);
int b, p;

int main(void){
  reqVal();
  pot(b,p);

}

int reqVal(void){
  printf("Ciao.\n"
          "Immetti la base: ");
  scanf("%d",&b);

  printf("\nCiao di nuovo.\n"
          "Immetti l'esponente: ");
  scanf("%d", &p);
  printf("\n");

  return b, p;
}

void pot(int n, int e){
  int i, t = n;
  printf("La potenza di %d elevato 0 e' 1\n", n);
  printf("La potenza di %d elevato 1 e' %d\n", n, n);

  for (i = 2; i <= e; i++){
    t = t * n;
    printf("La potenza di %d elevato %d e' %d\n", n, i, t);
  }
}
