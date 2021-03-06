#include <stdio.h>
#include <time.h>

unsigned long long int fibonacci(unsigned int n);

int main(void){
  puts("Sequential calls to fibonacci(50) and fibonacci(49)");

  time_t startTime1 = time(NULL);
  puts("Calculating fibonacci(50)");
  unsigned long long int result1 = fibonacci(50);
  time_t endTime1 = time(NULL);
  printf("Fibonacci(%u) = %llu\n", 50, result1);
  printf("Calculation time = %f minutes\n\n",
         difftime(endTime1, startTime1) / 60.0);

  time_t startTime2 = time(NULL);
  puts("Calculating fibonacci(49)");
  unsigned long long int result2 = fibonacci(49);
  time_t endTime2 = time(NULL);
  printf("Fibonacci(%u) = %llu\n", 49, result2);
  printf("Calculation time = %f minutes\n\n",
         difftime(endTime2, startTime2) / 60.0);
  printf("Total calculation time = %f minutes\n\n",
         difftime(endTime2, startTime1) / 60.0);
}

unsigned long long int fibonacci(unsigned int n){
  if (n == 0 || n == 1)
    return n;
  else return fibonacci(n - 1) + fibonacci(n - 2);
}
