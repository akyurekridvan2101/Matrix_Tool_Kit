#ifndef UPPER_TRIANGULARIZE_H
#define UPPER_TRIANGULARIZE_H

#include "HEADER.h"
#include "detDivProduct.h"
#include "matrixSimplification.h"

// Function to convert a matrix to upper triangular form
long int** UpperTriangularize(long int** matrix, int matrixSize) {
    long int* p_detDivProduct = &determinantDivisionProduct;

    for (int currentRow = 0, currentColumn = 0; currentColumn < matrixSize - 1; currentColumn++, currentRow++) {
        matrix = ExchangeRows(matrix, matrixSize, currentRow);
        SimplifyMatrix(matrix, matrixSize, currentRow);

        if (matrix[currentRow][currentRow] == 0) {
            continue;
        }

        int r_1 = matrix[currentRow][currentColumn];

        for (int i = currentRow + 1; i < matrixSize; i++) {
            if (matrix[i][currentColumn] == 0)
                continue;

            int r_2 = matrix[i][currentColumn];
            int lcm = FindLCM(r_1, r_2);
            int multiplier_r_1;
            int multiplier_r_2;

            if ((r_1 > 0 && r_2 > 0) || (r_1 < 0 && r_2 < 0)) {
                multiplier_r_1 = -(lcm / r_1);
                multiplier_r_2 = lcm / r_2;
            }
            else if (r_1 > 0 && r_2 < 0) {
                multiplier_r_1 = lcm / r_1;
                multiplier_r_2 = lcm / (-r_2);
            }
            else if (r_1 < 0 && r_2 > 0) {
                multiplier_r_1 = lcm / (-r_1);
                multiplier_r_2 = lcm / r_2;
            }

            *p_detDivProduct *= multiplier_r_2;

            for (int k = currentColumn; k < matrixSize; k++) {
                matrix[i][k] = multiplier_r_1 * matrix[currentRow][k] + multiplier_r_2 * matrix[i][k];
            }
        }
    }

    return matrix;
}

#endif
