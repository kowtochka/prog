#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct student
{
    char surname[30];
    int grade[4];
    student *l, *r;
} *t;

void printdown(student *t);
void printup(student *t);
void tree(student *&t, char data[30]);
void find(student *t, char sur[30]);

int main(int argc, char const *argv[])
{
    srand(time(0));
    char surnames[5][30] = {
        "Denezhkina",
        "Illarionov",
        "Abduraimova",
        "Kozik",
        "Milkevich"};
    for (int i = 0; i < 5; i++)
    {
        tree(t, surnames[i]);
    }
    printup(t);
    printf("enter surname to find\n");
    char surn[30];
    scanf("%30s", &surn);
    find(t, surn);
    return 0;
}
void tree(student *&t, char data[30])
{
    if (t == NULL)
    {
        t = new student;
        strcpy(t->surname, data);
        t->l = t->r = NULL;
        for (int j = 0; j < 4; j++)
        {
            t->grade[j] = rand() % 4 + 2;
        }
        return;
    }
    if (strcmp(data, t->surname) < 0)
        tree(t->l, data);
    else
        tree(t->r, data);
}
void printup(student *t)
{
    if (!t)
        return;
    printup(t->l);
    printf("%12s   ", t->surname);
    for (int j = 0; j < 4; j++)
    {
        printf("%d ", t->grade[j]);
    }
    printf("\n");
    printup(t->r);
}
void printdown(student *t)
{
    if (!t)
        return;
    printdown(t->r);
    printf("%12s   ", t->surname);
    for (int j = 0; j < 4; j++)
    {
        printf("%d ", t->grade[j]);
    }
    printf("\n");
    printdown(t->l);
}

void find(student *t, char sur[30])
{
    if (t)
    {
        if (strcmp(sur, t->surname) == 0)
        {
            printf("%p\n", t);
        }
        else if (strcmp(sur, t->surname) > 0)
        {
            find(t->r, sur);
        }
        else if (strcmp(sur, t->surname) < 0)
        {
            find(t->l, sur);
        }
    }
    else
    {
        printf("nothing\n");
    }
}
