#include <stdlib.h>
#include <stdio.h>

int main(void){

int a = 8;

int *puntatore = &a;

int *punt_punt =&puntatore;

puts("Stampo il contenuto di puntatore");
printf("%p\n",puntatore);
puts("Stampo il contenuto della variabile puntata da puntatore");
printf("%d\n", *puntatore);
puts("Stampo l'indirizzo di memoria dove è salvato il contenuto del puntatore");
printf("%p\n",&puntatore);
puts("\n");
printf("%p\n",punt_punt);



}

