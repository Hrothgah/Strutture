#include "item.h"

struct treeNode {
  struct treeNode * left;
  Item id;
  Item saldo;
  struct treeNode * right;
};

typedef struct treeNode TreeNode;
typedef TreeNode * TreeNodePtr;
static TreeNodePtr root;

void treeInit();
void treeInsertNode(Item id);
void insertNode(TreeNodePtr *nodePtr, Item id);
int treeIsEmpty();
void inOrder(TreeNodePtr root);

Item searchTree(Item item);
