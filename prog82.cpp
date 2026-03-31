#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <iterator>

struct room
{
    int number;
    int S;
    int facNumber;
    int people;
};
struct fac
{
    int number;
    int rooms;
    int students;
    double AverageS;
};
void PrintStruct(struct fac *A);

int main(int argc, char const *argv[])
{
    struct room List[]{
        {101, 25, 1, 4},
        {102, 18, 2, 2},
        {103, 30, 1, 6},
        {201, 22, 3, 3},
        {202, 20, 2, 4},
        {203, 28, 1, 5},
        {301, 24, 3, 2},
        {302, 15, 2, 1},
        {303, 32, 1, 7},
        {401, 26, 3, 4}};
    size_t size = std::size(List);
    struct fac facList[3];
    for (int i = 0; i < 3; i++)
    {
        int rooms = 0, students = 0, avgS = 0;
        facList[i].number = i + 1;
        for (int j = 0; j < size; j++)
        {
            if (List[j].facNumber == i + 1)
            {
                rooms++;
                students += List[j].people;
                avgS += List[j].S;
            }
        }
        facList[i].rooms = rooms;
        facList[i].students = students;
        facList[i].AverageS = (double)avgS / (double)students;
    }
    PrintStruct(facList);
}

void PrintStruct(struct fac *A)
{
    for (int i = 0; i < 3; i++)
        std::cout << "Факультет: " << A[i].number << ", Количество комнат: " << A[i].rooms << ", Количество студентов: " << A[i].students << ", Средняя площадь на студента: " << A[i].AverageS << std::endl;

    printf("\n");
}