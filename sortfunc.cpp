#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
int n = 10;

void SelectSort(int *A, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[k])
            {
                k = j;
            }
        }
        int move = A[i];
        A[i] = A[k];
        A[k] = move;
    }
}
void SelectSort(float *A, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[k])
            {
                k = j;
            }
        }
        float move = A[i];
        A[i] = A[k];
        A[k] = move;
    }
}
void ShellSort(int *A, int n)
{
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
    for (int l = m - 1; l >= 0; l--)
    {
        k = H1[l];
        for (int i = k; i < n; i++)
        {
            int temp = A[i];
            int j = i - k;
            if (A[j] < temp)
                for (; j >= 0 && temp < A[j];)
                {
                    A[j + k] = A[j];
                    j = j - k;
                }
            A[j + k] = temp;
        }
    }
}
void ShellSort(float *A, int n)
{
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
    for (int l = m - 1; l >= 0; l--)
    {
        k = H1[l];
        for (int i = k; i < n; i++)
        {
            float temp = A[i];
            int j = i - k;
            if (A[j] < temp)
                for (; j >= 0 && temp < A[j];)
                {
                    A[j + k] = A[j];
                    j = j - k;
                }
            A[j + k] = temp;
        }
    }
}
void BubbleSort(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (A[j] < A[j - 1])
            {
                int temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
            }
        }
    }
}
void BubbleSort(float *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (A[j] < A[j - 1])
            {
                float temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
            }
        }
    }
}

template <typename T>
float timer(void (*tip_sort)(T *, int), T *a, int n)
{
    clock_t start, end;
    start = clock();
    tip_sort(a, n);
    end = clock();
    float time_spent = ((float)(end - start) / CLOCKS_PER_SEC) * 1000.0f;
    return time_spent;
}