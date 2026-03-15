#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float fact(float a);
int baby(float n, float m, float &pg, float &pb);

int main(int argc, char const *argv[]){
    float pg,pb;
    float n,m;
    printf("Введите данные\n");
    scanf("%f%f",&n,&m);
    if (baby(n,m,pg,pb)==1){
        baby(n,m,pg,pb);
        printf("Шанс на девочек:%f \nШанс на мальчиков:%f\n",pg,pb);
    }else printf("Входные данные некорректны.\n");
    return 0;
}

int baby(float n, float m, float &pg, float &pb){
    if((n>0&&m>=0)&& m<n){
        float C = fact(n)/(fact(m)*fact(n-m));
        pg=C*pow(0.45,m)*pow(0.55,n-m);
        pb=C*pow(0.55,m)*pow(0.45,n-m);
        return 1;
    }else return 0;
}

float fact(float a){
    float res=1;
    for(int i=1;i<a+1;i++){
        res *=i;
    }
    return res;
}
