#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct list
{
    list *next;
    union
    {
        int data;
        unsigned char Digit[sizeof(int)];
    };

} *p, *S;
struct queue
{
    list *head;
    list *tail;
} *t;

int n = 10;

void FillUpStack(list *&h);
void FillDownStack(list *&h);
void FillDownStack(list *&h);
void FillRandStack(list *&h);
void FillUpQueue(list *&h, list *&t);
void FillDownQueue(list *&h, list *&t);
void FillRandQueue(list *&h, list *&t);
void Print(list *h);
int Sum(list *h);
int Ser(list *h);
void DelList(list *&h);
void PrintRf(list *h);
void PrintRfBack(list *h);

void FillUpStack(list *&h)
{
    for (int i = 1; i <= n; i++)
    {
        p = new list;
        p->data = i;
        p->next = h;
        h = p;
    }
}
void FillDownStack(list *&h)
{
    for (int i = n; i > 0; i--)
    {
        p = new list;
        p->data = i;
        p->next = h;
        h = p;
    }
}
void FillRandStack(list *&h)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        p = new list;
        p->data = rand() % n;
        p->next = h;
        h = p;
    }
}

void FillUpQueue(queue *&t)
{
    for (int i = 1; i <= n; i++)
    {
        p = new list;
        p->data = i;
        p->next = NULL;
        if (t->head != NULL)
        {
            t->tail->next = p;
        }
        else
        {
            t->head = p;
        }
        t->tail = p;
    }
}
void FillDownQueue(list *&h, list *&t)
{
    for (int i = n; i > 0; i--)
    {
        p = new list;
        p->data = i;
        p->next = NULL;
        if (h != NULL)
        {
            t->next = p;
        }
        else
        {
            h = p;
        }
        t = p;
    }
}
void FillRandQueue(list *&h, list *&t)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        p = new list;
        p->data = rand() % n + 1;
        p->next = NULL;
        if (h != NULL)
        {
            t->next = p;
        }
        else
        {
            h = p;
        }
        t = p;
    }
}
void Print(list *h)
{
    if (h)
    {
        for (p = h; p; p = p->next)
        {
            printf("%d ", p->data);
        }
        printf("\n");
    }
    else
        printf("nothing\n");
}
int Sum(list *h)
{
    int sum = 0;
    for (p = h->next; p; p = p->next)
    {
        sum += p->data;
    }
    return sum;
}
int Ser(list *h)
{
    int s = 1;
    for (p = h->next; p->next; p = p->next)
    {
        if (p->data > p->next->data)
        {
            s++;
        }
    }
    return s;
}
void DelList(list *&h)
{
    for (p = h; p; p = h)
    {
        h = p->next;
        delete (p);
    }
}
void PrintRf(list *h)
{
    if (h)
    {
        p = h;
        printf("%d ", p->data);
        PrintRf(p->next);
    }
    else
        return;
}
void PrintRfBack(list *h)
{
    if (h)
    {
        p = h;
        int temp = p->data;
        PrintRfBack(p->next);

        printf("%d ", temp);
    }
    else
        return;
}