#include <stdio.h>
int binarySearch(int b[], int searchKey, int max, int min);

int main(void){
  int array[15] = {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28};
  int n;

  printf("Immetti un numero da cercare: ");
  scanf("%d",&n);

  printf("Il numero cercato è in posizione %d dell'array",binarySearch(array[], 10, 15,0));

}

binarySearch(int b[], int searchKey, int max, int min){
  while (low <= high){

   int middle = (low + high) / 2;

   if (searchKey == b[middle]){
      return middle;
    } else if (searchKey < b[middle]){
     binarySearch(array[], 10, middle-1,0);
    } else {
     binarySearch(array[], 10, 15, middle+1);
    }

  }
    
  return middle;
}
