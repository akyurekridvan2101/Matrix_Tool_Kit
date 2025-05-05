#ifndef solveUsingCramer_H
#define solveUsingCramer_H

#include <stdio.h>
#include <stdlib.h>

#include "upperTriangularize.h"
#include "matrixOperations.h"

long int* solveUsingCramer(long int** matrix,int matrix_boyutu) {

    long int* determinantlar = (long int*)(malloc(sizeof(long int) * matrix_boyutu));
    long int* cevaplar = (long int*)(malloc(sizeof(long int) * matrix_boyutu));
    long int** gecici_matrix = allocateMatrix(matrix_boyutu);

    for (int i = 0; i < matrix_boyutu; i++) {

        printf("\nMatrix'in %d. satirinin cevabi : '" , i+1);
        scanf("%ld" , &cevaplar[i]);
    }
    
    printf("1 ");
    gecici_matrix = matrixCopy(matrix , gecici_matrix , matrix_boyutu);
    printf("2 ");

    for (int i = 0; i < matrix_boyutu; i++) {
        printf("i = %d  " , i);

        for (int j = 0; j < matrix_boyutu; j++) {
            printf("j = %d  " , j);
            
            gecici_matrix[j][i] = cevaplar[j];
        }

        gecici_matrix = upperTriangularize(gecici_matrix , matrix_boyutu);
        determinantlar[i] = calcDet(gecici_matrix , matrix_boyutu);

        gecici_matrix = matrixCopy(matrix , gecici_matrix , matrix_boyutu);
        
    }

    for (int i = 0; i < matrix_boyutu; i++) {
        
        free(gecici_matrix[i]);
    }

    free(gecici_matrix);
    free(cevaplar);
    
    return determinantlar;
}

#endif
