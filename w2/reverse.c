#include <stdio.h>
#define SIZE 80

void reverse( const char * const sPtr ); // prototype

int main( void ) {
  char sentence[ SIZE ]; 
  puts( "Enter a line of text:" );

  fgets( sentence, SIZE, stdin );
  puts( "\nThe line printed backward is:" );
  reverse( sentence );
  putchar('\n');
} 

void reverse( const char * const sPtr )
{
  if ( '\0' == sPtr[ 0 ] ) // base case
      return;
    else { // recursion step
      reverse( &sPtr[ 1 ] ); 
      putchar( sPtr[ 0 ] );
    }
} 
 
