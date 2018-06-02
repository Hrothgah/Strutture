#define SIZE 100000
#define DISPLAYSKIP SIZE / 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Prototipi di funzione
void mergeSort(int array[], size_t length, int (*compare)(int a, int b));
void sortSubArray(int array[], size_t low, size_t high, int (*compare)(int a, int b));
void merge(int array[], size_t left, size_t middle1, size_t middle2, size_t right, int (*compare)(int a, int b));
void displayElements(int array[], size_t length);
void displaySubArray(int array[], size_t left, size_t right);
int ascending(int a, int b);
int descending(int a, int b);

int main(void){
  int array[SIZE]; //dichiara l'array di int da ordinare
  int order;
  srand(time(NULL)); //fornisce il seed alla funzione srand

  for (size_t i = 0; i < SIZE; i++){
    array[i] = rand() % 90 + 10; //assegna un valore ad ogni elemento
  }

  printf("Scegli l'ordinamento: 1 per crescente, 2, per decrescente:");
  scanf("%d",&order);
  while(order < 1 || order > 2){
    printf("Scegli l'ordinamento: 1 per crescente, 2, per decrescente:");
    scanf("%d",&order);
  }

  puts("Unsorted array:");
  displayElements(array,SIZE); //stampa l'sortSubArray
  puts("\n");
  if(order == 1){
    time_t startTime1 = time(NULL);
    mergeSort(array, SIZE, ascending);  //ordina per fusione l'array
    time_t endTime1 = time(NULL);
    printf("Tempo esecuzione = %f secondi\n\n",
           difftime(endTime1, startTime1));
  } else {
    time_t startTime2 = time(NULL);
    mergeSort(array, SIZE, descending);
    time_t endTime2 = time(NULL);
    printf("Tempo esecuzione = %f secondi\n\n",
           difftime(endTime2, startTime2));
  }



  puts("Sorted array:");
  displayElements(array, SIZE); //stampa l'array
  puts("\n");
}


//funzione che ordina per fusione l'array
void mergeSort(int array[], size_t length, int (*compare)(int a, int b)){
  sortSubArray(array, 0, length - 1, compare);
}

//funzione che ordina una porzione dell'array
void sortSubArray(int array[], size_t low, size_t high, int (*compare)(int a, int b)){
  // test base case: size of array is 1
  if ((high - low) >= 1) { // if not base case...
     size_t middle1 = (low + high) / 2;
     size_t middle2 = middle1 + 1;

     // output split step
     printf("%s", "split:   ");
     displaySubArray(array, low, high);
     printf("%s", "\n         ");
     displaySubArray(array, low, middle1);
     printf("%s", "\n         ");
     displaySubArray(array, middle2, high);
     puts("\n");

     if ((middle1 - low) > 7) {
       // split array in half and sort each half recursively
       sortSubArray(array, low, middle1, compare); // first half
       sortSubArray(array, middle2, high, compare); // second half
     }
     else {
       insertionSort(array, low, middle1); // first half
       insertionSort(array, middle2, high); // second half
       }

     // merge the two sorted arrays
     merge(array, low, middle1, middle2, high, compare);
  }
}

//fonde i due sottoarray ordinati in un sottoarray ordinato
void merge(int array[], size_t left, size_t middle1, size_t middle2, size_t right, int (*compare)(int a, int b)){
  size_t leftIndex = left; // indice nel sottoarray sinistro
  size_t rightIndex = middle2; //indice nel sottoarray destro
  size_t combinedIndex = left; //indice nell'array temporaneo
  int tempArray[SIZE]; //array temporaneo


  //stampa i due sottoarray prima di fonderli
  printf("%s", "merge:   ");
  displaySubArray(array, left, middle1);
  printf("%s", "\n         ");
  displaySubArray(array, middle2, right);
  puts("");

  //fonde i sottoarray finchè non si raggiunge la fine di uno di loro
  while(leftIndex <= middle1 && rightIndex <= right){
    //inserisce il più piccolo dei due elementi correnti nel risultato
    //e si sposta nella posizione seguente nel sottoarray
    if ((*compare)(array[leftIndex], array[rightIndex])){
      tempArray[combinedIndex++] = array[leftIndex++];
    } else {
      tempArray[combinedIndex++] = array[rightIndex++];
    }
  }

  if (leftIndex == middle2){ //fine del sottoarray sinistro?
    while (rightIndex <= right){ //copia il sottoarray destro
      tempArray[combinedIndex++] = array[rightIndex++];
    }
  } else { //fine del sottoarray destro?
    while (leftIndex <= middle1){ //copia il sottoarray sinistro
      tempArray[combinedIndex++] = array[leftIndex++];
    }
  }

  //ricopia indietro i valori nell'array originario
  for (size_t i = left; i <= right; i++){
    array[i] = tempArray[i];
  }


  //stampa il sottoarray fuso
  printf("%s", "         ");
  displaySubArray(array, left, right);
  puts("\n");
}

//stampa gli elementi dell'array
void displayElements(int array[], size_t length){
  displaySubArray(array, 0, length - 1);
}

//stampa alcuni elementi dell'array
void displaySubArray(int array[], size_t left, size_t right){

  //stampa spazi per l'allineamento
  for (size_t i = 0; i < left; i+=DISPLAYSKIP){
    printf("%s", "   ");
  }

  //stampa la porzione di array
  for (size_t i = left; i <= right; i+=DISPLAYSKIP){
    printf(" %d", array[i]);
  }

}

//  Funzione insertionSort
void insertionSort(int array[], size_t low, size_t high)
{
   // loop over length - 1 elements
   for (size_t i = low; i <= high; i++) {
       size_t moveItem = i; // initialize location to place element
       int insert = array[i]; // holds element to insert

       // search for place to put current element
       while (moveItem > low && array[moveItem - 1] > insert) {
           // shift element right one slot
           array[moveItem] = array[moveItem - 1];
           --moveItem;
       }

       array[moveItem] = insert; // place inserted element
   }
      //printf("%s", "insertion sorted:   ");
      //displaySubArray(array, low, high);
}

int ascending( int a, int b) {
  return a < b;
}

int descending( int a, int b) {
  return a > b;
}
