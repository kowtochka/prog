#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cstring>
#include <time.h>

char texts[550] = {"Jo sank into her favorite low seat with a calm, serious expression that suited her best of all, while Laurie, leaning on the back of her chair so that his chin was level with her curly head, smiled with the friendliest of looks and nodded to her from the tall mirror in which they were both reflected."};
int C = 0;

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
    printf("Кол-во посимволных сравнений: %d\n", C);
    printf("\nВведите искомую подстроку:\n");
    char *needle1 = new char[50];
    scanf("%s", needle1);
    int start1 = Carp(needle1, texts);
    if (start1 != -1)
        printf("Индекс начала подстроки: %d\n", start1);
    else
        printf("Подстрока не найдена\n%d", start1);
    printf("Кол-во посимволных сравнений: %d\n", C);

    return 0;
}

int SelectSearch(char *str, char *text)
{
    C = 0;
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
            C++;
            j++;
        }
        C++;
    } while (j != m && i < n - m);
    if (i + n - m && j != m)
        i = -1;
    return i;
}

int hash(char *str, int start, int m)
{
    int k = 19;
    int h = 0;
    for (int i = start; i < m + start; i++)
    {
        h = (h * 256 + str[i]) % k;
    }
    return h;
}

int Carp(char *str, char *text)
{
    C = 0;
    int n = strlen(text);
    int m = strlen(str);
    int hash_str = hash(str, 0, m);
    int hash_text = hash(text, 0, m);
    for (int i = 0; i < (n - m); i++)
    {
        if (hash_str == hash_text)
        {
            for (int j = 0; j < m; j++)
            {
                C++;
                if (text[i + j] != str[j])
                    break;
                if (j == m - 1)
                    return i;
            }
        }
        hash_text = hash(text, i + 1, m);
    }
    return -1;
}