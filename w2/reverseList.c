#include <stdio.h>
#include <stdlib.h>

struct Node {
    char c; 
    struct Node *next;
  };

void reverse( const struct Node * const sent ); // prototype

int main( void ) {
  struct Node *sentence;
  struct Node *current;
  struct Node *nw;
  
  puts( "Enter a line of text:" );
  sentence = malloc( sizeof( struct Node ) );
  current = sentence;
  while ( (current->c = getchar()) != EOF ) {
      nw = malloc( sizeof( struct Node ) );
      nw->next = NULL;
      current->next = nw;
      current = nw;
   }
  
  puts( "\nThe line printed backward is:" );
  reverse( sentence );
  putchar('\n');
} 

void reverse( const struct Node *const sent ) {
  if ( EOF == sent->c )
    return;
  else {
    reverse( sent->next );
    putchar( sent->c );
  }
}
