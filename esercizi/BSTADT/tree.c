#include <stdlib.h>
#include <stdio.h>
#include "item.h"
#include "tree.h"
#include <time.h>

/*
struct treeNode {
  struct treeNode * left;
  Item id;
  Item saldo;
  struct treeNode * right;
};

typedef struct treeNode TreeNode;
typedef TreeNode * TreeNodePtr;

static TreeNodePtr root;
*/

void treeInit(){
  root = NULL;
}

int treeIsEmpty(){
  return root == NULL;
}

void treeInsertNode(Item id){
  insertNode(&root, id);
}

void insertNode(TreeNodePtr *nodePtr, Item id){

  if (*nodePtr == NULL){
     *nodePtr = malloc(sizeof(TreeNodePtr));
    (*nodePtr)->id = id;
    (*nodePtr)->saldo = rand()%100;
    (*nodePtr)->left = NULL;
    (*nodePtr)->right = NULL;
  } else {
    if (id < (*nodePtr)->id) {
      insertNode(&(*nodePtr)->left, id);
    }
    if (id > (*nodePtr)->id) {
      insertNode(&(*nodePtr)->right, id);
    }
    if (id == (*nodePtr)->id){
      return;
    }
  }
}

void inOrder(TreeNodePtr root){
  if (root != NULL){
    inOrder(root->left);
    printf("%d ", root->id);
    inOrder(root->right);
  }
}
