#ifndef TRANSPOSE_H
#define TRANSPOSE_H

#include <stdlib.h>

// Function to transpose a matrix
long int** Transpose(long int** matrix, int matrixSize) {
    // Allocate memory for the transpose matrix
    long int** transposeMatrix = (long int**)(malloc(matrixSize * sizeof(long int*)));

    // Allocate memory for each row of the transpose matrix
    for (int i = 0; i < matrixSize; i++) {
        transposeMatrix[i] = (long int*)malloc(matrixSize * sizeof(long int));
    }

    // Perform the transpose operation
    for (int row = 0; row < matrixSize; row++) {
        for (int column = 0; column < matrixSize; column++) {
            transposeMatrix[column][row] = matrix[row][column];
        }
    }

    return transposeMatrix;
}

#endif
