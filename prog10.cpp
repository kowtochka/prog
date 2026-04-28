#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct trees
{
    char data[30];
    trees *l, *r;
} *t = NULL;

void printup(trees *t);
void printin(trees *t, FILE *f);
void tree(trees *&t, char dats[30]);

int main(int argc, char const *argv[])
{
    FILE *file1, *file2;
    char ch, word[30];
    int i = 0;
    file1 = fopen("ssss", "r");
    while ((ch = getc(file1)) != EOF)
    {
        if (ch == ' ' || ch == '\n')
        {
            if (i > 0)
            {
                word[i] = '\0';
                tree(t, word);
                i = 0;
            }
        }
        else
        {
            word[i++] = ch;
        }
    }
    if (i > 0)
    {
        word[i] = '\0';
        tree(t, word);
    }
    fclose(file1);
    printup(t);
    file2 = fopen("file3", "w");
    printin(t, file2);
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
    printf("%s ", t->data);
    printup(t->r);
}
void printin(trees *t, FILE *f)
{
    if (!t)
        return;
    printin(t->l, f);
    fputs(t->data, f);
    fputs(" ", f);
    printin(t->r, f);
}