#include <stdio.h>

typedef unsigned long long int ullint;

unsigned long long int fibonacci(unsigned int n,
                                 ullint a,
                                 ullint b);

int main(void){
  unsigned int number;

  printf("%s", "immetti un intero: ");
  scanf("%u", &number);

  unsigned long long int result = fibonacci(number, 0, 1);

  printf("Fibonacci(%u) = %llu\n", number, result);
  
}

unsigned long long int fibonacci(unsigned int n, ullint a, ullint b){
  if (n == 0) return a;
  if (n == 1) return b;
  return fibonacci(n - 1, b, a + b);
}

