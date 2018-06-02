#include <stdio.h>
#include <stdlib.h>

int ladro(int portata, int peso[], int valore[], int q);
int max(int a, int b);

int main(void){
  int peso[4] = {1,1,2,3};
  int valore[4] = {1,1,3,3};
  int portata = 5;
  int q = 4;

  printf("Il massimo valore del furto è: %d\n",ladro(portata, peso, valore, q));
  return 0;

}

int max(int a, int b){
  if(a > b){
    return a;
  } else {
    return b;
  }
}

int ladro(int portata, int peso[], int valore[], int q){
  if (q == 0 || portata == 0){
    return 0;
  }

  if (peso[q-1] > portata){
    return ladro(portata, peso, valore, q-1);
  } else {
    return max((valore[q-1] + ladro(portata-peso[q-1], peso, valore, q-1)),ladro(portata, peso, valore, q-1));
  }

}
