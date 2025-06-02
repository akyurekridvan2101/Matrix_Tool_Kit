#ifndef ExchangeRows_H
#define ExchangeRows_H

#include "detDivProduct.h"

// Function to return the absolute value of a number
long int AbsoluteValue(long int number) {
    if (number < 0) {
        number *= -1; // Convert negative to positive
    }

    return number;
}

// Function to exchange rows in the matrix based on the smallest absolute value in a column
long int** ExchangeRows(long int** matrix, int matrixSize, int currentRow) {
    long int* p_detDivProduct = &determinantDivisionProduct;

    long int smallestNumber = matrix[currentRow][currentRow];
    int numberPosition = currentRow;
    long int number;

    // Find the row with the smallest absolute value in the current column
    for (int i = currentRow + 1; i < matrixSize; i++) {
        number = AbsoluteValue(matrix[i][currentRow]);

        if (number == 0) {
            continue;
        }
        else if ((smallestNumber == 0)) {
            numberPosition = i;
            smallestNumber = number;
        }
        else if (number < AbsoluteValue(smallestNumber)) {
            numberPosition = i;
            smallestNumber = number;
        }
    }

    // If all elements in the column are zero, no change is needed
    if (smallestNumber == 0) {
        return matrix;
    }
    else if (numberPosition == currentRow) {
        return matrix; // No row exchange needed
    }

    // Exchange rows
    long int* temp = matrix[currentRow];
    matrix[currentRow] = matrix[numberPosition];
    matrix[numberPosition] = temp;

    // Update determinant division product
    *p_detDivProduct *= -1; // Change sign for each row exchange

    return matrix;
}

#endif
