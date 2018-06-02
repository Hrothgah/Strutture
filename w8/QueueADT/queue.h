#include "item.h"

typedef struct queue *Q;

Q queueInit(int maxN);
int queueIsEmpty(Q);
void queueEnqueue(Q, Item);
Item queueDequeue(Q);
