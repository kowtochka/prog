#include "saod21.cpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
void DigitalSort(int L, list *S, list *&p);
int main()
{
    list *i, *j;
    FillUpStack(i);
    DigitalSort(4, i, j);
    PrintRf(i);
    printf("\n");
    PrintRf(j);
    printf("\n");
    return 0;
}
void DigitalSort(int L, list *S, list *&p)
{
    for (int j = L; j > 1; j--)
    {
        queue Q[255];
        for (int i = 0; i < 255; i++)
        {
            Q[i].tail = Q[i].head = NULL;
        }
        p = S;
        while (p)
        {
            int d = p->Digit[j];
            Q[d].tail->next = p;
            Q[d].tail = p;
            p = p->next;
        }
        p = S;
        for (int i = 0; i < 255; i++)
        {
            if (Q[i].tail != Q[i].head)
            {
                p->next = Q[i].head;
                p = Q[i].tail;
            }
        }
        p->next = NULL;
    }
}