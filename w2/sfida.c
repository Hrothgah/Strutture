#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
  long long unsigned int n;
  srand(time(NULL));

  time_t inizio = time(NULL);
  for (int i = 0; i <= 1000000; i++){
    n = i*2;
    printf("%llu\n",n);
  }
  time_t fine = time(NULL);

  printf("Tempo esecuzione = %f secondi\n\n", difftime(fine, inizio));

}
