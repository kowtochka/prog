#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char name[100];
    int grades[4];
    int scholarship;
};
int n = 5;
Student students[5] = {
    {"Иванов_Иван_Иванович", {5, 4, 5, 5}, 3500},
    {"Петров_Петр_Петрович", {3, 4, 3, 3}, 0},
    {"Сидорова_Анна_Сергеевна", {5, 5, 5, 5}, 5000},
    {"Кузнецов_Алексей_Владимирович", {4, 4, 4, 5}, 2800},
    {"Смирнова_Елена_Дмитриевна", {4, 3, 4, 4}, 0}};

void lookFile();
void addFile();
void addStudent();
void delStudent();
void changeGrade();
void addScholarship();

int main(int argc, char const *argv[])
{
start:
    printf("Меню\n1.Создать новый файл\n2.Просмотреть файл\n3.Добавить новую запись\n4.Удалить двоечников\n5.Изменить оценки студента\n6.Назначить стпиендию\n0.Выйти\n");
    int option;
    scanf("%d", &option);
    switch (option)
    {
    case 0:
        system("clear");
        return 0;
    case 1:
        system("clear");
        addFile();
        break;
    case 2:
        system("clear");
        lookFile();
        break;
    case 3:
        system("clear");
        addStudent();
        break;
    case 4:
        system("clear");
        delStudent();
        break;
    case 5:
        system("clear");
        changeGrade();
        break;
    case 6:
        system("clear");
        addScholarship();
        break;
    }
    goto start;
    return 0;
}
void addFile()
{
    char name[30];
    printf("Введите название файла\n");
    scanf("%s", &name);
    FILE *p = fopen(name, "wb");
    fwrite(&students, sizeof(Student), n, p);
    fclose(p);
}
void lookFile()
{
    Student import[n];
    char name[30];
    printf("Введите название файла\n");
    scanf("%30s", &name);
    FILE *p = fopen(name, "rb");
    fread(import, sizeof(Student), n, p);
    for (int i = 0; i < n; i++)
    {
        printf("%s ", import[i].name);
        for (int j = 0; j < 4; j++)
        {
            printf("%2d", import[i].grades[j]);
        }
        printf(", %5d руб.\n", import[i].scholarship);
    }
    fclose(p);
}
void addStudent()
{
    char name[30];
    Student newbie;
    printf("Введите название файла\n");
    scanf("%30s", name);
    FILE *p = fopen(name, "ab");
    printf("Введите Ф_И_О\n");
    scanf("%100s", newbie.name);
    for (int i = 0; i < 4; i++)
    {
        printf("Введите оценку\n");
        scanf("%d", &newbie.grades[i]);
    }
    fwrite(&newbie, sizeof(Student), 1, p);
    n++;
    fclose(p);
}
void delStudent()
{
    Student import[n];
    char name[30];
    printf("Введите название файла\n");
    scanf("%30s", &name);
    FILE *p = fopen(name, "rb");
    fread(import, sizeof(Student), n, p);
    fclose(p);
    p = fopen(name, "wb");
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < 4; j++)
        {
            if (import[i].grades[j] == 2)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            for (int a = i; a < n - 1; a++)
                import[a] = import[a + 1];
            n--;
            i--;
        }
    }
    fwrite(&import, sizeof(Student), n, p);
    fclose(p);
}
void changeGrade()
{
    Student import[n];
    char name[30];
    printf("Введите название файла\n");
    scanf("%30s", &name);
    FILE *p = fopen(name, "rb");
    fread(import, sizeof(Student), n, p);
    fclose(p);
    p = fopen(name, "wb");
    printf("Введите ФИО студента\n");
    scanf("%100s", &name);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(name, import[i].name) == 0)
        {
        staart:
            for (int j = 0; j < 4; j++)
            {
                printf("%d  ", import[i].grades[j]);
            }
            printf("Какую оценку хотите поменять? (0 для выхода)\n");
            int gra;
            scanf("%d", &gra);
            if (gra == 0)
            {
                break;
            }
            printf("Введите новую оценку\n");
            int gr;
            scanf("%d", &gr);
            import[i].grades[gra - 1] = gr;
            goto staart;
        }
    }
    fwrite(import, sizeof(Student), n, p);
    fclose(p);
}
void addScholarship()
{
    int otl = 0;
    Student import[n];
    char name[30];
    printf("Введите название файла\n");
    scanf("%30s", &name);
    FILE *p = fopen(name, "rb");
    fread(import, sizeof(Student), n, p);
    fclose(p);
    for (int i = 0; i < n; i++)
    {
        otl = 0;
        int flag = 1;
        for (int j = 0; j < 4; j++)
        {
            if (import[i].grades[j] == 2 || import[i].grades[j] == 3)
            {
                flag = 0;
                break;
            }
            if (import[i].grades[j] == 5)
            {
                otl++;
            }
        }
        if (otl == 4)
        {
            flag = 2;
        }
        switch (flag)
        {
        case 0:
            import[i].scholarship = 0;
            break;
        case 1:
            import[i].scholarship = 3000;
            break;
        case 2:
            import[i].scholarship = 7500;
            break;
        }
    }
    fopen(name, "wb");
    fwrite(import, sizeof(Student), n, p);
    fclose(p);
}