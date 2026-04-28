#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct trees
{
    char data[30];
    trees *l, *r;
} *t = NULL; // Инициализируем NULL

void printup(trees *t);
void tree(trees *&t, char dats[30]);

int main(int argc, char const *argv[])
{
    FILE *file1;
    char ch;

    file1 = fopen("ssss", "r");
    if (!file1)
    {
        printf("Не удалось открыть файл ssss\n");
        return 1;
    }

    char word[30];
    int i = 0;

    while ((ch = getc(file1)) != EOF) // Правильная проверка
    {
        if (ch == ' ' || ch == '\n')
        { // Разделитель
            if (i > 0)
            { // Если слово не пустое
                word[i] = '\0';
                tree(t, word);
                i = 0;
            }
        }
        else
        {
            if (i < 29)
            { // Защита от переполнения
                word[i++] = ch;
            }
        }
    }

    // Проверяем последнее слово
    if (i > 0)
    {
        word[i] = '\0';
        tree(t, word);
    }

    fclose(file1);

    // Вывод дерева для проверки
    printf("Дерево (симметричный обход):\n");
    printup(t);

    return 0;
}

void tree(trees *&t, char dats[30])
{
    if (t == NULL)
    {
        t = new trees;
        strcpy(t->data, dats);
        t->l = t->r = NULL;
        return;
    }
    if (strcmp(dats, t->data) < 0)
        tree(t->l, dats);
    else
        tree(t->r, dats);
}

void printup(trees *t)
{
    if (!t)
        return;
    printup(t->l);
    printf("%s\n", t->data); // Убрал лишний пробел
    printup(t->r);
}