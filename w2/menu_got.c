#include <stdio.h>

void ned(int a);
void ygritte(int b);
void hodor(int c);
void giancarlo(int d);

int main(void) {
  void (*f[ 4 ])( int ) = { ned, ygritte, hodor, giancarlo };
  size_t choice;
  printf( "%s", "Scegli un personaggio: " );
  printf("0 per Ned Stark, 1 per Ygritte, 2 per Hodor, 9 per terminare\n");
  scanf( "%lu", &choice );
  while (choice < 9) {
    if (choice >= 0 && choice <= 3){
      (*f[ choice ])( choice );
      printf( "%s", "0 per Ned Stark, 1 per Ygritte, 2 per Hodor\n" );
      scanf( "%lu", &choice );
    } else {
      printf("Scelta non corretta.\n");
      printf( "%s", "Scegli un personaggio: " );
      printf("0 per Ned Stark, 1 per Ygritte, 2 per Hodor, 9 per terminare\n");
      scanf( "%lu", &choice );
    }

  }
  puts( "Tanto alla fine muoiono tutti ;-)\n" );
}

void ned( int a ) {
printf( "L'inverno sta arrivando!\n\n");
}
void ygritte( int b )
{
printf( "Non sai niente, John Snow!\n\n");
}
void hodor( int c )
{
printf( "Hodor!\n\n");
}
void giancarlo(int d){
  printf("Hai selezionato Giancarlo!\n");
  printf("La sua catchphrase è: ");
  printf("Piccio' bomba!\n\n");
}
