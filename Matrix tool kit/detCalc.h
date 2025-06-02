#ifndef DET_CALC_H
#define DET_CALC_H

#include "detDivProduct.h"

/*
    Function: CalculateDeterminant
    ------------------------------
    Calculates the determinant of a matrix using the upper triangular matrix and division factors.

    matrix: The upper triangular matrix.
    matrixSize: The size of the matrix (number of rows/columns).

    returns: The determinant of the matrix.
*/
long int CalculateDeterminant(long int** matrix, int matrixSize) {
    long int* p_detDivProduct = &determinantDivisionProduct;
    long int* p_detDivQuotient = &determinantDivisionQuotient;

    long int finalDeterminant = 1; // Upper triangular matrix determinant
    long int initialDeterminant;   // Initial matrix determinant

    // Calculate the determinant of the upper triangular matrix
    for (int i = 0; i < matrixSize; i++) {
        finalDeterminant *= matrix[i][i];
    }

    // Calculate the determinant of the initial matrix
    initialDeterminant = (long int)((finalDeterminant * *p_detDivQuotient) / (*p_detDivProduct));

    // Reset division factors for future use
    *p_detDivQuotient = 1;
    *p_detDivProduct = 1;

    return initialDeterminant;
}

#endif
