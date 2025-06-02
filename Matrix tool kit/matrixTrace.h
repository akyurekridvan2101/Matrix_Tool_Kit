#ifndef matrixTrace_H
#define matrixTrace_H

/*
    File: matrisIzi.h
    -----------------
    This header file contains function prototypes for calculating matrix trace and sum of elements.
*/

long int MatrixTrace(long int** matrix, int matrixSize) {
    // Calculate the sum of diagonal elements
    long int trace = 0;

    for (int i = 0; i < matrixSize; i++) {
        trace += matrix[i][i];
    }

    return trace;
}

long int MatrixElementSum(long int** matrix, int matrixSize) {
    // Calculate the sum of all elements in the matrix
    long int sum = 0;

    for (int row = 0; row < matrixSize; row++) {
        for (int column = 0; column < matrixSize; column++) {
            sum += matrix[row][column];
        }
    }

    return sum;
}

#endif
