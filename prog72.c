#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void sum(int **arr, int l);

int main(int argc, char const *argv[]){
    int l;
    srand(time(0));
    printf("Введите количество строк\n");
    scanf("%d", &l);
    printf("\n");
    int *B = malloc(sizeof(int)*l);
    for(int i=0;i<l;i++){
        B[i]=(rand()%9+2);
    }
    int **A=malloc(sizeof(int*)*l);
    srand(time(0));
    for(int i=0;i<l;i++){
        A[i]=malloc(sizeof(int)*B[i]);
    }
    for(int i=0;i<l;i++){
        for(int j=1;j<B[i];j++){
            A[i][j]=rand()%10+1;
        }
        A[i][0]=B[i];
    }
    printf("\n");
    sum(A,l);
    printf("\n");
    return 0;
}
void sum(int **arr, int l){
    for(int i=0;i<l;i++){
        printf("\n");
        int sum=0;
        for(int j=0;j<arr[i][0];j++){
            printf("%3d",arr[i][j]);
            sum+=arr[i][j];
        }
        for(int k=0; k<10-arr[i][0];k++) printf("   ");
        printf(" Сумма:%d",sum);
    }
}
