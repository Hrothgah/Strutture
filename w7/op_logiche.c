#include <stdio.h>
#include <limits.h>
#define UNSIGNED_BIT CHAR_BIT * sizeof(unsigned int)

void displayBits(unsigned int value);

int main(){
  unsigned int number1 = 65535;
  unsigned int mask = 1;
  unsigned int setBits = 241;
  puts("Combinando");
  displayBits(number1);
  displayBits(mask);
  puts("usando l'AND bitwise \'&\' otteniamo ");
  displayBits(number1 & mask);
  puts("\n");

  number1 = 15;
  //unsigned int setBits = 241;
  puts("Combinando");
  displayBits(number1);
  displayBits(setBits);
  puts("usando l'OR inclusivo bitwise \'|\' otteniamo ");
  displayBits(number1 | setBits);
  puts("\n");

  puts("Combinando");
  displayBits(number1);
  displayBits(setBits);
  puts("usando l'OR esclusivo bitwise \'^\' otteniamo ");
  displayBits(number1 ^ setBits);
  puts("\n");

  number1 = 960;
  puts("\nIl risultato di uno shift a sinistra del numero ");
  displayBits(number1);
  puts("di 8 posizioni usando << e': ");
  displayBits(number1 << 8);

  puts("\nIl risultato di uno shift a destra del numero ");
  displayBits(number1);
  puts("di 8 posizioni usando >> e': ");
  displayBits(number1 >> 8);
}

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
