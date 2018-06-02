h#define SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Prototipi di funzione
void mergeSort(int array[], size_t length);
void sortSubArray(int array[], size_t low, size_t high);
void merge(int array[], size_t left, size_t middle1, size_t middle2, size_t right);
void displayElements(int array[], size_t length);
void displaySubArray(int array[], size_t left, size_t right);

int main(void){
  int array[SIZE]; //dichiara l'array di int da ordinare
  srand(time(NULL)); //fornisce il seed alla funzione srand

  for (size_t i = 0; i < SIZE; i++){
    array[i] = rand() % 90 + 10; //assegna un valore ad ogni elemento
  }

  puts("Unsorted array:");
  displayElements(array,SIZE); //stampa l'sortSubArray
  puts("\n");
  mergeSort(array, SIZE); //ordina per fusione l'array
  puts("Sorted array:");
  displayElements(array, SIZE); //stampa l'array
  puts("\n");

}

//funzione che ordina per fusione l'array
void mergeSort(int array[], size_t length){
  sortSubArray(array, 0, length - 1);
}

//funzione che ordina una porzione dell'array
void sortSubArray(int array[], size_t low, size_t high){
  //effettua il test per il caso di base
  if ((high - low) >= 1) { //se non si tratta del caso base
    size_t middle1 = (low + high) / 2;
    size_t middle2 = middle1 + 1;

    //stampa il passo di suddivisione
    printf("%s", "split:   ");
    displaySubArray(array, low, high);
    printf("%s", "\n         ");
    displaySubArray(array, low, middle1);
    printf("%s", "\n         ");
    displaySubArray(array, middle2, high);
    puts("\n");

    //divide l'array a meta' e ordina ciascuna meta' ricorsivamente
    sortSubArray(array, low, middle1); //prima meta'
    sortSubArray(array, middle2, high); //seconda meta'

    //fonde i due array ordinati
    merge(array, low, middle1, middle2, high);
  }
}

//fonde i due sottoarray ordinati in un sottoarray ordinato
void merge(int array[], size_t left, size_t middle1, size_t middle2, size_t right){
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
    if (array[leftIndex] <= array[rightIndex]){
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
  for (size_t i = 0; i < left; i++){
    printf("%s", "   ");
  }

  //stampa la porzione di array
  for (size_t i = left; i <= right; i++){
    printf(" %d", array[i]);
  }
}
