#include <stdlib.h>
#include <stdio.h>

struct arco {
  int nodo;
  struct arco * next;
};

typedef struct arco Arco;
typedef Arco * ArcoPtr;

int main(){
  ArcoPtr array;
  char appoggio[20];
  int temp[20];
  int k, dimensione, cont = 0;
  char valore;

  FILE * pf;

  pf = fopen("grafo.txt","r");

  while(!feof(pf)){
    fscanf(pf, "%c", &valore);
    if(valore == '\n')
      cont++;
  }

  dimensione = (cont-1)*(cont-2);

  k = 0;

  array = (ArcoPtr)malloc(dimensione*sizeof(ArcoPtr));

  rewind(pf);
  int a;
  char b;
  while(!feof(pf)){
    fscanf(pf, "%d", &a);
    //printf("a vale %d \n",a);
    do {
      //puts("inizio a leggere b");
      //puts("\n");
      fscanf(pf,"%c",&b);
      //printf("b vale %c ,", b);
      if ((b >= '0') && (b <= '9')){
        ArcoPtr nodo1 = malloc(sizeof(Arco));
        ArcoPtr nodo2 = malloc(sizeof(Arco));
        nodo1->nodo = a;
        nodo1->next = nodo2;
        nodo2->nodo = (int)b-48;
        nodo2->next = NULL;
        array[k] = *nodo1;
        k++;
      }
    } while (b != '\n');
  }

for (size_t t = 0; t < k; t++){
  printf("%d -> %d ", (array[t]).nodo, ((array[t]).next)->nodo);
  puts("\n");
}

}
