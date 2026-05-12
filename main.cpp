#include "sortfunc.cpp"

int main(int argc, char const *argv[])
{
    int n = 50000;
    int *data_int = (int *)malloc(n * sizeof(int));
    float *data_float = (float *)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++)
    {
        data_int[i] = rand() % 1000;
        data_float[i] = (float)(rand() % 1000) / 3.5f;
    }
    float time_select = timer(SelectSort, data_int, n);
    float time_selectf = timer(SelectSort, data_float, n);
    for (int i = 0; i < n; i++)
    {
        data_int[i] = rand() % 1000;
        data_float[i] = (float)(rand() % 1000) / 3.5f;
    }
    float time_bubble = timer(BubbleSort, data_int, n);
    float time_bubblef = timer(BubbleSort, data_float, n);
    for (int i = 0; i < n; i++)
    {
        data_int[i] = rand() % 1000;
        data_float[i] = (float)(rand() % 1000) / 3.5f;
    }
    float time_shell = timer(ShellSort, data_int, n);
    float time_shellf = timer(ShellSort, data_float, n);
    printf("Время сортировки select int: %.3f ms\n", time_select);
    printf("Время сортировки select float: %.3f ms\n\n", time_selectf);
    printf("Время сортировки bubble int: %.3f ms\n", time_bubble);
    printf("Время сортировки bubble float: %.3f ms\n\n", time_bubblef);
    printf("Время сортировки shell int: %.3f ms\n", time_shell);
    printf("Время сортировки shell float: %.3f ms\n", time_shellf);

    return 0;
}
