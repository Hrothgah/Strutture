// di Daniele Schicchi
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 100

void riempiVettore(int *v, int n);
void mergesort(int *v, int n);

int main (void){
    int v[N];
    int n=20;
    riempiVettore(v,n);
    mergesort(v,n);
    return 0;
}

void riempiVettore(int *v, int n){
    srand((time(NULL)));
    for (int i=0; i<n; i++)
        v[i]=rand() %100 +1;
}

void merge (int *v, int low, int middle, int high, int n){
    int i=low;
    int j=middle+1;
    int temp[high-low+1];
    int k=0;
    while(i <= middle && j<= high){
        if(v[i]<=v[j]){
            temp[k]=v[i];
            ++i;
        }
        else{
            temp[k]=v[j];
            ++j;
        }
        ++k;

    }
    while(i <= middle){
        temp[k]=v[i];
        ++i;
        ++k;
    }

    while(j <= high){
        temp[k]=v[j];
        ++j;
        ++k;
    }

    printf("vettore ottenuto dal merge:");
    for(int i=0; i < (high-low+1); i++){
        v[low+i]=temp[i];
        printf("%d ",temp[i]);

    }
    printf("\n\n");


}


void mergesort(int *v, int n){
    int parti, numinsiemi,restanti,left,middle,right;
    int i;
    int resto=0;
    printf("lunghezza vettore originale: %d\n",n);
    i=2;
    while(i<=n){
        numinsiemi=n/i;
        restanti=n%i;
        printf("\ndivisione per: %d\nnuminsiemi %d\nelementi restanti %d\n",i,numinsiemi,restanti);
        for (int p=0;p<numinsiemi;p++){
            left=p*i;
            right=left + i-1;
            middle= left + i/2-1;
            printf("\nchiamo merge su:\nleft %d\nmiddle %d\nright %d\n",left,middle,right);
            merge(v,left,middle,right,n);

        }
        if(restanti!=0){
            middle=right;
            right=right+restanti;
            printf("restanti: %d\n",restanti);
            printf("\nchiamo merge su: \nleft %d\nmiddle %d\nright %d\n",left,middle,right);
            merge(v,left,middle,right,n);
            printf("vettore originale:\n");
            for(int k=0;k<n;k++)
                printf("%d ",v[k]);
            printf("\n");
        }
        i=i*2;
    }

}
