#ifndef matrixSimplification_H
#define matrixSimplification_H

#include "detDivProduct.h"
#include "gcdLcm.h"
#include <stdio.h>

// Function to simplify the matrix by dividing each row by their greatest common divisor (GCD)
long int** SimplifyMatrix(long int** matrix, int matrixSize, int currentRow) {
    long int* p_detDivQuotient = &determinantDivisionQuotient;

    // Iterate over rows starting from the current row
    for (int t = currentRow; t < matrixSize; t++) {
        long int gcdValue = matrix[t][currentRow];

        // Find the greatest common divisor (GCD) of the current row
        for (int e = currentRow + 1; e < matrixSize; e++) {
            gcdValue = FindGCD(gcdValue, matrix[t][e]);

            if (gcdValue == 1)
                break;
        }

        // If the GCD is not 1, simplify the row by dividing all elements by the GCD
        if (gcdValue != 1) {
            for (int b = currentRow; b < matrixSize; b++) {
                matrix[t][b] /= gcdValue;
            }

            // Update the determinant division quotient
            *p_detDivQuotient *= gcdValue;
        }
    }

    return matrix;
}

#endif