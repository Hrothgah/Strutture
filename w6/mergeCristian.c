#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 9

void mergeSort(int V[],int low,int high);
void merge(int B[],int low,int middle1,int middle2,int high);
void carbsort(int V[], int dim);

int main(){
  srand(time(NULL));
  size_t i;
  int A[SIZE], B[SIZE];

  //generazione array
  for(i=0;i<SIZE;i++){
    A[i]=rand()%99+1;
  }

  for(i=0; i<SIZE; i++){
    B[i] = A[i];
  }

  printf("Array:\n");
  for(i=0;i<SIZE;i++){
    printf("%d ",A[i]);
  }
  printf("\n");

  time_t mstart = time(NULL);
  mergeSort(A,0,SIZE-1);
  time_t mstop = time(NULL);

  time_t cstart = time(NULL);
  carbsort(B, SIZE);
  time_t cstop = time(NULL);

  printf("Tempo per il mergesort: %d\n", difftime(mstop, mstart));
  printf("Tempo per il carbSort:  %d\n", difftime(cstop, cstart));

  /*printf("\n\nArray ordinato:\n");
  for(i=0;i<SIZE;i++){
    printf("%d ", A[i]);
  }*/
  puts("\n");
}

void mergeSort(int V[],int low,int high){
    if(low<high){
      int middle1=(high+low)/2;
      int middle2=middle1+1;

      mergeSort(V,low,middle1);
      mergeSort(V,middle2,high);

      merge(V,low,middle1,middle2,high);
    }
}

void merge(int B[],int low,int middle1,int middle2,int high){
  int leftIndex=low;
  int rightIndex=middle2;
  int tempIndex=low;
  int tempV[SIZE];

while(leftIndex<=middle1 && rightIndex<=high){

    if(B[leftIndex]<B[rightIndex]){
      tempV[tempIndex++]=B[leftIndex++];
    }
    else{
      tempV[tempIndex++]=B[rightIndex++];
    }
  }

  if(leftIndex>middle1){
    while(rightIndex<=high){
      tempV[tempIndex++]=B[rightIndex++];
    }
  }

  if(rightIndex>high){
    while(leftIndex<=middle1){
      tempV[tempIndex++]=B[leftIndex++];
    }
  }

  for(int i=low;i<=high;i++){
    B[i]=tempV[i];
  }
}

void carbsort(int V[], int dim){
  size_t i, ci, c=0;
  int secV[SIZE];

  for (i = 0; i<SIZE; i++){
    for (ci = 0; ci<SIZE; ci++){
      if(V[i]>=V[ci]){
        c++;
      }
    }
    secV[c-1] = V[i];
    c = 0;
  }
}
