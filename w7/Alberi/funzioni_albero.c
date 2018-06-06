#include <stdlib.h>
#include <stdio.h>
#include "albero.h"
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
int maxLev = 0;

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
    if (level > maxLev){
      maxLev = level;
    }
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
    int curLev = 1;
    int proxLev = 0;
    /*int livello = 0;*/
    queueEnqueue(treePtr);
    /*printf("maxLev vale %d\n",maxLev);
    printf(">");*/

      while(!queueIsEmpty()){
        TreeNodePtr nodo = queueDequeue();
        curLev--;
        //printf("%*s%2d",(maxLev-livello)*8,".",nodo->item);
        printf("%d ",nodo->item);
        if (nodo->left != NULL){
          queueEnqueue(nodo->left);
          proxLev++;
        }

        if(nodo->right != NULL){
          queueEnqueue(nodo->right);
          proxLev++;
        }
        if (curLev == 0){
          printf("\n");
          //printf(">");
          curLev = proxLev;
          proxLev = 0;
          //livello++;
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
