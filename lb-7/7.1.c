#include <stdio.h>

void enterMatrix(int row, int col, int a[row][col]);
void printUpdatedMatrix(int row, int col, int a[row][col], int element, int (*op)(int, int));
int getFirstElementOfFirstNegativeRow(int row, int col, int a[row][col]);
int sum(int a, int b);

int main() {
    int row, col, a[row][col];
    printf("Задайте количество строк матрицы: ");
    scanf("%d", &row);
    printf("Задайте количество столбцов матрицы: ");
    scanf("%d", &col);
    enterMatrix(row, col, a);
    printUpdatedMatrix(row, col, a, getFirstElementOfFirstNegativeRow(row, col, a), sum);
}

void enterMatrix(int row, int col, int a[row][col]) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("Введите элемент [%d,%d] матрицы: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void printUpdatedMatrix(int row, int col, int a[row][col], int element, int (*op)(int, int)) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            a[i][j] = op(a[i][j], element);
            //print updated matrix
            printf("Преобразованный элемент [%d,%d] матрицы: %d \n", i, j, a[i][j]);
        }
    }
}

int getFirstElementOfFirstNegativeRow(int row, int col, int a[row][col]) {
    unsigned short hasPositiveElement;
    int i, j;
    for (i = 0; i < row; i++) {
        hasPositiveElement = 0;
        for (j = 0; j < col; j++) {
            if (a[i][j] >= 0) {
                hasPositiveElement = 1;
                break;
            }
        }
        if (!hasPositiveElement) {
            return(a[i][0]);
        }
    }
    return 0;
}

int sum(int a, int b) {
    return a + b;
}
