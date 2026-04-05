#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int C = 0; // сравнение
int M = 0; // пересылки
int n;
int *A = NULL;
int *B = NULL;
int teorM;
int teorC;

void FillInc();
void FillDec();
void FillRand();
void ShellSort2();
void Heap(int *A);
void PrintMas();
int main(int argc, char **argv)
{
    n = 100;
    A = (int *)malloc(n * sizeof(int));
    printf("\n");
    printf("----Массив случайных чисел----");
    printf("\n");
    printf("\n");
    printf("Исходный массив: ");
    FillRand();
    PrintMas();
    printf("\n");
    printf("Построенная пирамида: ");
    Heap(A);
    PrintMas();
    printf("Среднее теоретическое значение  M:%d, фактическое:%d", teorM, M);
    printf("\n");
    printf("Теоретическое значение  C:%d, фактическое:%d\n", teorC, C);
    printf("Время работы: %d", C + M);
    printf("\n");
    printf("\n");

    printf("----Массив возрастающих чисел----");
    printf("\n");
    printf("\n");
    printf("Исходный массив: ");
    FillInc();
    PrintMas();
    printf("\n");
    printf("Отсортированный массив: ");
    Heap(A);
    PrintMas();
    teorM = 0;
    printf("Теоретическое значение  M:%d, фактическое:%d", teorM, M);
    printf("\n");
    teorC = n - 1;
    printf("Теоретическое значение  C:%d, фактическое:%d\n", teorC, C);
    printf("Время работы: %d", C + M);
    printf("\n");
    printf("\n");

    printf("----Массив убывающих чисел----");
    printf("\n");
    printf("\n");
    printf("Исходный массив: ");
    FillDec();
    PrintMas();
    printf("\n");
    printf("Отсортированный массив: ");
    Heap(A);
    PrintMas();
    teorM = 3 * n * (n - 1) / 2;
    printf("Теоретическое значение  M:%d, фактическое:%d", teorM, M);
    printf("\n");
    teorC = (n * (n - 1)) / 2;
    printf("Теоретическое значение  C:%d, фактическое:%d\n", teorC, C);
    printf("Время работы: %d", C + M);
    printf("\n");
    printf("\n");

    printf("\n");
    printf("\n");
    return 0;
}

void FillInc()
{
    for (int i = 0; i < n; i++)
    {
        A[i] = i + 1;
    }
}
void FillDec()
{
    for (int i = 0; i < n; i++)
    {
        A[i] = n - i;
    }
}
void FillRand()
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % (2 * n + 1);
    }
}
void PrintMas()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void ShellSort2()
{
    C = 0;
    M = 0;
    int m = 0;
    int k = 1;
    int H1[20];
    while (1)
    {
        int h = (int)pow(2, k) - 1;
        if (h >= n)
            break;
        H1[m] = h;
        m++;
        k++;
    }
    for (int k = H1[m - 1]; m >= 0; m--)
    {
        for (int i = k; i < n; i++)
        {
            M++;
            int temp = A[i];
            int j = i - k;
            if (A[j] < temp)
                C++;
            for (; j >= 0 && temp < A[j]; C++)
            {
                M++;
                A[j + k] = A[j];
                j = j - k;
            }
            M++;
            A[j + k] = temp;
        }
    }
}
void Heap(int *A)
{
    teorM = 0;
    teorC = 0;
    M = 0;
    C = 0;
    for (int l = n / 2 - 1; l >= 0; l--)
    {

        int R = n - 1;
        int L = l;
        int i = L;
        int temp = A[L];
        teorM += log2(R / L);
        teorC += (log2(R / L)) / 2 + 1;
        while (1)
        {
            int j = 2 * i + 1;
            if (j > R)
                break;
            C++;
            if (j < R && A[j + 1] <= A[j])
                j += 1;
            C++;
            if (temp <= A[j])
                break;
            M++;
            A[i] = A[j];
            i = j;
        }
        M += 2;
        A[i] = temp;
    }
}