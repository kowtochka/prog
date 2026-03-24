#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int n =10;
int* A=NULL;
int* B=NULL;

void zanulen(int *arr);
void PartsBubbleSort();

void main(int argc, char const *argv[]){
    srand(time(0));
    A=(int*)malloc(sizeof(int)*n);
    printf("\n");
    for(int i=0;i<n;i++){
        A[i]=rand()%99+1;
    }
    printf("Исходный массив\n");
    for(int i=0;i<n;i++){
        printf("%2d ",A[i]);
    }
    printf("\n");
    zanulen(A);
    printf("Конечный массив\n");
    for(int i=0;i<n;i++){
        printf("%2d ",A[i]);
    }
    printf("\n");
    printf("\n");
}

void zanulen(int *arr){
    B=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        B[i]=i;
    }
    PartsBubbleSort();
    if(B[0]<B[1]){
        for(int i=B[0]+1;i<B[1];i++)
        arr[i]=0;
    }else {
        for(int i=B[1]+1;i<B[0];i++)
        arr[i]=0;
    }


} 

void PartsBubbleSort(){
    for (int i=0; i<2;i++){
        for(int j=n-1;j>i;j--){
            if(A[B[j]]<A[B[j-1]]){
                int temp = B[j];
                B[j]=B[j-1];
                B[j-1]=temp;
            }
        }
    }
}