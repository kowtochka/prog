#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <time.h>

void FillRand();
void heapSort();
void shellSort();
void QuickSort2(int L, int R);

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
    yLabel.setPosition(20, 40);

    sf::Text Shell;
    Shell.setFont(font);
    Shell.setString("Shell - White");
    Shell.setCharacterSize(20);
    Shell.setFillColor(sf::Color::White);
    Shell.setPosition(100, 60);

    sf::Text Heap;
    Heap.setFont(font);
    Heap.setString("Heap - Yellow");
    Heap.setCharacterSize(20);
    Heap.setFillColor(sf::Color::Yellow);
    Heap.setPosition(100, 90);

    sf::Text Quick;
    Quick.setFont(font);
    Quick.setString("Quick - Green");
    Quick.setCharacterSize(20);
    Quick.setFillColor(sf::Color::Green);
    Quick.setPosition(100, 120);

    srand(time(0));
    const int POINTS_COUNT = 1300; // Количество точек
    sf::VertexArray graph(sf::LineStrip, POINTS_COUNT);
    sf::VertexArray graph1(sf::LineStrip, POINTS_COUNT);
    sf::VertexArray graph2(sf::LineStrip, POINTS_COUNT);
    sf::RenderWindow win(sf::VideoMode(1366, 768), "Test");
    sf::Vertex y[] =
        {
            sf::Vertex(sf::Vector2f(50, 700), sf::Color::Red), // Начальная точка (красная)
            sf::Vertex(sf::Vector2f(50, 50), sf::Color::Blue)  // Конечная точка (зеленая)
        };
    sf::Vertex x[] =
        {
            sf::Vertex(sf::Vector2f(50, 700), sf::Color::Red),   // Начальная точка (красная)
            sf::Vertex(sf::Vector2f(1260, 700), sf::Color::Blue) // Конечная точка (зеленая)
        };
    sf::Vertex xp[] =
        {
            sf::Vertex(sf::Vector2f(1230, 670), sf::Color::Blue), // Начальная точка (красная)
            sf::Vertex(sf::Vector2f(1260, 700), sf::Color::Blue),
            sf::Vertex(sf::Vector2f(1230, 730), sf::Color::Blue) // Конечная точка (зеленая)
        };
    sf::Vertex yp[] =
        {
            sf::Vertex(sf::Vector2f(20, 80), sf::Color::Blue), // Начальная точка (красная)
            sf::Vertex(sf::Vector2f(50, 50), sf::Color::Blue),
            sf::Vertex(sf::Vector2f(80, 80), sf::Color::Blue) // Конечная точка (зеленая)
        };
    for (; n < 1300; n++)
    {
        FillRand();
        C = 0;
        M = 0;
        shellSort();
        float x = n + 50;
        float y = 700 - (C + M) / 150;
        graph[n].position = sf::Vector2f(x, y);
    }
    graph[0].position = sf::Vector2f(50, 700);
    n = 1;
    for (; n < 1300; n++)
    {
        FillRand();
        C = 0;
        M = 0;
        heapSort();
        float x = n + 50;
        float y = 700 - (C + M) / 150;
        graph1[n].position = sf::Vector2f(x, y);
        graph1[n].color = sf::Color::Yellow;
    }
    graph1[0].position = sf::Vector2f(50, 700);
    n = 1;
    for (; n < 1300; n++)
    {
        FillRand();
        C = 0;
        M = 0;
        int L = 0;
        int R = n - 1;
        QuickSort2(L, R);
        float x = n + 50;
        float y = 700 - (C + M) / 150;
        graph2[n].position = sf::Vector2f(x, y);
        graph2[n].color = sf::Color::Green;
    }
    graph2[0].position = sf::Vector2f(50, 700);
    while (win.isOpen())
    {
        win.setFramerateLimit(0);
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
        win.draw(graph);
        win.draw(graph1);
        win.draw(graph2);
        win.draw(Heap);
        win.draw(Shell);
        win.draw(Quick);
        win.display();
    }
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
void shellSort()
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = A[i];
            M++;

            int j;
            C++;
            for (j = i; j >= gap; j -= gap)
            {
                C++;
                if (A[j - gap] > temp)
                {
                    A[j] = A[j - gap];
                    M++;
                }
                else
                {
                    break;
                }
                C++;
            }
            A[j] = temp;
            M++;
        }
    }
}

void heapify(int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    C++;
    if (left < n)
    {
        C++;
        if (A[left] > A[largest])
        {
            largest = left;
        }
    }

    C++;
    if (right < n)
    {
        C++;
        if (A[right] > A[largest])
        {
            largest = right;
        }
    }

    if (largest != i)
    {
        swap(A[i], A[largest]);
        M += 3;
        heapify(n, largest);
    }
}

void heapSort()
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(A[0], A[i]);
        M += 3;
        heapify(i, 0);
    }
}