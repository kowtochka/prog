#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void BubbleSort(int* arr, int n);
int Search(int *arr, int n,int x);
int BinarySearch1(int *arr,int n,int x);

int main(int argc, char const *argv[]){
    int n=100;
    int x=500;
    srand(time(0));
    int *A=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        A[i]=rand()%n+1;
    }
    A[0]=x;
    BubbleSort(A,n);
    printf("Бинарный поиск: %d\n", BinarySearch1(A,n,x));
    printf("Перебор: %d\n", Search(A,n,x));
    n =1000;
    A=realloc(A,sizeof(int)*n);
    for(int i=0;i<n;i++){
        A[i]=rand()%n+1;
    }
    BubbleSort(A,n);
    printf("Бинарный поиск: %d\n", BinarySearch1(A,n,x));
    printf("Перебор: %d\n", Search(A,n,x));
    return 0;
}

void BubbleSort(int* arr, int n){
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            if(arr[j]>arr[j-1]){
                int temp = arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
}

int Search(int *arr, int n,int x){
    int C =0;
    for(int i=0;i<n;i++){
        C++;
        if(arr[i]==x) break;
    }
    return C;
}

int BinarySearch1(int *arr,int n,int x){
    int C=0;
    int R=n-1;
    int L=0;
    while(L<=R){
        int m=floor((double)(L+R)/2);
        C++;
        if(arr[m]==x){
            break;
        }
        C++;
        if (arr[m]>x){
            L=m+1;
        }else{
            R=m-1;
        }
    }
    return C;
}