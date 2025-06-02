#include "HEADER.h"
#include "gcdLcm.h"
#include "upperTriangularize.h"
#include "matrixOperations.h"
#include "randomMatrixGenerator.h"
#include "detDivProduct.h"
#include "detCalc.h"
#include "ExchangeRows.h"
#include "matrixSimplification.h"
#include "matrixTrace.h"
#include "transpoze.h"
#include "solveUsingCramer.h"

// Global variables for determinant division
long int determinantDivisionProduct = 1;
long int determinantDivisionQuotient = 1;

int main() {
    int matrixSize;

    // Prompt for matrix size
    printf("Enter the size of the square matrix: ");
    scanf_s("%d", &matrixSize);

    // Allocate memory for matrices
    long int** matrix = AllocateMatrix(matrixSize);
    long int** initialMatrix = AllocateMatrix(matrixSize);

    // Prompt for user choice to fill or generate matrix
    while (1) {
        int choice;
        printf("\n\nTo manually input matrix elements, press ---> 1\n"
            "To generate matrix elements within a range, press ---> 2\n"
            "and then press ENTER: ");
        scanf_s("%d", &choice);

        if (choice == 1) {
            matrix = FillMatrix(matrix, matrixSize);
            break;
        }
        else if (choice == 2) {
            matrix = RandomMatrixGenerator(matrix, matrixSize);
            break;
        }
        else {
            ClearConsole();
            printf("INVALID INPUT");
        }
    }

    // Copy the initial matrix
    initialMatrix = matrixCopy(matrix, initialMatrix, matrixSize);

    // Upper triangularize the matrix
    matrix = UpperTriangularize(matrix, matrixSize);

    // Clear console
    ClearConsole();

    // Print original and upper triangular matrices
    printf("ORIGINAL MATRIX\n");
    printMatrix(initialMatrix, matrixSize);
    printf("\nUPPER TRIANGULAR MATRIX\n");
    printMatrix(matrix, matrixSize);

    // Calculate determinant and solutions using Cramer's Rule
    long int detA = CalculateDeterminant(matrix, matrixSize);
    printf("\nDeterminant = %ld", detA);
    long int* determinants = (long int*)(malloc(sizeof(long int) * matrixSize));
    determinants = SolveUsingCramer(initialMatrix, matrixSize);

    for (int i = 0; i < matrixSize; i++) {
        printf("\nX%d = %lf", i + 1, (float)determinants[i] / detA);
    }

    // Print matrix trace and sum of elements
    printf("\n\nMatrix Trace = %ld\n\n", MatrixTrace(initialMatrix, matrixSize));
    printf("Sum of Matrix Elements = %ld\n\n", MatrixElementSum(initialMatrix, matrixSize));

    // Transpose the matrix and print
    printf("TRANSPOSE MATRIX\n");
    long int** transposeMatrix = Transpose(initialMatrix, matrixSize);
    printMatrix(transposeMatrix, matrixSize);

    // Free memory allocated for matrices
    freeMatrix(transposeMatrix, matrixSize);
    freeMatrix(matrix, matrixSize);
    freeMatrix(initialMatrix, matrixSize);

    return 0;
}

// Function to clear console
void ClearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
