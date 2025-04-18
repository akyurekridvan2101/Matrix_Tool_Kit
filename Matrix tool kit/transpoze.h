#ifndef TRANSPOZE_H
#define TRANSPOZE_H

#include "stdlib.h"

long int** transpoze(long int** matrix,int matrix_boyutu) {

    //long int** gecici_matrix = matrix;

    long int** gecici_matrix = (long int**)(malloc(matrix_boyutu * sizeof(long int*)));

    for (int i = 0; i < matrix_boyutu; i++) {
        // Her satır için bellek tahsis et
        gecici_matrix[i] = (long int*)malloc(matrix_boyutu * sizeof(long int));
    }

    for (int satir = 0; satir < matrix_boyutu; satir++) {

        for (int sutun = 0; sutun < matrix_boyutu; sutun++) {

            gecici_matrix[sutun][satir] = matrix[satir][sutun];            
        }
    }

    return gecici_matrix;
}


#endif
