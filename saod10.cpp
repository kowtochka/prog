#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int C = 0; // сравнение
int M = 0; // пересылки
int n, rm, rt = 0;
int *A = NULL;

void FillInc();
void FillDec();
void FillRand();
void QuickSort1(int L, int R);
void QuickSort2(int L, int R);
void PrintMas();

int main(int argc, char **argv)
{
    n = 10;
    A = (int *)malloc(n * sizeof(int));
    int teorM = 3 * (n - 1);
    int teorC = ((n * n) + 5 * n + 4) / 2;
    printf("\n");
    printf("----Массив случайных чисел----");
    printf("\n");
    printf("\n");
    printf("Исходный массив: ");
    FillRand();
    PrintMas();
    printf("\n");
    printf("Отсортированный массив: ");
    int L = 0;
    int R = n - 1;
    QuickSort1(L, R);
    PrintMas();
    printf("Среднее теоретическое значение  M:%d, фактическое:%d", teorM, M);
    printf("\n");
    printf("Теоретическое значение  C:%d, фактическое:%d\n", teorC, C);
    printf("Время работы: %d", C + M);
    printf("\n");
    printf("\n");
    C = 0;
    M = 0;
    printf("----Массив возрастающих чисел----");
    teorM = 3 * (n - 1);
    teorC = ((n * n) + 5 * n + 4) / 2;
    printf("\n");
    printf("\n");
    printf("Исходный массив: ");
    FillInc();
    PrintMas();
    printf("\n");
    printf("Отсортированный массив: ");
    L = 0;
    R = n - 1;
    QuickSort1(L, R);
    PrintMas();
    printf("Теоретическое значение  M:%d, фактическое:%d", teorM, M);
    printf("\n");
    printf("Теоретическое значение  C:%d, фактическое:%d\n", teorC, C);
    printf("Время работы: %d", C + M);
    printf("\n");
    printf("\n");
    C = 0;
    M = 0;
    printf("----Массив убывающих чисел----");
    teorM = 3 * (n - 1);
    teorC = ((n * n) + 5 * n + 4) / 2;
    printf("\n");
    printf("\n");
    printf("Исходный массив: ");
    FillDec();
    PrintMas();
    printf("\n");
    printf("Отсортированный массив: ");
    L = 0;
    R = n - 1;
    QuickSort1(L, R);
    PrintMas();
    printf("Теоретическое значение  M:%d, фактическое:%d", teorM, M);
    printf("\n");
    printf("Теоретическое значение  C:%d, фактическое:%d\n", teorC, C);
    printf("Время работы: %d", C + M);
    printf("\n");
    printf("\n");

    printf("\n");
    printf("\n");
    printf("|////////|//////////////////////////|\n");
    printf("|   N    |         Mф+Сф            |\n");
    printf("|        | Убыв.  | Случ.  |Возр .  |\n");
    printf("|////////|////////|////////|////////|\n");

    for (n = 100; n < 600; n += 100)
    {
        A = (int *)realloc(A, n * sizeof(int));
        FillDec();
        L = 0;
        R = n - 1;
        QuickSort1(L, R);
        int MDec = M;
        int CDec = C;
        FillRand();
        C = 0;
        M = 0;
        L = 0;
        R = n - 1;
        QuickSort1(L, R);
        int MRand = M;
        int CRand = C;
        FillInc();
        C = 0;
        M = 0;
        L = 0;
        R = n - 1;
        QuickSort1(L, R);
        int MInc = M;
        int CInc = C;
        printf("|%8d|%8d|%8d|%8d|\n", n, MDec + CDec, MRand + CRand, MInc + CInc);
    }
    printf("|////////|////////|////////|////////|\n");
    printf("\n");
    printf("\n");
    printf("|////////|/////////////////////////////////////////////////////|\n");
    printf("|   N    |       QuickSort1         |       QuickSort2         |\n");
    printf("|        | Убыв.  | Случ.  |Возр .  | Убыв.  | Случ.  |Возр .  |\n");
    printf("|////////|////////|////////|////////|////////|////////|////////|\n");

    for (n = 100; n < 600; n += 100)
    {
        A = (int *)realloc(A, n * sizeof(int));
        FillDec();
        L = 0;
        R = n - 1;
        rt = 0;
        rm = 0;
        QuickSort2(L, R);
        int r4 = rm;
        rt = 0;
        rm = 0;
        FillDec();
        L = 0;
        R = n - 1;
        QuickSort1(L, R);
        int r1 = rm;
        rt = 0;
        rm = 0;
        FillRand();
        L = 0;
        R = n - 1;
        QuickSort2(L, R);
        int r5 = rm;
        rt = 0;
        rm = 0;
        FillRand();
        L = 0;
        R = n - 1;
        QuickSort1(L, R);
        int r2 = rm;
        rt = 0;
        rm = 0;
        FillInc();
        L = 0;
        R = n - 1;

        QuickSort2(L, R);
        int r6 = rm;
        rt = 0;
        rm = 0;
        FillInc();
        L = 0;
        R = n - 1;
        QuickSort1(L, R);
        int r3 = rm;
        rt = 0;
        rm = 0;
        printf("|%8d|%8d|%8d|%8d|%8d|%8d|%8d|\n", n, r1, r2, r3, r4, r5, r6);
    }
    printf("|////////|////////|////////|////////|////////|////////|////////|\n");
    free(A);
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

void QuickSort1(int L, int R)
{
    rt++;
    if (rt > rm)
        rm = rt;

    if (L >= R)
    {
        rt--;
    }
    int x = A[L];
    int i = L;
    int j = R;
    while (i <= j)
    {
        for (; A[i] < x; i++)
        {
            C++;
        }
        if (i <= R)
            C++;
        for (; A[j] > x; j--)
        {
            C++;
        }
        if (j >= L)
            C++;
        if (i <= j)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
            M += 3;
        }
    }
    if (L < j)
    {
        QuickSort1(L, j);
    }
    if (i < R)
    {
        QuickSort1(i, R);
    }
    rt--;
}
void QuickSort2(int L, int R)
{
    rt++;
    if (rt > rm)
        rm = rt;
    while (L < R)
    {
        int x = A[L];
        int i = L;
        int j = R;

        while (i <= j)
        {
            for (; A[i] < x; i++)
                C++;
            if (i <= R)
                C++;
            for (; A[j] > x; j--)
                C++;
            if (j >= L)
                C++;
            if (i <= j)
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i++;
                j--;
            }
        }

        if (j - L < R - i)
        {
            if (L < j)
            {
                QuickSort2(L, j);
            }
            L = i;
        }

        else
        {
            if (i < R)
            {
                QuickSort2(i, R);
            }
            R = j;
        }
    }
    rt--;
}
