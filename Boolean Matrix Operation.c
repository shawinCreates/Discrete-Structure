#include <stdio.h>

#define ROW1 3
#define COL1 3
#define ROW2 3
#define COL2 3

void displayMatrix(int matrix[][COL1], int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void booleanJoin(int matrix1[][COL1], int matrix2[][COL1], int row, int col) {
    int i, j;
    printf("Boolean Join:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", matrix1[i][j] || matrix2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void booleanMeet(int matrix1[][COL1], int matrix2[][COL1], int row, int col) {
    int i, j;
    printf("Boolean Meet:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", matrix1[i][j] && matrix2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void booleanProduct(int matrix1[][COL1], int matrix2[][COL1], int row, int col) {
    int i, j;
    printf("Boolean Product:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", matrix1[i][j] ^ matrix2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int matrix1[ROW1][COL1] = {{1, 0, 1}, {0, 1, 0}, {1, 1, 0}};
    int matrix2[ROW2][COL2] = {{0, 1, 1}, {1, 0, 1}, {0, 0, 1}};

    printf("Matrix 1:\n");
    displayMatrix(matrix1, ROW1, COL1);

    printf("Matrix 2:\n");
    displayMatrix(matrix2, ROW2, COL2);

    booleanJoin(matrix1, matrix2, ROW1, COL1);
    booleanMeet(matrix1, matrix2, ROW1, COL1);
    booleanProduct(matrix1, matrix2, ROW1, COL1);

    return 0;
}

