#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "item.h"

struct treeNode {
  struct treeNode *left;
  Item item;
  struct treeNode *right;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

static TreeNodePtr rootPtr;

struct queueNode {
  TreeNodePtr node;
  struct queueNode *next;
};

typedef struct queueNode QueueNode;
typedef QueueNode * QueueNodePtr;

static QueueNodePtr head, tail;

static void insertNode(TreeNodePtr *, Item);

void stampaAlbero(void);

int level = 0;

void treeInit(void){
  rootPtr = NULL;
}

int treeIsEmpty(void){
  return rootPtr == NULL;
}

void treeInsertNode(Item item){
  insertNode(&rootPtr, item);
}

static void insertNode(TreeNodePtr *treePtr, Item item){
  if (*treePtr == NULL){
    *treePtr = malloc(sizeof(TreeNode));
    if (*treePtr != NULL){
      (*treePtr)->item = item;
      (*treePtr)->left = NULL;
      (*treePtr)->right = NULL;
    } else {
      printf("Impossibile eseguire l'operazione, memoria esaurita.\n");
    }
  } else {
    if (item < (*treePtr)->item){
      insertNode(&((*treePtr)->left), item);
    } else if (item > (*treePtr)->item){
      insertNode(&((*treePtr)->right), item);
    } else {
      printf("%s ", "dup");
    }
  }
}


static void inOrder(TreeNodePtr treePtr){
  if (treePtr != NULL){
    inOrder(treePtr->left);
    printf("%3d", treePtr->item);
    inOrder(treePtr->right);
  }
}

void treeInOrder(void){
  if (!treeIsEmpty()){
    inOrder(rootPtr);
  }
}


static void preOrder(TreeNodePtr treePtr){
  if (treePtr != NULL){
    printf("%3d", treePtr->item);
    preOrder(treePtr->left);
    preOrder(treePtr->right);
  }
}

void treePreOrder(void){
  if (!treeIsEmpty()){
    preOrder(rootPtr);
  }
}


static void postOrder(TreeNodePtr treePtr){
  if (treePtr != NULL){
    postOrder(treePtr->left);
    postOrder(treePtr->right);
    printf("%3d",treePtr->item);
  }
}

void treePostOrder(void){
  if (!treeIsEmpty()){
    postOrder(rootPtr);
  }
}

static void stampa90(TreeNodePtr treePtr){
  if (treePtr != NULL){
    level++;
    stampa90(treePtr->right);
    printf(">%*s%5d\n", level*5," ", treePtr->item);
    stampa90(treePtr->left);
    level--;
  }
}

void stampaAlbero(void){
  if (!treeIsEmpty()){
    stampa90(rootPtr);
  }
}

void queueInit() {
  head = NULL;
}

int queueIsEmpty(void) {
  return head == NULL;
}

void queueEnqueue(TreeNodePtr node) {
  QueueNodePtr x = malloc(sizeof *x);
  if (x != NULL){
    x->node = node;
    x->next = NULL;
    if (queueIsEmpty()){
      head = tail = x;
    } else {
      tail->next = x;
      tail = tail->next;
    }
  } else {
    puts("Not enqueued. No memory.\n");
  }
}

TreeNodePtr queueDequeue() {
  if (head != NULL){
    TreeNodePtr node;
    QueueNodePtr temp;
    node = head->node;
    temp = head;
    head = head->next;
    if (queueIsEmpty()){
      tail = NULL;
    }
    free(temp);
    return node;
  } else {
    puts("Not dequeued. Queue underflow.\n");
  }
}

static void stampaLivelliF(TreeNodePtr treePtr){
  if (treePtr != NULL ){
    int i = 0;
    queueEnqueue(treePtr);

      while(!queueIsEmpty()){
        TreeNodePtr nodo = queueDequeue();
        i++;
        printf("%d ",nodo->item);
        if (nodo->left != NULL){
          queueEnqueue(nodo->left);
        }

        if(nodo->right != NULL){
          queueEnqueue(nodo->right);
        }

        /*
        if (i < SIZE){
          printf("- ");
        }*/

      }
  }
}

void stampaLivelli(void){
  if(!treeIsEmpty()){
    queueInit();
    stampaLivelliF(rootPtr);
  }
}

static TreeNodePtr min(TreeNodePtr treePtr){
  if (treePtr->left == NULL) return treePtr;
  else return min(treePtr->left);
}

static void deleteMin(TreeNodePtr *treePtr){
  if ((*treePtr)->left == NULL){
    TreeNodePtr tmp = (*treePtr)->right;
    free(*treePtr);
    *treePtr = tmp;
  } else {
    deleteMin(&((*treePtr)->left));
  }
}

void treeDeleteMin(){
  deleteMin(&rootPtr);
}

void delete(TreeNodePtr *treePtr, Item item){
  if ((*treePtr) == NULL){
    return;
  } else {
    if (item < (*treePtr)->item){
      delete(&((*treePtr)->left), item);
      return;
    } else if (item > (*treePtr)->item){
      delete(&((*treePtr)->right), item);
      return;
    } else {
      if ((*treePtr)->right == NULL) {
        TreeNodePtr tmp = (*treePtr)->left;
        free(*treePtr);
        *treePtr = tmp;
        return;
      }
      if ((*treePtr)->left == NULL) {
        TreeNodePtr tmp = (*treePtr)->right;
        free(*treePtr);
        *treePtr = tmp;
        return;
      }
      TreeNodePtr tmp = *treePtr;
      (*treePtr) = min((*treePtr)->right);
      deleteMin(&(tmp->right));
      (*treePtr)->right = tmp->right;
      (*treePtr)->left = tmp->left;
      free(tmp);
    }
  }
}

void treeDelete(Item item){
  if(rootPtr != NULL){
    delete(&rootPtr, item);
  } else {
    puts("L'albero è vuoto.\n");
  }
}
