#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
const int M = 17;
const int n = 12;

struct student
{
    char surname[30];
    int grade[4];
    student *next;
} *p, *t;

student *ht[M] = {};

unsigned h2(char *str);
int add_hash_table(char *x);
char* find_hash_table(char x[30], int &collision);

int main(int argc, char const *argv[])
{
    int i, hash, collision, col=0;
    char d[30];
    student *p;
    student *ht[M] = {};
    srand(time(0));
    char surnames[n][30] = {
        "Denezhkina",
        "Illarionov",
        "Abduraimova",
        "Kozik",
        "Milkevich",
        "Zaharova",
        "Dec",
        "Galdak",
        "Chebotareva",
        "Batukova",
        "Kuznetsova",
        "Lobova"};
        srand(time(0));
    printf("    N   surnames       hash\n");
    for (i = 0; i < n; i++)
    {
        hash = add_hash_table(surnames[i]);
        printf("%5d %12s %5d\n", i, surnames[i], hash);
    }
    printf("%5s %5s\n", "data", "collision");
    for (i = 0; i < n; i++)
    {
        strcpy(d,find_hash_table(surnames[i], collision));
        col+=collision;
        printf("%12s %5d\n", d, collision);
    }
    printf("Среднее кол-во коллизий: %f\n\n",(double)col/n);
    printf("Введите элемент\n");
    char f[30];
    scanf("%30s",&f);
    strcpy(d, find_hash_table(f, collision));
    printf("%12s %5d\n", d, collision);
    return 0;
}

unsigned h2(char *str){ 
    unsigned i, hash=5381, c;
    while(c=*str++) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash%M;
}
int add_hash_table(char *x)
{
    int hash = h2(x);
    t = ht[hash];
    p = new student;
    for(int i =0;i<4;i++){
        p->grade[i]=rand()%4+2;
    }
    strcpy(p->surname,x);
    p->next = t;
    ht[hash] = p;
    return hash;
}

char* find_hash_table(char x[30], int &collision)
{
    collision = 0;
    int hash = h2(x);
    p = ht[hash];
    while (p)
    {
        if (strcmp(p->surname, x)==0)
            return p->surname;
        collision++;
        p = p->next;
    }
    return "nothing";
}