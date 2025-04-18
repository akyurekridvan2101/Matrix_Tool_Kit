#ifndef matrisIzi_H
#define matrisIzi_H

long int matrisIzi(long int** matrix,int matrix_boyutu) {//Köşegendekki elemanların toplamı

    long int iz = 0;

    for (int i = 0; i < matrix_boyutu; i++) {

        iz += matrix[i][i];
    }

    return iz;
}

long int matrixElemanlarToplami(long int** matrix,int matrix_boyutu) {

    long int toplam = 0;

    for (int satir = 0; satir < matrix_boyutu; satir++) {

        for (int sutun = 0; sutun < matrix_boyutu; sutun++) {

            toplam += matrix[satir][sutun];
        }
        
    }

    return toplam;
}


#endif
