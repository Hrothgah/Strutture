#include <stdio.h>
#include <stdlib.h>
struct listNode {
  char data; 
  struct listNode *nextPtr; 
}; 
typedef struct listNode ListNode; 
typedef ListNode *ListNodePtr; 

// prototypes
void insert( ListNodePtr *sPtr, char value );
char delete( ListNodePtr *sPtr, char value );
int isEmpty( ListNodePtr sPtr );
void printList( ListNodePtr currentPtr );
void printListBW( ListNodePtr currentPtr );
void instructions( void );

int main( void ) {
  ListNodePtr startPtr = NULL; 
  unsigned int choice; 
  char item; 
  instructions(); // display the menu
  printf( "%s", "? " ); scanf( "%u", &choice );
  while ( choice != 3 ) {
    switch ( choice ) {
      case 1:
      printf( "%s", "Enter a character: " );
      scanf( "\n%c", &item );
      insert( &startPtr, item ); 
      printList( startPtr );
      break;
      case 2:       
      if ( !isEmpty( startPtr ) ) {
        printf("%s", "Enter char to delete:");
        scanf( "\n%c", &item );
        if ( delete( &startPtr, item ) ) { 
          printf( "%c deleted.\n", item );
          printList( startPtr );
        } 
        else {
          printf( "%c not found.\n\n", item );
        } 
      } 
      else {
        puts( "List is empty.\n" );
      } 
      break;
      default:
      puts( "Invalid choice.\n" );
      instructions();
      break;
    } 
    printf( "%s", "? " ); scanf( "%u", &choice );
  } 
  printListBW(startPtr); puts("\n");
  puts( "End of run." );
}

void instructions( void ) {
  puts( "Enter your choice:\n"
  " 1 to insert an element\n"
  " 2 to delete an element\n"
  " 3 to end." );
}

void insert( ListNodePtr *sPtr, char value ) {
  ListNodePtr newPtr; 
  ListNodePtr previousPtr; 
  ListNodePtr currentPtr; 
  newPtr = malloc( sizeof( ListNode ) ); 
  if ( newPtr != NULL ) { 
    newPtr->data = value; 
    newPtr->nextPtr = NULL; 
    previousPtr = NULL;
    currentPtr = *sPtr;
    while ( currentPtr != NULL &&
            value > currentPtr->data ) {
      previousPtr = currentPtr; 
      currentPtr = currentPtr->nextPtr; 
    }
    // head insertion        
    if ( previousPtr == NULL ) {
      newPtr->nextPtr = *sPtr;
      *sPtr = newPtr;
    }
    else { // inner insertion
      previousPtr->nextPtr = newPtr;
      newPtr->nextPtr = currentPtr;
    } 
  } 
  else {
    printf(
     "%c not inserted. No memory.\n", value );
  } 
}

// delete a list element
char delete(ListNodePtr *sPtr, char value)
{ 
   // delete first node if a match is found
   if (value == (*sPtr)->data) { 
      ListNodePtr tempPtr = *sPtr; // hold onto node being removed
      *sPtr = (*sPtr)->nextPtr; // de-thread the node
      free(tempPtr); // free the de-threaded node
      return value;
   } 
   else { 
      ListNodePtr previousPtr = *sPtr;
      ListNodePtr currentPtr = (*sPtr)->nextPtr;

      // loop to find the correct location in the list
      while (currentPtr != NULL && currentPtr->data != value) { 
         previousPtr = currentPtr; // walk to ...  
         currentPtr = currentPtr->nextPtr; // ... next node  
      } 

      // delete node at currentPtr
      if (currentPtr != NULL) { 
         ListNodePtr tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         free(tempPtr);
         return value;
      } 
   } 

   return '\0';
} 

// return 1 if the list is empty, 0 otherwise
int isEmpty(ListNodePtr sPtr)
{ 
   return sPtr == NULL;
} 

// print the list
void printList(ListNodePtr currentPtr)
{ 
   // if list is empty
   if (isEmpty(currentPtr)) {
      puts("List is empty.\n");
   } 
   else { 
      puts("The list is:");

      // while not the end of the list
      while (currentPtr != NULL) { 
         printf("%c --> ", currentPtr->data);
         currentPtr = currentPtr->nextPtr;   
      } 

      puts("NULL\n");
   } 
} 


// print the list backwards
void printListBW(ListNodePtr currentPtr)
{ 
   // if list is empty
   if (!isEmpty(currentPtr))  { 
     printListBW(currentPtr->nextPtr);
     printf("%c --> ", currentPtr->data);
   } 
} 

