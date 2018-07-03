#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define SIZE 10

typedef struct treeNode {
  struct treeNode * left;
  int value;
  struct treeNode * right;
} TreeNode;

typedef TreeNode * TreeNodePtr;

TipeNodePtr root;

void treeInit();
int treeIsEmpty();
void treeInsert(int a);
int treeDelete(int a);
void printTree();
TreeNodePtr findMin(TreeNodePtr nodePtr);

int main() {
  int i;
  int numero;
  srand(time(NULL));

  treeInit();

  for (i = 0; i < SIZE; i++){
    treeInsert(&root,(rand()%49 + 1));
  }

  printTree(root);

  printf("Digita il numero che vuoi eliminare:");
  scanf("%d",&numero);

  treeDelete(numero);

  puts("L'albero ora e':");
  printTree();
  puts("\n");

}// end of main

void treeInit(){
  start = NULL;
}

int treeIsEmpty(){
  return start == NULL;
}

void treeInsert(TreeNodePtr *nodePtr, int a){
  if (*nodePtr->value == a){
    printf("Valore gia' esistente.\n");
    return;
  } else if (a < (*nodePtr)->value){
      treeInsert(&((*nodePtr)->left), a)
    } else if (a > (*nodePtr)->value){
      treeInsert(&((*nodePtr)->right), a)
    } else {
      (*nodePtr) = malloc(sizeof(TreeNode));
      (*nodePtr)->value = a;
      (*nodePtr)->left = NULL;
      (*nodePtr)->right = NULL;
    }
  }


TreeNodePtr findMin(TreeNodePtr nodePtr){
  if (nodePtr->left == NULL){
    return nodePrt;
  } else {
    findMin(nodePtr->left);
  }
}

int treeDelete(TreeNodePtr nodePtr, int a){
    if (nodePtr == NULL){
      printf("Lista vuota\n");
      return 0;
    } else {
      if (nodePtr->value < )
    }
}

void printTree(TreeNodePtr nodePtr){
  if (!treeIsEmpty()){
    printTree(nodePtr->left);
    printf("%d ", nodePtr->value);
    printTree(nodePtr->right);
  } else {
    printf("L'albero e' vuoto.\n");
  }

}
