#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

struct list
{
    list *next;
    int data;
} *p, *head_a, *head_b, *head_c, *tail_a, *tail_b, *tail_c, *head_c1, *tail_c1, *head_c2, *tail_c2;

int n = 25;
int M = 0;
int C = 0;
int teorM, teorC;
void merge(list *&a, list *&b, int &q, int &r, list *&c, list *&c1);
void crash(list *S, list *&a, list *&b, int &n);
void mergeSort(list *&S, list *a, list *b, int n);
void addElement(list *&a, list *&c, list *&c1);
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

int main(int argc, char const *argv[])
{
    srand(time(0));
    printf("\n");
    FillRandQueue(head_a, tail_a);
    mergeSort(head_a, head_b, head_c, n);
    printf("%d, %d", C, M);
    printf("\n");
    printf("\n");
    printf("|////////|////////|//////////////////////////|\n");
    printf("|   N    |  M+C   |         Mф+Сф            |\n");
    printf("|        |  теор. | Убыв.  | Случ.  |Возр .  |\n");
    printf("|////////|////////|////////|////////|////////|\n");

    for (n = 100; n < 600; n += 100)
    {

        teorM = n * (int)ceil(log2(n));
        teorC = n * (int)ceil(log2(n));
        FillDownQueue(head_a, tail_a);
        mergeSort(head_a, head_b, head_c, n);
        int MDec = M;
        int CDec = C;
        FillRandQueue(head_a, tail_a);
        mergeSort(head_a, head_b, head_c, n);
        int MRand = M;
        int CRand = C;
        FillUpQueue(head_a, tail_a);
        mergeSort(head_a, head_b, head_c, n);
        int MInc = M;
        int CInc = C;
        printf("|%8d|%8d|%8d|%8d|%8d|\n", n, teorM + teorC, MDec + CDec, MRand + CRand, MInc + CInc);
    }
    printf("|////////|////////|////////|////////|////////|\n");

    return 0;
}

void crash(list *S, list *&a, list *&b, int &n)
{
    list *k, *p;
    a = S;
    b = S->next;
    M += 4;
    n = 1;
    k = a;
    p = b;
    while (p)
    {
        n++;
        M += 2;
        k->next = p->next;
        k = p;
        p = p->next;
    }
}
void merge(list *&a, list *&b, int &q, int &r, list *&c, list *&c1)
{

    while (q != 0 && r != 0)
    {
        C++;
        if (a->data <= b->data)
        {
            addElement(a, c, c1);
            q--;
        }
        else
        {
            addElement(b, c, c1);
            r--;
        }
    }
    while (q > 0)

    {
        addElement(a, c, c1);
        q--;
    }

    while (r > 0)

    {
        addElement(b, c, c1);
        r--;
    }
}
void mergeSort(list *&S, list *a, list *b, int n)
{
    M = 0;
    C = 0;
    crash(S, a, b, n);
    int p = 1;
    int q, r;
    list *ch[] = {head_c1, head_c2};
    list *ct[] = {tail_c1, tail_c2};
    while (p < n)
    {
        ch[0] = ct[0] = NULL;
        ch[1] = ct[1] = NULL;
        int i = 0;
        int m = n;
        while (m > 0)
        {
            if (m >= p)
            {
                q = p;
            }
            else
            {
                q = m;
            }
            m = m - q;
            if (m >= p)
            {
                r = p;
            }
            else
            {
                r = m;
            }
            m = m - r;
            merge(a, b, q, r, ch[i], ct[i]);
            i = 1 - i;
        }
        a = ch[0];
        b = ch[1];
        p = 2 * p;
    }
    ct[0]->next = NULL;
    S = ch[0];
}
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
void delElement(list *&a)
{
    list *temp;
    temp = a;
    a = a->next;
    delete (temp);
}
void addElement(list *&a, list *&c, list *&c1)
{
    p = new list;
    p->data = a->data;
    M++;
    p->next = NULL;
    delElement(a);
    if (c != NULL)
    {
        c1->next = p;
    }
    else
    {
        c = p;
    }
    c1 = p;
}
void FillRandStack(list *&h)
{
    for (int i = 0; i < n; i++)
    {
        p = new list;
        p->data = rand() % n;
        p->next = h;
        h = p;
    }
}

void FillUpQueue(list *&h, list *&t)
{
    for (int i = 1; i <= n; i++)
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