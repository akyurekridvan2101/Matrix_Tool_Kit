#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include "HEADER.h"

// Allocates memory for a matrix using malloc for pointers
long int** AllocateMatrix(int matrixSize) {
    long int** matrix = (long int**)malloc(sizeof(long int*) * matrixSize);
    for (int i = 0; i < matrixSize; i++) {
        matrix[i] = (long int*)(malloc(sizeof(long int) * matrixSize));
    }
    return matrix;
}

// Fills the elements of the matrix with user input
long int** FillMatrix(long int** matrix, int matrixSize) {
    long int number;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            printf("\nmatris[%d][%d] : ", i + 1, j + 1);
            scanf_s("%ld", &number);
            matrix[i][j] = number;
        }
    }
    return matrix;
}

// Prints the matrix to the console
void printMatrix(long int** matrix, int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            printf("%ld   ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Frees the memory allocated for the matrix
void freeMatrix(long int** matrix, int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Copies the content of one matrix to another
long int** matrixCopy(long int** sourceMatrix, long int** destinationMatrix, int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            destinationMatrix[i][j] = sourceMatrix[i][j];
        }
    }
    return destinationMatrix;
}

#endif
