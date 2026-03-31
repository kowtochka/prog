#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

struct School
{
    int number;
    int graduate;
    int applicants;
};

void ShellSort(struct School *R, int *L);
void PrintStruct(struct School *A, int *L);

int main(int argc, char const *argv[])
{
    struct School List[]{{86, 60, 60},
                         {15, 100, 60},
                         {20, 90, 50},
                         {57, 80, 30},
                         {25, 75, 40},
                         {10, 95, 55},
                         {30, 85, 45},
                         {3, 70, 20},
                         {2, 88, 44},
                         {7, 60, 25},
                         {1, 99, 33}

    };

    int B[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Исходный массив\n");
    PrintStruct(List, B);
    printf("Отсортированный массив\n");
    ShellSort(List, B);
    PrintStruct(List, B);
    return 0;
}

void ShellSort(struct School *R, int *L)
{
    int m = 1;
    int H[m];
    H[0] = 1;
    int temp;
    for (int i = 2; i < m + 1; i++)
    {
        H[i - 1] = 2 * H[i - 2] + 1;
    }
    for (int l = m - 1; l >= 0; l--)
    {
        int k = H[l];
        for (int i = k; i < 11; i++)
        {
            temp = L[i];
            int j = i - k;
            for (; j >= 0 && ((double)R[temp].applicants / (double)R[temp].graduate) < ((double)R[L[j]].applicants / (double)R[L[j]].graduate);)
            {
                L[j + k] = L[j];
                j = j - k;
            }
            L[j + k] = temp;
        }
    }
}
void PrintStruct(struct School *A, int *L)
{
    for (int i = 0; i < 11; i++)
        std::cout << "Номер школы: " << A[L[i]].number << ", Выпустившиеся: " << A[L[i]].graduate << ", Поступившие: " << A[L[i]].applicants << ", Процент поступивших: " << ((double)A[L[i]].applicants / (double)(A[L[i]].graduate) * 100) << std::endl;

    printf("\n");
}
