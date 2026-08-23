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
    long long hStr = 0;
    long long hText = 0;
    long long pow256 = 1;
    for (int i = 0; i < m - 1; i++)
        pow256 = (pow256 * 256) % k;
    for (int i = 0; i < m; i++)
    {
        hStr += str[i] * int(pow(256, m - i - 1));
    }
    hStr = hStr % k;
    for (int i = 0; i < m; i++)
    {
        hText += text[i] * int(pow(256, m - i - 1));
    }
    hText = hText % k;
    for (int i = 0; i < (n - m + 1); i++)
    {
        if (hText == hStr)
        {
            int check = 0;
            for (int j = 0; j < m; j++)
            {
                if (text[j + i] == str[j])
                    check++;
            }
            if (check == m)
                return i;
        }
        hText = (256 * (hText - text[i] * pow256) + text[i + m]) % k;
    }
    return -1;
}