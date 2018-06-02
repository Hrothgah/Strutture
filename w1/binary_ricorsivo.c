#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20


int binarySearch(int array[], int searchKey, int max, int min);
void mergeSort(int array[], size_t length);
void sortSubArray(int array[], size_t low, size_t high);
void merge(int array[], size_t left, size_t middle1, size_t middle2, size_t right);

int main(void){
  srand(time(NULL));
  int array[SIZE];
  int n;

  for (size_t i = 0; i <= SIZE; i++){
    array[i] = rand() % 90 + 10;
  }

  printf("L'array random è: ");
  for(size_t i = 0; i < SIZE; i++){
    printf("%d ", array[i]);
  }
  printf("\n");

  mergeSort(array, SIZE);

  printf("L'array ordinato è: ");
  for(size_t i = 0; i < SIZE; i++){
    printf("%d ", array[i]);
  }
  printf("\n");

  printf("Immetti un numero da cercare: ");
  scanf("%d",&n);
  printf("\n");

  printf("Il numero cercato è in posizione %d dell'array\n",binarySearch(array, n, 20,0));

}

int binarySearch(int array[], int searchKey, int max, int min){
  int middle;

  while (min <= max){

   middle = (min + max) / 2;

   if (searchKey == array[middle]){
      return middle;
    } else if (searchKey < array[middle]){
     binarySearch(array, searchKey, middle-1,0);
    } else {
     binarySearch(array, searchKey, 20, middle+1);
    }

  }

  return middle;
}


// function that merge sorts the array
void mergeSort(int array[], size_t length)
{
   sortSubArray(array, 0, length - 1);
}


// function that sorts a piece of the array
void sortSubArray(int array[], size_t low, size_t high)
{
   // test base case: size of array is 1
   if ((high - low) >= 1) { // if not base case...
      size_t middle1 = (low + high) / 2;
      size_t middle2 = middle1 + 1;

      // split array in half and sort each half recursively
      sortSubArray(array, low, middle1); // first half
      sortSubArray(array, middle2, high); // second half

      // merge the two sorted arrays
      merge(array, low, middle1, middle2, high);
   }
}

// merge two sorted subarrays into one sorted subarray
void merge(int array[], size_t left, size_t middle1, size_t middle2, size_t right)
{
   size_t leftIndex = left; // index into left subarray
   size_t rightIndex = middle2; // index into right subarray
   size_t combinedIndex = left; // index into temporary array
   int tempArray[SIZE]; // temporary array


   // merge the subarrays until the end of one is reached
   while (leftIndex <= middle1 && rightIndex <= right) {
      // place the smaller of the two current elements in result
      // and move to the next space in the subarray
      if (array[leftIndex] <= array[rightIndex]) {
         tempArray[combinedIndex++] = array[leftIndex++];
      }
      else {
         tempArray[combinedIndex++] = array[rightIndex++];
      }
   }

   if (leftIndex == middle2) { // if at end of left subarray ...
      while (rightIndex <= right) { // copy the right subarray
         tempArray[combinedIndex++] = array[rightIndex++];
      }
   }
   else { // if at end of right subarray...
      while (leftIndex <= middle1) { // copy the left subarray
         tempArray[combinedIndex++] = array[leftIndex++];
      }
   }

   // copy values back into original array
   for (size_t i = left; i <= right; i++) {
      array[i] = tempArray[i];
   }

}
