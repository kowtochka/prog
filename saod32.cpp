#include "saod31.cpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
tree *ISDP(int L, int R);
int TreeAdd(int Data, tree **root);
tree *TreeAddRec(int data, tree *&root);
void bubble_sort(int *A, int n);
sf::CircleShape Circles[100];
void drawLine(sf::RenderWindow &win, float x1, float y1, float x2, float y2);
void drawTree(tree *rt, sf::RenderWindow &win, float x, float y, float offsetX, float levelH);
int A[100];
int LengthStick = 5;
int CircleSize = 15;
int x = 1840 / 2;
int y = 768 - 100;
int main(int argc, char const *argv[])
{
    srand(time(0));
    for (int i = 0; i < 100; i++)
    {
        A[i] = rand() % 500;
    }
    tree *R = nullptr;
    tree *S = nullptr;
    for (int i = 0; i < 100; i++)
    {
        TreeAdd(A[i], &S);
        TreeAddRec(A[i], R);
    }
    bubble_sort(A, 100);
    tree *RISDP = ISDP(0, 99);
    sf::RenderWindow win(sf::VideoMode(1840, 768), "Test");
    win.setFramerateLimit(60);
    printf("////////|//////////////////////////////////|\n");
    printf("| n=100 | Размер | Контрл | Высота | Средн |\n");
    printf("|       |        |  сумм  |        | Высота|\n");
    printf("////////|////////|////////|////////////////|\n");
    printf("|  ISDP |%8d|%8d|%8d|%.6f|\n", size(RISDP), sum(RISDP), Height(RISDP), SumLenWay(RISDP, 1) / float(size(RISDP)));
    printf("|  SDP1 |%8d|%8d|%8d|%.6f|\n", size(S), sum(S), Height(S), SumLenWay(S, 1) / float(size(S)));
    printf("|  SDP2 |%8d|%8d|%8d|%.6f|\n", size(R), sum(R), Height(R), SumLenWay(R, 1) / float(size(R)));
    printf("|///////|////////|////////|////////|////////|\n");
    printf("\n");
    printf("\n");
    while (win.isOpen())
    {
        win.setFramerateLimit(0);
        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();
        }
        win.clear(sf::Color(60, 45, 45));
        drawTree(S, win, x, 50, 450, 80);
        win.display();
    }
    return 0;
}
void drawLine(sf::RenderWindow &win, float x1, float y1, float x2, float y2)
{
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(x1, y1)),
        sf::Vertex(sf::Vector2f(x2, y2))};
    win.draw(line, 2, sf::Lines);
}

void drawTree(tree *rt, sf::RenderWindow &win, float x, float y, float offsetX, float levelH)
{
    sf::Font font;
    if (!font.loadFromFile("Arial.ttf"))
    {
        return;
    }
    if (rt == nullptr)
        return;

    float ly = y + levelH;
    float lx = x - offsetX;
    float rx = x + offsetX;
    if (rt->left)
        drawLine(win, x, y, lx, ly);
    if (rt->right)
        drawLine(win, x, y, rx, ly);
    drawTree(rt->left, win, lx, ly, offsetX / 2, levelH);
    drawTree(rt->right, win, rx, ly, offsetX / 2, levelH);
    sf::CircleShape c(CircleSize, 30);
    sf::Text t;
    t.setColor(sf::Color::Black);
    t.setString(std::to_string(rt->data));
    t.setFont(font);
    t.setCharacterSize(13);
    t.setPosition(x - CircleSize / 2, y - CircleSize / 2);
    c.setPosition(x - CircleSize, y - CircleSize);
    c.setFillColor(sf::Color(178, 171, 171));
    win.draw(c);
    win.draw(t);
}

tree *ISDP(int L, int R)
{
    if (L > R)
        return 0;
    else
    {
        int m = ceil((double(L) + R) / 2);
        tree *p = new tree();
        p->data = A[m];
        p->left = ISDP(L, m - 1);
        p->right = ISDP(m + 1, R);
        return p;
    }
}
void bubble_sort(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (A[j] < A[j - 1])
            {
                int temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
            }
        }
    }
}
int TreeAdd(int data, tree **root)
{
    tree **p = root;
    while (*p != nullptr)
    {
        if (data < (*p)->data)
            p = &((*p)->left);
        else if (data > (*p)->data)
            p = &((*p)->right);
        else
            return 0;
    }
    if (*p == nullptr)
    {
        *p = new tree();
        (*p)->data = data;
        (*p)->right = nullptr;
        (*p)->left = nullptr;
    }
    return 1;
}
tree *TreeAddRec(int data, tree *&root)
{
    if (root == nullptr)
    {
        root = new tree();
        root->data = data;
        root->right = nullptr;
        root->left = nullptr;
    }
    else if (data < root->data)
    {
        TreeAddRec(data, root->left);
    }
    else if (data > root->data)
    {
        TreeAddRec(data, root->right);
    }
    return root;
}