#include <stdlib.h>
#include <stdio.h>
#define MAX 50

unsigned long int fibonacci(unsigned int n);

static int dpTable[MAX];

int main(void){
  unsigned int number;

  printf("unsigned long int is %lu bytes long\n", sizeof(unsigned long int));
  // printf("maximum is %lu \n", ULONG_MAX);

  printf("%s", "Immetti un intero: \n");
  scanf("%u", &number);

  unsigned long long int result = fibonacci(number);

  printf("Fibonacci(%u) = %lu\n", number, result);

}

unsigned long int fibonacci(unsigned int n){
  /*if (n >= MAX){
    return ULONG_MAX;
    }*/

  if (n == 0 || n == 1){
    return n;
  }

  if (dpTable[n] == 0){
    dpTable[n] = fibonacci(n-1) + fibonacci(n-2);
  }

  return dpTable[n];
}
