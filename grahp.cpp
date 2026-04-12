#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

// ==================== ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ ====================
long long C = 0, M = 0;
int *A = NULL;

// Структура для хранения результатов для одного размера массива
struct TestResult
{
    int n;
    long long quickSortTotal; // C+M для быстрой сортировки
    long long shellSortTotal; // C+M для сортировки Шелла
    long long heapSortTotal;  // C+M для пирамидальной сортировки
};

// ==================== ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ ====================

void resetCounters()
{
    C = 0;
    M = 0;
}

void swapInt(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void fillRandom(int n)
{
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 10000;
    }
}

void copyArray(int *dest, int *src, int n)
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
}

// ==================== БЫСТРАЯ СОРТИРОВКА ====================

void QuickSort2(int L, int R)
{
    if (L >= R)
        return;

    int x = A[(L + R) / 2];
    int i = L;
    int j = R;

    while (i <= j)
    {
        while (A[i] < x)
        {
            C++;
            i++;
        }
        C++;
        while (A[j] > x)
        {
            C++;
            j--;
        }
        C++;
        if (i <= j)
        {
            swapInt(A[i], A[j]);
            M += 3;
            i++;
            j--;
        }
    }

    if (L < j)
        QuickSort2(L, j);
    if (i < R)
        QuickSort2(i, R);
}

// ==================== СОРТИРОВКА ШЕЛЛА ====================

void shellSort(int n)
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

// ==================== ПИРАМИДАЛЬНАЯ СОРТИРОВКА ====================

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
        swapInt(A[i], A[largest]);
        M += 3;
        heapify(n, largest);
    }
}

void heapSort(int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swapInt(A[0], A[i]);
        M += 3;
        heapify(i, 0);
    }
}

// ==================== ТЕСТИРОВАНИЕ ====================

long long testQuickSort(int n, int *originalArray)
{
    copyArray(A, originalArray, n);
    resetCounters();
    QuickSort2(0, n - 1);
    return C + M;
}

long long testShellSort(int n, int *originalArray)
{
    copyArray(A, originalArray, n);
    resetCounters();
    shellSort(n);
    return C + M;
}

long long testHeapSort(int n, int *originalArray)
{
    copyArray(A, originalArray, n);
    resetCounters();
    heapSort(n);
    return C + M;
}

// ==================== ОТРИСОВКА ГРАФИКА ====================

void drawGraph(sf::RenderWindow &window, const vector<TestResult> &results, int width, int height)
{
    if (results.empty())
        return;

    // Находим максимумы для масштабирования
    int maxN = 0;
    long long maxTotal = 0;

    for (const auto &r : results)
    {
        if (r.n > maxN)
            maxN = r.n;
        if (r.quickSortTotal > maxTotal)
            maxTotal = r.quickSortTotal;
        if (r.shellSortTotal > maxTotal)
            maxTotal = r.shellSortTotal;
        if (r.heapSortTotal > maxTotal)
            maxTotal = r.heapSortTotal;
    }

    // Отступы для осей
    const int marginLeft = 80;
    const int marginRight = 40;
    const int marginTop = 60;
    const int marginBottom = 80;

    int graphWidth = width - marginLeft - marginRight;
    int graphHeight = height - marginTop - marginBottom;

    // Фон графика
    sf::RectangleShape bg(sf::Vector2f(width, height));
    bg.setFillColor(sf::Color(30, 30, 40));
    window.draw(bg);

    // Рамка графика
    sf::RectangleShape border(sf::Vector2f(graphWidth, graphHeight));
    border.setPosition(marginLeft, marginTop);
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineColor(sf::Color::White);
    border.setOutlineThickness(2);
    window.draw(border);

    // Ось X (n)
    sf::Vertex axisX[] = {
        sf::Vertex(sf::Vector2f(marginLeft - 5, marginTop + graphHeight), sf::Color::White),
        sf::Vertex(sf::Vector2f(marginLeft + graphWidth + 5, marginTop + graphHeight), sf::Color::White)};
    window.draw(axisX, 2, sf::Lines);

    // Ось Y (C+M)
    sf::Vertex axisY[] = {
        sf::Vertex(sf::Vector2f(marginLeft, marginTop - 5), sf::Color::White),
        sf::Vertex(sf::Vector2f(marginLeft, marginTop + graphHeight + 5), sf::Color::White)};
    window.draw(axisY, 2, sf::Lines);

    // Стрелки на осях
    sf::Vertex xArrow[] = {
        sf::Vertex(sf::Vector2f(marginLeft + graphWidth + 5, marginTop + graphHeight), sf::Color::White),
        sf::Vertex(sf::Vector2f(marginLeft + graphWidth, marginTop + graphHeight - 5), sf::Color::White),
        sf::Vertex(sf::Vector2f(marginLeft + graphWidth, marginTop + graphHeight + 5), sf::Color::White)};
    window.draw(xArrow, 3, sf::Lines);

    sf::Vertex yArrow[] = {
        sf::Vertex(sf::Vector2f(marginLeft, marginTop - 5), sf::Color::White),
        sf::Vertex(sf::Vector2f(marginLeft - 5, marginTop), sf::Color::White),
        sf::Vertex(sf::Vector2f(marginLeft + 5, marginTop), sf::Color::White)};
    window.draw(yArrow, 3, sf::Lines);

    // Подписи осей
    sf::Font font;
    if (font.loadFromFile("arial.ttf"))
    {
        sf::Text xLabel;
        xLabel.setFont(font);
        xLabel.setString("Размер массива (n)");
        xLabel.setCharacterSize(18);
        xLabel.setFillColor(sf::Color::White);
        xLabel.setPosition(marginLeft + graphWidth / 2 - 100, marginTop + graphHeight + 35);
        window.draw(xLabel);

        sf::Text yLabel;
        yLabel.setFont(font);
        yLabel.setString("C + M (сравнения + перемещения)");
        yLabel.setCharacterSize(18);
        yLabel.setFillColor(sf::Color::White);
        yLabel.setPosition(marginLeft - 70, marginTop + graphHeight / 2);
        yLabel.setRotation(-90);
        window.draw(yLabel);

        sf::Text title;
        title.setFont(font);
        title.setString("Сравнение эффективности сортировок");
        title.setCharacterSize(24);
        title.setFillColor(sf::Color::Yellow);
        title.setPosition(width / 2 - 200, 15);
        window.draw(title);
    }

    // Рисуем деления на оси X
    for (int i = 0; i <= 10; i++)
    {
        int nValue = (maxN / 10) * i;
        float x = marginLeft + (static_cast<float>(i) / 10.0f) * graphWidth;

        sf::Vertex tick[] = {
            sf::Vertex(sf::Vector2f(x, marginTop + graphHeight), sf::Color::White),
            sf::Vertex(sf::Vector2f(x, marginTop + graphHeight + 5), sf::Color::White)};
        window.draw(tick, 2, sf::Lines);

        if (font.loadFromFile("arial.ttf"))
        {
            sf::Text label;
            label.setFont(font);
            label.setString(to_string(nValue));
            label.setCharacterSize(12);
            label.setFillColor(sf::Color::White);
            label.setPosition(x - 15, marginTop + graphHeight + 8);
            window.draw(label);
        }
    }

    // Рисуем деления на оси Y
    for (int i = 0; i <= 10; i++)
    {
        long long totalValue = (maxTotal / 10) * i;
        float y = marginTop + graphHeight - (static_cast<float>(i) / 10.0f) * graphHeight;

        sf::Vertex tick[] = {
            sf::Vertex(sf::Vector2f(marginLeft - 5, y), sf::Color::White),
            sf::Vertex(sf::Vector2f(marginLeft, y), sf::Color::White)};
        window.draw(tick, 2, sf::Lines);

        if (font.loadFromFile("arial.ttf"))
        {
            sf::Text label;
            label.setFont(font);
            label.setString(to_string(totalValue));
            label.setCharacterSize(12);
            label.setFillColor(sf::Color::White);
            label.setPosition(marginLeft - 50, y - 8);
            window.draw(label);
        }
    }

    // Рисуем графики
    // Быстрая сортировка (жёлтая)
    sf::VertexArray quickGraph(sf::LineStrip, results.size());
    for (size_t i = 0; i < results.size(); i++)
    {
        float x = marginLeft + (static_cast<float>(results[i].n) / maxN) * graphWidth;
        float y = marginTop + graphHeight - (static_cast<float>(results[i].quickSortTotal) / maxTotal) * graphHeight;
        quickGraph[i].position = sf::Vector2f(x, y);
        quickGraph[i].color = sf::Color::Yellow;
    }

    // Сортировка Шелла (голубая)
    sf::VertexArray shellGraph(sf::LineStrip, results.size());
    for (size_t i = 0; i < results.size(); i++)
    {
        float x = marginLeft + (static_cast<float>(results[i].n) / maxN) * graphWidth;
        float y = marginTop + graphHeight - (static_cast<float>(results[i].shellSortTotal) / maxTotal) * graphHeight;
        shellGraph[i].position = sf::Vector2f(x, y);
        shellGraph[i].color = sf::Color::Cyan;
    }

    // Пирамидальная сортировка (зелёная)
    sf::VertexArray heapGraph(sf::LineStrip, results.size());
    for (size_t i = 0; i < results.size(); i++)
    {
        float x = marginLeft + (static_cast<float>(results[i].n) / maxN) * graphWidth;
        float y = marginTop + graphHeight - (static_cast<float>(results[i].heapSortTotal) / maxTotal) * graphHeight;
        heapGraph[i].position = sf::Vector2f(x, y);
        heapGraph[i].color = sf::Color::Green;
    }

    window.draw(quickGraph);
    window.draw(shellGraph);
    window.draw(heapGraph);

    // Рисуем точки на графиках
    for (size_t i = 0; i < results.size(); i++)
    {
        sf::CircleShape point(3);

        // Точка для быстрой сортировки
        float x = marginLeft + (static_cast<float>(results[i].n) / maxN) * graphWidth;
        float y = marginTop + graphHeight - (static_cast<float>(results[i].quickSortTotal) / maxTotal) * graphHeight;
        point.setPosition(x - 3, y - 3);
        point.setFillColor(sf::Color::Yellow);
        window.draw(point);

        // Точка для сортировки Шелла
        y = marginTop + graphHeight - (static_cast<float>(results[i].shellSortTotal) / maxTotal) * graphHeight;
        point.setPosition(x - 3, y - 3);
        point.setFillColor(sf::Color::Cyan);
        window.draw(point);

        // Точка для пирамидальной сортировки
        y = marginTop + graphHeight - (static_cast<float>(results[i].heapSortTotal) / maxTotal) * graphHeight;
        point.setPosition(x - 3, y - 3);
        point.setFillColor(sf::Color::Green);
        window.draw(point);
    }

    // Легенда
    sf::RectangleShape legendBg(sf::Vector2f(220, 110));
    legendBg.setPosition(width - 240, marginTop);
    legendBg.setFillColor(sf::Color(0, 0, 0, 200));
    legendBg.setOutlineColor(sf::Color::White);
    legendBg.setOutlineThickness(1);
    window.draw(legendBg);

    sf::Font legendFont;
    if (legendFont.loadFromFile("arial.ttf"))
    {
        // Быстрая сортировка
        sf::Vertex legendQuick[] = {
            sf::Vertex(sf::Vector2f(width - 220, marginTop + 20), sf::Color::Yellow),
            sf::Vertex(sf::Vector2f(width - 190, marginTop + 20), sf::Color::Yellow)};
        window.draw(legendQuick, 2, sf::Lines);

        sf::Text quickText;
        quickText.setFont(legendFont);
        quickText.setString("Быстрая сортировка");
        quickText.setCharacterSize(14);
        quickText.setFillColor(sf::Color::Yellow);
        quickText.setPosition(width - 185, marginTop + 12);
        window.draw(quickText);

        // Сортировка Шелла
        sf::Vertex legendShell[] = {
            sf::Vertex(sf::Vector2f(width - 220, marginTop + 45), sf::Color::Cyan),
            sf::Vertex(sf::Vector2f(width - 190, marginTop + 45), sf::Color::Cyan)};
        window.draw(legendShell, 2, sf::Lines);

        sf::Text shellText;
        shellText.setFont(legendFont);
        shellText.setString("Сортировка Шелла");
        shellText.setCharacterSize(14);
        shellText.setFillColor(sf::Color::Cyan);
        shellText.setPosition(width - 185, marginTop + 37);
        window.draw(shellText);

        // Пирамидальная сортировка
        sf::Vertex legendHeap[] = {
            sf::Vertex(sf::Vector2f(width - 220, marginTop + 70), sf::Color::Green),
            sf::Vertex(sf::Vector2f(width - 190, marginTop + 70), sf::Color::Green)};
        window.draw(legendHeap, 2, sf::Lines);

        sf::Text heapText;
        heapText.setFont(legendFont);
        heapText.setString("Пирамидальная сортировка");
        heapText.setCharacterSize(14);
        heapText.setFillColor(sf::Color::Green);
        heapText.setPosition(width - 185, marginTop + 62);
        window.draw(heapText);
    }
}

// ==================== MAIN ====================

int main()
{
    srand(time(NULL));

    // Вектор размеров массивов для тестирования
    vector<int> sizes;
    cout << "Введите размеры массивов через пробел (например: 100 500 1000 2000 5000 10000): ";
    string input;
    getline(cin, input);

    // Если пользователь ничего не ввёл, используем стандартные значения
    if (input.empty())
    {
        sizes = {100, 250, 500, 750, 1000, 2000, 3000, 4000, 5000};
    }
    else
    {
        size_t pos = 0;
        while (pos < input.length())
        {
            size_t space = input.find(' ', pos);
            if (space == string::npos)
                space = input.length();
            int size = stoi(input.substr(pos, space - pos));
            sizes.push_back(size);
            pos = space + 1;
        }
    }

    cout << "\nТестирование сортировок...\n";

    vector<TestResult> results;

    // Для каждого размера массива запускаем тесты
    for (int n : sizes)
    {
        cout << "Тестирование n = " << n << "... ";

        // Выделяем память
        A = new int[n];
        int *originalArray = new int[n];

        // Заполняем исходный массив
        fillRandom(n);
        copyArray(originalArray, A, n);

        TestResult result;
        result.n = n;

        // Тестируем каждую сортировку
        result.quickSortTotal = testQuickSort(n, originalArray);
        result.shellSortTotal = testShellSort(n, originalArray);
        result.heapSortTotal = testHeapSort(n, originalArray);

        results.push_back(result);

        cout << "готово (QS=" << result.quickSortTotal
             << ", SS=" << result.shellSortTotal
             << ", HS=" << result.heapSortTotal << ")\n";

        // Очищаем память
        delete[] A;
        delete[] originalArray;
    }

    // Создаём окно для графика
    sf::RenderWindow window(sf::VideoMode({1366, 768}), "Сравнение сортировок: C+M от n");

    // Основной цикл отрисовки
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        drawGraph(window, results, 1366, 768);
        window.display();
    }

    return 0;
}