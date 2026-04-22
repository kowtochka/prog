#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define M 13 // Размер хеш таблицы
#define N 10 // Количество элементов
struct spis
{
    int data;
    spis *next;
};
spis *ht[M] = {};
int data[N];

int h(int x)
{ // хеш функция
    // return x % M;
    return (x * 19 + 3) % M;
}
// функция добавления элемента в хеш таблицу
int add_hash_table(int x)
{
    spis *p, *t;
    int hash = h(x);
    // запись элемента в список
    t = ht[hash];
    p = new spis;
    p->data = x;
    p->next = t;
    ht[hash] = p;
    return hash;
}
// функция поиска элемента в хеш таблице
int find_hash_table(int x, int &collision)
{
    collision = 0;
    spis *p;
    int hash = h(x);
    p = ht[hash];
    while (p)
    { // перебор элементов с одинаковым хешем в списке
        if (p->data == x)
            return p->data;
        collision++;
        p = p->next;
    }
    return -1; // если элемент не найден
}

int main()
{
    srand(time(0));
    int i, hash, d, collision;
    spis *p;
    printf("    N data   hash\n");
    for (i = 0; i < N; i++)
    {
        data[i] = rand() % 300 + 1;
        hash = add_hash_table(data[i]);
        printf("%5d %5d %5d\n", i, data[i], hash);
    }
    printf("\n");
    printf("    found\n");
    printf("%5s %5s\n", "data", "collision");
    for (i = 0; i < N; i++)
    {
        d = find_hash_table(data[i], collision);
        printf("%5d %5d\n", d, collision);
    }
    d = find_hash_table(332, collision);
    printf("%5d %5d\n", d, collision);
}