#include <cstdio>
#include <cstdlib>
#include <ctime>

int g_rows = 0;
int g_cols = 0;

int **genRandMatrix(int size, int maxValue);
void printMatrix(int **matrix);

int main()
{
    srand(time(0));
    int size = rand() % 10 + 1;
    int **matrix = genRandMatrix(size, 100);
    printMatrix(matrix);

    for (int i = 0; i < g_rows; i++)
        delete[] matrix[i];
    delete[] matrix;
}

int **genRandMatrix(int size, int maxValue)
{
    g_rows = rand() % size + 1;
    g_cols = rand() % size + 1;

    int **p = new int *[g_rows];
    for (int i = 0; i < g_rows; i++)
        p[i] = new int[g_cols];

    for (int i = 0; i < g_rows; i++)
        for (int j = 0; j < g_cols; j++)
            p[i][j] = rand() % maxValue;

    return p;
}

void printMatrix(int **matrix)
{
    printf("\n");
    for (int i = 0; i < g_rows; i++)
    {
        for (int j = 0; j < g_cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}