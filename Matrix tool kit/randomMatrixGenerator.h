#ifndef randomMatrixGenerator_H
#define randomMatrixGenerator_H

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

// Function to generate a random matrix within a given range
long int** RandomMatrixGenerator(long int** matrix, int matrixSize) {
    long int minNumber, maxNumber;

    ClearConsole();

    // Prompt for minimum and maximum numbers
    while (1) {
        printf("Enter the minimum number: ");
        scanf_s("%ld", &minNumber);

        printf("Enter the maximum number: ");
        scanf_s("%ld", &maxNumber);

        if (minNumber < maxNumber) {
            break;  // Exit the loop if the condition is satisfied
        }
        else {
            ClearConsole();
            printf("\nInvalid input! The minimum number should be less than the maximum number.\n\n");
        }
    }

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Generate random numbers for each element in the matrix
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            matrix[i][j] = rand() % (maxNumber - minNumber + 1) + minNumber;
        }
    }

    return matrix;
}

#endif
