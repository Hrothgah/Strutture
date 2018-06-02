#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "stack.h"

int main(int argc, char *argv[]){
  printf("%s \n", argv[0]);
  printf("%s \n", argv[1]);
  char *a = argv[1];
  int N = strlen(a);
  printf("la lunghezza della stringa e': %d\n", N);

  stackInit();

  for (int i = 0; i < N; i++){
    if (a[i] == '+'){
      stackPush(stackPop() + stackPop());
    }
    if (a[i] == '*'){
      stackPush(stackPop() * stackPop());
    }

    if ((a[i]>= '0') && (a[i]<= '9')){
      stackPush(0);
    }

    while ((a[i] >= '0') && (a[i] <= '9')){
      stackPush(10 * stackPop() + a[i++] - '0');
    }
  }
  printf("%d \n", stackPop());
}
