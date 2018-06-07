#include "item.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct treeNode {
  struct treeNode *left;
  Item value;
  struct treeNode *right;
} TreeNode;

typedef TreeNode * TreeNodePtr;

static TreeNodePtr root;

static void insertNode(TreeNodePtr *nodePtr, Item item);
static void printInOrder(TreeNodePtr nodePtr);
static void printPreOrder(TreeNodePtr nodePtr);
static void printPostOrder(TreeNodePtr nodePtr);

void treeInit(){
  root = NULL;
}

int treeIsEmpty(){
  return root == NULL;
}

void treeInsert(Item item){
  insertNode(&root, item);
}

static void insertNode(TreeNodePtr *nodePtr, Item item){
  if (*nodePtr == NULL){
    *nodePtr = malloc(sizeof(TreeNode));
    if (*nodePtr != NULL){
      (*nodePtr)->value = item;
      (*nodePtr)->left = NULL;
      (*nodePtr)->right = NULL;
    } else {
        puts("Impossibile inserire il valore, memoria esaurita.\n");
        return;
    }
  } else {
    if (item < (*nodePtr)->value){
      insertNode(&((*nodePtr)->left), item);
    } else if (item > (*nodePtr)->value){
      insertNode(&((*nodePtr)->right), item);
    } else {
      puts("Elemento già presente nell'albero.\n");
      return;
    }
  }
}

void inOrder(){
  if (!treeIsEmpty()){
    printInOrder(root);
  }
  puts("\n");
}

static void printInOrder(TreeNodePtr nodePtr){
  if (nodePtr != NULL){
    printInOrder(nodePtr->left);
    printf("%d -> ",nodePtr->value);
    printInOrder(nodePtr->right);
  }
}

void postOrder(){
  if (!treeIsEmpty()){
    printPostOrder(root);
  }
  puts("\n");
}

static void printPostOrder(TreeNodePtr nodePtr){
  if (nodePtr != NULL){
    printPostOrder(nodePtr->left);
    printPostOrder(nodePtr->right);
    printf("%d -> ",nodePtr->value);
  }

}

void preOrder(){
  if(!treeIsEmpty()){
    printPreOrder(root);
  }
  puts("\n");
}

static void printPreOrder(TreeNodePtr nodePtr){
  if (nodePtr != NULL){
    printf("%d -> ",nodePtr->value);
    printPreOrder(nodePtr->left);
    printPreOrder(nodePtr->right);
  }

}
