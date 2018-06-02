#include <stdio.h>
#include <limits.h>
#define UNSIGNED_BIT CHAR_BIT * sizeof(unsigned int)

void displayBits(unsigned int value){
  unsigned int displayMask = 1 << UNSIGNED_BIT - 1;
  printf("%10u = ", value);

  for (unsigned int c = 1; c <= UNSIGNED_BIT; ++c){
    putchar(value & displayMask ? '1' : '0');
    value <<= 1;

    if (c % CHAR_BIT == 0){
      putchar(' ');
    }
  }
  putchar('\n');
}
