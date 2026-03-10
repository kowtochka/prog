#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char const *argv[]){
    int A[25];
    int*B[5];
    for(int i=0;i<5;i++){
        B[i]=&A[i*5];
    }
    for(int i =0;i<25;i++){            
        A[i]=rand()%51-25;
    }
    printf("\n");
    for(int i=0;i<25;i++){
        printf("%5d",A[i]);
    }
    printf("\n");
    for(int i=0;i<5;i++){
        printf("\n");
        for(int j=0;j<5;j++){
            printf("%5d",B[i][j]);
        }
    }
    printf("\n");
    return 0;
}
