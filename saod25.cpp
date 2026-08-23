#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cstring>
#include <time.h>

char texts[550] = {"Jo sank into her favorite low seat with a calm, serious expression that suited her best of all, while Laurie, leaning on the back of her chair so that his chin was level with her curly head, smiled with the friendliest of looks and nodded to her from the tall mirror in which they were both reflected."};
int k = 13;

int hash(char *str, int m);
int SelectSearch(char *str, char *text);
int Carp(char *str, char *text);

int main(int argc, char const *argv[])
{
    printf("Исходный текст:\n");
    for (int i = 0; i < strlen(texts); i++)
    {
        printf("%c", texts[i]);
    }
    printf("\nВведите искомую подстроку:\n");
    char *needle = new char[50];
    scanf("%s", needle);
    int start = SelectSearch(needle, texts);
    if (start != -1)
        printf("Индекс начала подстроки: %d\n", start);
    else
        printf("Подстрока не найдена\n");
    printf("\nВведите искомую подстроку:\n");
    char *needle1 = new char[50];
    scanf("%s", needle1);
    int start1 = Carp(needle1, texts);
    if (start1 != -1)
        printf("Индекс начала подстроки: %d\n", start1);
    else
        printf("Подстрока не найдена\n");
    return 0;
}
int hash(char *str, int m)
{
    int h = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        h = (h * 256 + str[i]) % m;
    }
    return h;
}
int SelectSearch(char *str, char *text)
{
    int m = strlen(str);
    int n = strlen(text);
    int i = -1;
    int j;
    do
    {
        i++;
        j = 0;
        while (j < m && text[i + j] == str[j])
        {
            j++;
        }
    } while (j != m && i < n - m);
    if (i + n - m && j != m)
        i = -1;
    return i;
}
int Carp(char *str, char *text)
{
    int m = strlen(str);
    int n = strlen(text);

    if (m == 0 || m > n)
        return -1;

    long long hStr = 0;   // хеш образца
    long long hText = 0;  // хеш текущего окна
    long long pow256 = 1; // будет 256^(m-1) % k

    // 1. Предвычисляем 256^(m-1) % k
    for (int i = 0; i < m - 1; i++)
        pow256 = (pow256 * 256) % k;

    // 2. Считаем начальные хеши образца и первого окна текста
    for (int i = 0; i < m; i++)
    {
        hStr = (hStr * 256 + (unsigned char)str[i]) % k;
        hText = (hText * 256 + (unsigned char)text[i]) % k;
    }

    // 3. Скользим по тексту
    for (int i = 0; i <= n - m; i++)
    {
        if (hText == hStr)
        {
            // точная проверка (защита от коллизий)
            int match = 1;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != str[j])
                {
                    match = 0;
                    break;
                }
            }
            if (match)
                return i;
        }

        // 4. Пересчитываем хеш для СЛЕДУЮЩЕГО окна за O(1)
        if (i < n - m) // обновляем только если следующее окно существует
        {
            // вычитаем "вылетающий" левый символ (его вес = 256^(m-1))
            long long val = hText - ((unsigned char)text[i] * pow256) % k;
            if (val < 0)
                val += k; // фикс отрицательного остатка

            // сдвигаем окно (умножаем на 256) и прибавляем новый правый символ
            hText = (val * 256 + (unsigned char)text[i + m]) % k;
        }
    }

    return -1;
}