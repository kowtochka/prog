#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

bool Less(int key, int *L);
void LessSurname(struct phone x, struct phone y);
void LessName(struct phone x, struct phone y);
void LessEmail(struct phone x, struct phone y);
void LessPhone(struct phone x, struct phone y);

int k1, k2;
int j;
char *find;
const int z = 5;
struct phone
{
    char surname[20];
    char name[20];
    char email[40];
    long phone;
};
int temp;
struct phone A[z] = {{"Agalakov", "Artur", "Legenda@gmail.com", 78005553535},
                     {"Shvartskop", "Tatyana", "KazahstanCat@gmail.com", 79135468742},
                     {"Agaboldin", "Vlad", "Starichok@gmail.com", 77778923842},
                     {"Fatkudinov", "Roman", "Nachalnik@gmail.com", 76665554433},
                     {"Agalakov", "Anton", "BigBoss@gmail.com", 79895643245}};
void ShellSort(int *L, int key);
void ShellSortNaoborot(int *L, int key);
void PrintStruct(int *L);
int res = -1;
int B[z] = {0, 1, 2, 3, 4};
int C[z] = {0, 1, 2, 3, 4};

int main(int argc, char const *argv[])
{

    printf("Исходный массив:\n");
    PrintStruct(B);
    printf("Выберите вариант действий\n");
    printf("0. Отсортировать в порядке возрастания\n");
    printf("1. Отсортировать в порядке убывания\n");
    int p;
    scanf("%d", &p);
    switch (p)
    {
    case 0:
        printf("По какому ключу (в порядке важности)?\n");
        printf("1. Фамилия\n");
        printf("2. Имя\n");
        printf("3. Почта\n");
        printf("4. Номер телефона\n");
        scanf("%d%d", &k1, &k2);
        printf("По первому ключу: \n");
        ShellSort(B, k1);
        PrintStruct(B);
        printf("По второму ключу: \n");
        ShellSort(C, k2);
        PrintStruct(C);
        break;
    case 1:
        printf("По какому ключу?\n");
        printf("1. Фамилия\n");
        printf("2. Имя\n");
        printf("3. Почта\n");
        printf("4. Номер телефона\n");
        scanf("%d%d", &k1, &k2);
        printf("По первому ключу: \n");
        ShellSortNaoborot(B, k1);
        PrintStruct(B);
        printf("По второму ключу: \n");
        ShellSortNaoborot(C, k2);
        PrintStruct(C);
        break;
    }
    return 0;
}

void ShellSort(int *L, int key)
{
    int m = 1;
    int H[m];
    H[0] = 1;
    for (int i = 2; i < m + 1; i++)
    {
        H[i - 1] = 2 * H[i - 2] + 1;
    }
    for (int l = m - 1; l >= 0; l--)
    {
        int k = H[l];
        for (int i = k; i < 5; i++)
        {
            temp = L[i];
            j = i - k;
            for (; j >= 0 && Less(key, L);)
            {
                L[j + k] = L[j];
                j = j - k;
            }
            L[j + k] = temp;
        }
    }
}

void ShellSortNaoborot(int *L, int key)
{
    int m = 1;
    int H[m];
    H[0] = 1;
    for (int i = 2; i < m + 1; i++)
    {
        H[i - 1] = 2 * H[i - 2] + 1;
    }
    for (int l = m - 1; l >= 0; l--)
    {
        int k = H[l];
        for (int i = k; i < 5; i++)
        {
            temp = L[i];
            j = i - k;
            for (; j >= 0 && Less(key, L) == 0;)
            {
                L[j + k] = L[j];
                j = j - k;
            }
            L[j + k] = temp;
        }
    }
}

bool Less(int key, int *L)
{
    res = -1;
    switch (key)
    {
    case 1:
        LessSurname(A[temp], A[L[j]]);
        break;
    case 2:
        LessName(A[temp], A[L[j]]);
        break;
    case 3:
        LessEmail(A[temp], A[L[j]]);
        break;
    case 4:
        LessPhone(A[temp], A[L[j]]);
        break;
    }
    if (res == -1)
        res = 0;
    return res;
}

void LessSurname(struct phone x, struct phone y)
{
    for (int i = 0; i < 20 && res == -1; i++)
    {
        if (*(x.surname + i) < *(y.surname + i))
            res = 1;
        else if (*(x.surname + i) > *(y.surname + i))
            res = 0;
    }
}

void LessName(struct phone x, struct phone y)
{
    for (int i = 0; i < 20 && res == -1; i++)
    {
        if (*(x.name + i) < *(y.name + i))
            res = 1;
        else if (*(x.name + i) > *(y.name + i))
            res = 0;
    }
}
void LessEmail(struct phone x, struct phone y)
{
    for (int i = 0; i < 40 && res == -1; i++)
    {
        if (*(x.email + i) < *(y.email + i))
            res = 1;
        else if (*(x.email + i) > *(y.email + i))
            res = 0;
    }
}
void LessPhone(struct phone x, struct phone y)
{
    if (x.phone < y.phone)
        res = 1;
    else if (x.phone > y.phone)
        res = 0;
}

void PrintStruct(int *L)
{
    for (int i = 0; i < 5; i++)
        std::cout << A[L[i]].surname << " " << A[L[i]].name << ", Phone: " << A[L[i]].phone << ", Email: " << A[L[i]].email << std::endl;

    printf("\n");
}