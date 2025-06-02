#ifndef HEADER_H
#define HEADER_H

/*
    File: HEADER.h
    ---------------
    This header file contains function prototypes for various matrix operations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
long int FindGCD(long int a, long int b);
long int FindLCM(long int a, long int b);
long int** UpperTriangularize(long int** matrix, int matrixSize);
void printMatrix(long int** matrix, int matrixSize); // Reformat matrix elements for better display
long int** AllocateMatrix(int matrixSize);
long int** FillMatrix(long int** matrix, int matrixSize);
void freeMatrix(long int** matrix, int matrixSize);
long int** RandomMatrixGenerator(long int** matrix, int matrixSize);
long int** matrixCopy(long int** sourceMatrix, long int** destinationMatrix, int matrixSize);
void ClearConsole();
long int CalculateDeterminant(long int** matrix, int matrixSize);
long int AbsoluteValue(long int number);
long int** ExchangeRows(long int** matrix, int matrixSize, int currentRow);
long int** SimplifyMatrix(long int** matrix, int matrixSize, int currentRow);

#endif
