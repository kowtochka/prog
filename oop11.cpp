#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <ctime>
int *genRandArray(int size, int maxValue);
void print(int *arr);
int main()
{
    srand(time(0));
    int size = rand() % 10;
    int maxValue = 100;
    int *arr = genRandArray(size, maxValue);
    print(arr);
}
int *genRandArray(int size, int maxValue)
{
    int *p = new int[size];
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        p[i] = rand() % maxValue;
    }
    return p;
}
void print(int *arr)
{
    printf("\n");
    for (int i = 0; arr[i] != NULL; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
