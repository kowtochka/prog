#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cstring>
#include <time.h>
int m = 29;
int simple[10] = {11, 13, 17, 19, 23, 29, 53, 61, 73, 101};
struct list
{
    char *string;
    list *next;
};
void random(char *res, int length);
int hash(char *str, int m);
void tableAdd(list *s, list *table[]);

int main(int argc, char const *argv[])
{
    int col = 0;
    srand(time(0));
    list *h = NULL;
    int len = 7;
    for (int s = 0; s < 100; s++)
    {
        list *p = new list;
        p->string = (char *)malloc(len + 1);
        random(p->string, len);
        p->next = h;
        h = p;
    }

    printf("\n");
    printf("\n");
    printf("|//////////////////////////|\n");
    printf("| Размер | Кол-во | Кол-во |\n");
    printf("|        |  Исх.  |   Кол. |\n");
    printf("|////////|////////|////////|\n");

    for (int i = 0; i < 10; i++)
    {

        m = simple[i];
        list *table[m];
        col = 0;
        for (int i = 0; i < m; i++)
            table[i] = NULL;
        tableAdd(h, table);
        for (int i = 0; i < m; i++)
        {
            int cl = -1;
            for (list *p = table[i]; p; p = p->next)
            {
                cl++;
            }
            if (cl != -1)
            {
                col += cl;
            }
        }
        printf("|%8d|%8d|%8d|\n", m, len, col);
    }
    printf("|////////|////////|////////|\n");
    printf("\n");
    printf("\n");

    return 0;
}

void random(char *res, int length)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < length; ++i)
    {
        int j = rand() % (sizeof(charset) - 1);
        res[i] = charset[j];
    }
    res[length] = '\0';
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

void tableAdd(list *s, list *table[])
{
    for (list *c = s; c != NULL; c = c->next)
    {
        list *l;
        int h = hash(c->string, m);
        l = table[h];
        list *p = new list;
        p->string = new char[strlen(c->string) + 1];
        strcpy(p->string, c->string);
        p->next = l;
        table[h] = p;
    }
}