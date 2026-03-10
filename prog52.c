#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[]){
    int**A=malloc(sizeof(int*)*9);
    for(int i =0;i<9;i++){   
        A[i]=malloc(sizeof(int)*(i+1));
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<(i+1);j++){
            A[i][j]=(i+1)*(j+1);   
        }
    }
    printf("\n");
    for(int i=0;i<9;i++){
        printf("\n");
        for(int j=0;j<(i+1);j++){
            printf("%3d ",A[i][j]);
        }
    }
    printf("\n");  
    return 0;
}
