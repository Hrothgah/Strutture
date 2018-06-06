#include "item.h"
#include <stdio.h>

void queueInit();
int queueIsEmpty();
void queueEnqueue(int i, int numero, FILE * file);
void queueDequeue(int i, FILE * file);
int franco(int i);

void printQueue(FILE * file);
int countQueue();
