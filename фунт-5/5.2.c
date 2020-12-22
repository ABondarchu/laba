#include <stdio.h>
#include <math.h>

int main()
{
    int row, col, i, j, e;
    unsigned short hasPositiveElement;
    printf("Задайте количество строк матрицы: ");
    scanf("%d", &row);
    printf("Задайте количество столбцов матрицы: ");
    scanf("%d", &col);
    int a[row][col];
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("Введите элемент [%d,%d] матрицы: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < row; i++) {
        hasPositiveElement = 0;
        for (j = 0; j < col; j++) {
            if (a[i][j] >= 0) {
                hasPositiveElement = 1;
                break;
            }
        }
        if (!hasPositiveElement) {
            e = a[i][0];
            break;
        }
    }
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            a[i][j] = a[i][j] + e;
            printf ("Преобразованный элемент [%d,%d] матрицы: %d \n", i, j, a[i][j]);
        }
    }
}
