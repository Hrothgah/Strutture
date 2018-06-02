#include <stdlib.h>
#include <stdio.h>

struct stackNode {
  int data;
  struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

//Prototipi
void push(StackNodePtr *topPtr, int info);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void instructions(void);

int main(void){
  StackNodePtr stackPtr = NULL;
  int value;

  instructions();
  printf("%s", "? ");
  unsigned int choice;
  scanf("%u", &choice);
  while (choice != 3){
    switch (choice){
      case 1:
        printf("%s","Enter integer: ");
        scanf("%d", &value);
        push(&stackPtr, value);
        printStack(stackPtr);
        break;
      case 2:
        if (!isEmpty(stackPtr)){
          printf("The popped value is %d.\n",pop(&stackPtr));
        }
        printStack(stackPtr);
        break;
      default:
        puts("Invalid choice.\n");
        instructions();
        break;
    }
    printf("%s", "? ");
    scanf("%u", &choice);
  }
  puts("End of run.");
}

void instructions(void){
  puts("Enter choice:\n"
        "1 to push a value on the stack\n"
        "2 to pop a value off the stack\n"
        "3 to end program");
}

void printStack(StackNodePtr currentPtr){
  StackNodePtr pp = currentPtr;
  while (pp != NULL){
    printf(" -> %d",pp->data);
    pp = pp->nextPtr;
  }
  printf("\n");
}

int isEmpty(StackNodePtr topPtr){
  return topPtr == NULL;
}

void push(StackNodePtr *topPtr, int info){
  StackNodePtr newPtr = malloc(sizeof(StackNode));

  if (newPtr != NULL){
    newPtr->data = info;
    newPtr->nextPtr = *topPtr;
    *topPtr = newPtr;
  } else {
    printf("%d not pushed. No memory.\n", info);
  }
}

int pop(StackNodePtr *topPtr){
  StackNodePtr tempPtr = *topPtr;
  int popValue = (*topPtr)->data;
  *topPtr = (*topPtr)->nextPtr;
  free(tempPtr);
  return popValue;
}
