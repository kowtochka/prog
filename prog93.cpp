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

int main(int argc, char const *argv[])
{
    srand(time(0));
    char surnames[5][30] = {
        "Denezhkina  ",
        "Illarionov  ",
        "Abduraimova ",
        "Kozik       ",
        "Milkevich   "};
    for (int i = 0; i < 5; i++)
    {
        tree(t, surnames[i]);
    }
    printup(t);
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
    printf("%s   ", t->surname);
    for (int j = 0; j < 4; j++)
    {
        printf("%d ", t->grade[j]);
    }
    printup(t->r);
}
void printdown(student *t)
{
    if (!t)
        return;
    printdown(t->r);
    printf("%s   ", t->surname);
    for (int j = 0; j < 4; j++)
    {
        printf("%d ", t->grade[j]);
    }
    printdown(t->l);
}
