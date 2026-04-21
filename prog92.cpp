#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct student
{
    char surname[30];
    int grade[4];
    student *next, *prev;
} *head, *p, *tail, *t1, *t2;

int main(int argc, char const *argv[])
{
    int flag;
    srand(time(0));
    char surnames[5][30] = {"Abduraimova", "Illarionov", "Denezhkina", "Kozik", "Milkevich"};
    head = tail = new student;
    tail->next = tail->prev = NULL;
    for (int i = 0; i < 5; i++)
    {
        p = new student;
        strcpy(p->surname, surnames[i]);
        for (int j = 0; j < 4; j++)
        {
            p->grade[j] = rand() % 4 + 2;
        }
        p->prev = tail;
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
    for (p = head->next; p; p = p->next)
    {
        printf("%s  ", p->surname);
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", p->grade[j]);
        }
        printf("\n");
    }
    for (p = head; p; p = p->next)
    {
        for (int i = 0; i < 4; i++)
        {
            if (p->grade[i] == 2)
            {
                if (p->next)
                {
                    p->next->prev = p->prev;
                    p->prev->next = p->next;
                    delete (p);
                }
                else
                {
                    p->prev->next = p->next;
                    delete (p);
                }
                break;
            }
        }
    }
    printf("\n");
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
