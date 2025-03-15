#ifndef calcDet_H
#define calcDet_H

#include "detDiv.h"

long int calcDet(long int** matrix,int matrix_boyutu) {//en son upper triangular matrisin determinantını detDiv e bölüp baştaki matrisin determinantını buluyoruz.detDiv in 0 olma ihtimali yazdığımız kodlar sayesinde yoktur...

    long int* p_detDivCarpim = &detDivCarpim;
    long int* p_detDivBolum = &detDivBolum;

    long int sonDeterminant = 1;//upper triangular matrisin determinantı
    long int ilkDeterminant;//ilk matrisin determinantı

    for (int i = 0; i < matrix_boyutu; i++) {
        sonDeterminant *= matrix[i][i];
    }
    
    ilkDeterminant = (long int)((sonDeterminant * *p_detDivBolum) / (*p_detDivCarpim));

    return ilkDeterminant;
}

#endif