#include <stdio.h>
#include <time.h>

unsigned long long int fibonacci(unsigned int n);

int main(void){
  int primo, secondo;
  printf("primo = ");
  scanf("%d", &primo);

  printf("secondo = ");
  scanf("%d", &secondo);

  printf("Sequential call to fibonacci(%d) and fibonacci(%d) \n", primo, secondo);

  time_t startTime1 = time(NULL);
  puts("Calculating fibonacci(primo)");
  unsigned long long int result1 = fibonacci(primo);
  time_t endTime1 = time(NULL);
  printf("Fibonacci(%u) = %llu\n", primo, result1);
  printf("Calculation time = %f minutes\n\n", difftime(endTime1, startTime1)/* / 60.0*/);

  time_t startTime2 = time(NULL);
  puts("Calculating fibonacci(secondo)");
  unsigned long long int result2 = fibonacci(secondo);
  time_t endTime2 = time(NULL);
  printf("Fibonacci(%u) = %llu\n", secondo, result2);
  printf("Calculation time = %f minutes\n\n", difftime(endTime2, startTime2)/* / 60.0*/);
  printf("Total calculation time = %f minutes\n\n", difftime(endTime2, startTime1)/* /60.0*/);
}

unsigned long long int fibonacci(unsigned int n){
  if (n == 0 || n == 1){
    return n;
  } else {
    return fibonacci(n-1) + fibonacci(n-2);
  }
}
