#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

bool Less(int k1, int k2);
void LessSurname(struct phone x, struct phone y);
void LessName(struct phone x, struct phone y);
void LessEmail(struct phone x, struct phone y);
void LessPhone(struct phone x, struct phone y);

int k1, k2;
int j;
char *find;
struct phone
{
    char surname[20];
    char name[20];
    char email[40];
    long phone;
};
struct phone temp;
struct phone A[5] = {{"Agalakov", "Artur", "Legenda@gmail.com", 78005553535},
                     {"Shvartskop", "Tatyana", "KazahstanCat@gmail.com", 79135468742},
                     {"Agaboldin", "Vlad", "Starichok@gmail.com", 77778923842},
                     {"Fatkudinov", "Roman", "Nachalnik@gmail.com", 76665554433},
                     {"Agalakov", "Anton", "BigBoss@gmail.com", 79895643245}};
void ShellSort();
void ShellSortNaoborot();
void PrintStruct();
int res = -1;

int main(int argc, char const *argv[])
{

    printf("Исходный массив:\n");
    PrintStruct();
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
        ShellSort();
        PrintStruct();
        printf("Хотите найти абонента?  y/n\n");
        char kkk;
        scanf("%s", &kkk);
        if (kkk == 'y')
        {
            printf("Введите предмет ключа сортировки\n");

            scanf("%s", find);
        }
        break;
    case 1:
        printf("По какому ключу?\n");
        printf("1. Фамилия\n");
        printf("2. Имя\n");
        printf("3. Почта\n");
        printf("4. Номер телефона\n");
        scanf("%d%d", &k1, &k2);
        ShellSortNaoborot();
        PrintStruct();
        break;
    }
    return 0;
}

void ShellSort()
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
            temp = A[i];
            j = i - k;
            for (; j >= 0 && Less(k1, k2);)
            {
                A[j + k] = A[j];
                j = j - k;
            }
            A[j + k] = temp;
        }
    }
}

void ShellSortNaoborot()
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
            temp = A[i];
            j = i - k;
            for (; j >= 0 && Less(k1, k2) == 0;)
            {
                A[j + k] = A[j];
                j = j - k;
            }
            A[j + k] = temp;
        }
    }
}

bool Less(int k1, int k2)
{
    res = -1;
    switch (k1)
    {
    case 1:
        LessSurname(temp, A[j]);
        break;
    case 2:
        LessName(temp, A[j]);
        break;
    case 3:
        LessEmail(temp, A[j]);
        break;
    case 4:
        LessPhone(temp, A[j]);
        break;
    }
    if (res == -1)
    {
        switch (k2)
        {
        case 1:
            LessSurname(temp, A[j]);
            break;
        case 2:
            LessName(temp, A[j]);
            break;
        case 3:
            LessEmail(temp, A[j]);
            break;
        case 4:
            LessPhone(temp, A[j]);
            break;
        }
    }
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

void PrintStruct()
{
    for (int i = 0; i < 5; i++)
        std::cout << A[i].surname << " " << A[i].name << ", Phone: " << A[i].phone << ", Email: " << A[i].email << std::endl;

    printf("\n");
}