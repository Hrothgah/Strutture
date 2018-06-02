#define SIZE 11
#define MIN(a,b) (((a)<(b))?(a):(b))
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes 
void mergeSort(int array[], size_t length);
void sortSubArray(int array[], size_t low, size_t high);
void merge(int array[], size_t left, size_t middle1, 
   size_t middle2, size_t right);
void displayElements(int array[], size_t length);
void displaySubArray(int array[], size_t left, size_t right);

int main(void)
{
   int array[SIZE]; // declare the array of ints to be sorted 
    
   srand(time(NULL)); // seed the rand function 
    
   for (size_t i = 0; i < SIZE; i++) {
      array[i] = rand() % 90 + 10; // give each element a value 
   }
        
   puts("Unsorted array:");
   displayElements(array, SIZE); // print the array 
   puts("\n");
   mergeSort(array, SIZE); // merge sort the array 
   puts("Sorted array:");
   displayElements(array, SIZE); // print the array 
} 

// function that merge sorts the array 
void mergeSort(int array[], size_t length) {
  int aux[length];
  for (int sz = 1; sz < length; sz = sz + sz)
    for (int lo = 0; lo < length - sz; lo += sz+sz)
      merge(array, lo, lo+sz-1, lo+sz, MIN(lo+sz+sz-1, length-1));
} 

// merge two sorted subarrays into one sorted subarray 
void merge(int array[], size_t left, size_t middle1, 
   size_t middle2, size_t right)
{
   size_t leftIndex = left; // index into left subarray 
   size_t rightIndex = middle2; // index into right subarray 
   size_t combinedIndex = left; // index into temporary array 
   int tempArray[SIZE]; // temporary array 
    
   // output two subarrays before merging 
   printf("%s", "merge:   ");
   displaySubArray(array, left, middle1);
   printf("%s", "\n         ");
   displaySubArray(array, middle2, right);
   puts("");
    
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
    
   // output merged subarray 
   printf("%s", "         ");
   displaySubArray(array, left, right);
   puts("\n");
} 

// display elements in array 
void displayElements(int array[], size_t length)
{
   displaySubArray(array, 0, length - 1);
} 

// display certain elements in array 
void displaySubArray(int array[], size_t left, size_t right)
{
   // output spaces for alignment 
   for (size_t i = 0; i < left; i++) {
      printf("%s", "   ");
   } 
    
   // output elements left in array 
   for (size_t i = left; i <= right; i++) {
      printf(" %d", array[i]);
   } 
} 

