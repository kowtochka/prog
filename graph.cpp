#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <time.h>

struct list
{
    list *next;
    int data;
} *p, *head_a, *head_b, *head_c, *tail_a, *tail_b, *tail_c, *head_c1, *tail_c1, *head_c2, *tail_c2;

void merge(list *&a, list *&b, int &q, int &r, list *&c, list *&c1);
void crash(list *S, list *&a, list *&b, int &n);
void mergeSort(list *&S, list *a, list *b, int n);
void FillRand();
void QuickSort2(int L, int R);
void FillRandQueue(list *&h, list *&t);
void swap(int &a, int &b);
void delElement(list *&a);
void addElement(list *&a, list *&c, list *&c1);

int C = 0, M = 0, n = 1;
int A[100000];

int main(int argc, char const *argv[])
{
    sf::Font font;
    font.loadFromFile("Arial.ttf");
    sf::Text xLabel;
    xLabel.setFont(font);
    xLabel.setString("n");
    xLabel.setCharacterSize(20);
    xLabel.setFillColor(sf::Color::Red);
    xLabel.setPosition(1300, 730);

    sf::Text yLabel;
    yLabel.setFont(font);
    yLabel.setString("C+M");
    yLabel.setCharacterSize(20);
    yLabel.setFillColor(sf::Color::Red);
    yLabel.setPosition(25, 25);

    sf::Text Shell;
    Shell.setFont(font);
    Shell.setString("Merge - Rainbow");
    Shell.setCharacterSize(20);
    Shell.setFillColor(sf::Color::White);
    Shell.setPosition(100, 60);

    sf::Text Quick;
    Quick.setFont(font);
    Quick.setString("Quick - Green");
    Quick.setCharacterSize(20);
    Quick.setFillColor(sf::Color::Green);
    Quick.setPosition(100, 120);

    srand(time(0));
    const int POINTS_COUNT = 1300;
    sf::VertexArray graphMerge(sf::LineStrip, POINTS_COUNT);
    sf::VertexArray graphQuick(sf::LineStrip, POINTS_COUNT);
    sf::RenderWindow win(sf::VideoMode(1366, 768), "Test");

    sf::Vertex y[] =
        {
            sf::Vertex(sf::Vector2f(50, 700), sf::Color::Red),
            sf::Vertex(sf::Vector2f(50, 50), sf::Color::Blue)};
    sf::Vertex x[] =
        {
            sf::Vertex(sf::Vector2f(50, 700), sf::Color::Red),
            sf::Vertex(sf::Vector2f(1260, 700), sf::Color::Blue)};
    sf::Vertex xp[] =
        {
            sf::Vertex(sf::Vector2f(1230, 670), sf::Color::Blue),
            sf::Vertex(sf::Vector2f(1260, 700), sf::Color::Blue),
            sf::Vertex(sf::Vector2f(1230, 730), sf::Color::Blue)};
    sf::Vertex yp[] =
        {
            sf::Vertex(sf::Vector2f(20, 80), sf::Color::Blue),
            sf::Vertex(sf::Vector2f(50, 50), sf::Color::Blue),
            sf::Vertex(sf::Vector2f(80, 80), sf::Color::Blue)};

    // ============= MERGE SORT =============
    for (n = 1; n < POINTS_COUNT; n++)
    {
        head_a = tail_a = NULL;
        FillRandQueue(head_a, tail_a);
        C = 0;
        M = 0;
        mergeSort(head_a, head_b, head_c, n);

        float x = n + 50;
        float y = 700 - (C + M) / 150.0f;

        graphMerge[n].position = sf::Vector2f(x, y);
        switch (rand() % 8)
        {
        case 1:
            graphMerge[n].color = sf::Color::Red;
            break;
        case 2:
            graphMerge[n].color = sf::Color::Yellow;
            break;
        case 3:
            graphMerge[n].color = sf::Color::Yellow;
            break;
        case 4:
            graphMerge[n].color = sf::Color::Green;
            break;
        case 5:
            graphMerge[n].color = sf::Color::Cyan;
            break;
        case 6:
            graphMerge[n].color = sf::Color::Blue;
            break;
        case 7:
            graphMerge[n].color = sf::Color::Magenta;
            break;
        }
    }
    graphMerge[0].position = sf::Vector2f(50, 700);
    graphMerge[0].color = sf::Color::White;

    // ============= QUICK SORT =============
    for (n = 1; n < POINTS_COUNT; n++)
    {
        FillRand();
        C = 0;
        M = 0;
        int L = 0;
        int R = n - 1;
        QuickSort2(L, R);

        float x = n + 50;
        float y = 700 - (C + M) / 150.0f;

        graphQuick[n].position = sf::Vector2f(x, y);
        graphQuick[n].color = sf::Color::Green;
    }
    graphQuick[0].position = sf::Vector2f(50, 700);
    graphQuick[0].color = sf::Color::Green;

    while (win.isOpen())
    {
        win.setFramerateLimit(60);
        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();
        }
        win.clear(sf::Color::Black);
        win.draw(xLabel);
        win.draw(yLabel);
        win.draw(x, 2, sf::Lines);
        win.draw(y, 2, sf::Lines);
        win.draw(xp, 3, sf::LineStrip);
        win.draw(yp, 3, sf::LineStrip);
        win.draw(graphMerge);
        win.draw(graphQuick);
        win.draw(Shell);
        win.draw(Quick);
        win.display();
    }
    return 0;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void FillRand()
{
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % (2 * n + 1);
    }
}

void QuickSort2(int L, int R)
{
    while (L < R)
    {
        int x = A[L];
        int i = L;
        int j = R;

        while (i <= j)
        {
            for (; A[i] < x; i++)
                C++;
            if (i <= R)
                C++;
            for (; A[j] > x; j--)
                C++;
            if (j >= L)
                C++;
            if (i <= j)
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i++;
                j--;
            }
        }

        if (j - L < R - i)
        {
            if (L < j)
            {
                QuickSort2(L, j);
            }
            L = i;
        }
        else
        {
            if (i < R)
            {
                QuickSort2(i, R);
            }
            R = j;
        }
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

void crash(list *S, list *&a, list *&b, int &n)
{
    list *k, *p;
    a = S;
    M += 4;
    b = S->next;
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

    crash(S, a, b, n);
    int p = 1;
    int q, r;

    list *head1 = NULL, *tail1 = NULL;
    list *head2 = NULL, *tail2 = NULL;

    while (p < n)
    {
        head1 = tail1 = NULL;
        head2 = tail2 = NULL;
        int i = 0;
        int m = n;

        while (m > 0)
        {
            if (m >= p)
                q = p;
            else
                q = m;
            m = m - q;

            if (m >= p)
                r = p;
            else
                r = m;
            m = m - r;

            if (i == 0)
                merge(a, b, q, r, head1, tail1);
            else
                merge(a, b, q, r, head2, tail2);

            i = 1 - i;
        }

        if (tail1 != NULL)
            tail1->next = head2;

        a = head1;
        b = head2;
        p = 2 * p;
    }

    if (tail1 != NULL)
        tail1->next = NULL;

    S = head1;
}

void FillRandQueue(list *&h, list *&t)
{
    h = t = NULL;
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
// g++ graph.cpp -ISFML -lsfml-graphics -lsfml-window -lsfml-system -o fzar.o