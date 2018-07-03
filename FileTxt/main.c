#include "item.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
  FILE * fp;
  char * cognome[50];
  char * a[255];
  char * b[255];

  fp = fopen("cognomi.txt","r");
  listInit();


  while(!feof(fp)){
    fgets(cognome,49,fp);
    listIns(cognome);
  }

/*
  fgets(a,250,fp);
  fgets(b,250,fp);
  toUpper(a);
  toUpper(b);
  printf("%d\n",(strcmp(a,b)));
*/
  printList();

  puts("\n");

}
