#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct student
{
    char surname[30];
    int grade[4];
    student *next, *prev;
} *head, *p, *tail;

int main(int argc, char const *argv[])
{
    int flag;
    srand(time(0));
    char surnames[5][30] = {"Abduraimova ", "Illarionov  ", "Denezhkina  ", "Kozik       ", "Milkevich   "};
    head = tail = new student;
    tail->next = NULL;
    for (int i = 0; i < 5; i++)
    {
        p = new student;
        strcpy(p->surname, surnames[i]);
        for (int j = 0; j < 4; j++)
        {
            p->grade[j] = rand() % 4 + 2;
        }
        tail->next = p;
        tail = p;
    }
    do
    {
        flag = 0;
        for (p = head; p->next->next; p = p->next)
        {
            t1 = p->next;
            t2 = t1->next;
            if (strcmp(t1->surname, t2->surname) > 0)
            {
                t1->next = t2;
                t2
                    flag = 1;
            }
        }
    } while (flag);
    tail->next = NULL;
    for (p = head->next; p; p = p->next)
    {
        printf("%s  ", p->surname);
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", p->grade[j]);
        }
        printf("\n");
    }
    return 0;
}
