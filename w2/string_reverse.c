#include <stdlib.h>
#include <stdio.h>
#define SIZE 80

void reverse(const char * const sPtr);

int main(void){
  char frase[SIZE];

  puts("Inserisci una frase:");

  fgets(frase, SIZE, stdin);
  puts("\nLa frase che hai inserito al contrario è:");
  reverse(frase);
  puts("\n");

}

void reverse(const char * const sPtr){
  if (sPtr[0] == '\0') {
    return;
  } else {
    reverse(&sPtr[1]);
    putchar(sPtr[0]);
  }

}
