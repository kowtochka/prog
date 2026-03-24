#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void nulling(int *n, int c);

void main(int argc, char const *argv[]){
    int n =100;
    srand(time(0));
    int *A=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        A[i]=rand()%101+1;
    }
    printf("Исходный массив\n");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    printf("\n");
    nulling(A, n);
    printf("Конечный массив\n");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
void nulling(int *n, int c){
    int*m1 = &n[0];
    int*m2 = &n[1];
    for(int i=0;i<c;i++){
        if(*m1>=n[i]){
            m1 =&n[i]; 
        }
        if(*m2>=*m1){
            int*temp = m2;
            m2=m1;
            m1=temp;
        }
    }
    if(m2<m1){
        while(m2<m1-1){
            m2++;
            *m2=0;
        }
    }else{
        while(m1<m2-1){
            m1++;
            *m1=0;
        }        
    }
}    