#ifndef solveUsingCramer_H
#define solveUsingCramer_H

#include <stdio.h>
#include <stdlib.h>

#include "upperTriangularize.h"
#include "matrixOperations.h"

// Function to solve a system of linear equations using Cramer's rule
long int* SolveUsingCramer(long int** matrix, int matrixSize) {
    // Allocate memory for determinants and solutions
    long int* determinants = (long int*)(malloc(sizeof(long int) * matrixSize));
    long int* solutions = (long int*)(malloc(sizeof(long int) * matrixSize));
    long int** temporaryMatrix = AllocateMatrix(matrixSize);

    // Get user input for solutions
    for (int i = 0; i < matrixSize; i++) {
        printf("\nEnter the solution for row %d: ", i + 1);
        scanf_s("%ld", &solutions[i]);
    }

    // Create a copy of the original matrix
    temporaryMatrix = matrixCopy(matrix, temporaryMatrix, matrixSize);

    // Calculate determinants for each variable using Cramer's rule
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            temporaryMatrix[j][i] = solutions[j]; // Replace the column corresponding to the variable with the solutions
        }

        // Upper triangularize the modified matrix
        temporaryMatrix = UpperTriangularize(temporaryMatrix, matrixSize);

        // Calculate determinant of the modified matrix
        determinants[i] = CalculateDeterminant(temporaryMatrix, matrixSize);

        // Reset the temporary matrix for the next iteration
        temporaryMatrix = matrixCopy(matrix, temporaryMatrix, matrixSize);
    }

    // Free memory allocated for the temporary matrix
    for (int i = 0; i < matrixSize; i++) {
        free(temporaryMatrix[i]);
    }
    free(temporaryMatrix);

    // Free memory allocated for solutions
    free(solutions);

    return determinants;
}

#endif
