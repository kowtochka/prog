#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calc(int a, int b, int c, int &P, int &S);

int main(int argc, char const *argv[]){
    int P,S,a,b,c;
    printf("Введите стороны треугольника\n");
    scanf("%d%d%d",&a,&b,&c);
    calc(a,b,c,P,S);
    printf("Площадь:%d, периметр:%d\n", S,P);
    return 0;
}

int calc(int a, int b, int c, int &P, int &S){
    if(a+b>c&&a+c>b&&c+b>a){
        P = a+c+b;
        int p = P/2;
        S = sqrt(p*(p-a)*(p-b)*(p-c));
        return 1;
    }else return 0;
}