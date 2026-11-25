
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <windows.h>

#define N 10

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "RUS");

    float A[N], B[N];
    int choice;

    printf("Введите 10 элементов массива:\n");

    for (int i = 0; i < N; i++)
    {
        printf("A[%d] = ", i + 1);
        scanf("%f", &A[i]);
        B[i] = A[i];
    }

    printf("\nВыберите преобразование:\n");
    printf("1 - Удвоить все элементы\n");
    printf("2 - Увеличить каждый второй элемент на 1\n");
    printf("3 - Обнулить отрицательные элементы\n");
    printf("4 - Возвести в квадрат\n");
    printf("5 - Уменьшить в 10 раз\n");
    printf("6 - Изменить знак элементов\n");
    printf("7 - Уменьшить на константу 5\n");
    printf("8 - Отбросить дробную часть\n");
    printf("9 - Установить 1 в четных элементах\n");
    printf("10 - Округлить в большую сторону\n");
    printf("11 - Прибавить последний элемент\n");
    printf("12 - Заменить нули порядковым номером\n");

    printf("\nВаш выбор: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 12)
    {
        printf("Неверный выбор!\n");
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        switch (choice)
        {
        case 1:
            A[i] = A[i] * 2;
            break;

        case 2:
            if ((i + 1) % 2 == 0)
                A[i] = A[i] + 1;
            break;

        case 3:
            if (A[i] < 0)
                A[i] = 0;
            break;

        case 4:
            A[i] = A[i] * A[i];
            break;

        case 5:
            A[i] = A[i] / 10;
            break;

        case 6:
            A[i] = -A[i];
            break;

        case 7:
            A[i] = A[i] - 5;
            break;

        case 8:
            A[i] = (int)A[i];
            break;

        case 9:
            if ((i + 1) % 2 == 0)
                A[i] = 1;
            break;

        case 10:
            A[i] = ceil(A[i]);
            break;

        case 11:
            A[i] = A[i] + B[N - 1];
            break;

        case 12:
            if (A[i] == 0)
                A[i] = i + 1;
            break;
        }
    }

    printf("\nРезультат:\n");
    printf("---------------------------------\n");
    printf("Индекс\tИсходное\tНовое\n");

    for (int i = 0; i < N; i++)
    {
        printf("%d\t%.2f\t\t%.2f\n",
            i + 1, B[i], A[i]);
    }

    return 0;
}
