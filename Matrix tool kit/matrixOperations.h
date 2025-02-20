#ifndef matrixOperations_H
#define matrixOperations_H

#include "HEADER.h"

//Pointerlara malloc sayesinde bellek ataması yapar
long int** allocateMatrix(int matrix_boyutu) {

    long int** matrix = (long int**)malloc(sizeof(long int*) * matrix_boyutu);

    for (int i = 0; i < matrix_boyutu; i++) {

        matrix[i] = (long int*)(malloc(sizeof(long int) * matrix_boyutu));
    }

    return matrix;
}

//Matrisin elemanlarına değer ataması yapar
long int** fill_matris(long int** matrix,int matrix_boyutu) {

    long int sayi;
    
    for (int i = 0; i < matrix_boyutu; i++) {

        for (int j = 0; j < matrix_boyutu; j++) {

            printf("\nmatris[%d][%d] : ",i+1,j+1);
            scanf("%ld",&sayi);
            matrix[i][j] = sayi;
        }
    }

    return matrix;
}

//Matriste işlem satırının ilk elemanı 0 olduğunda 0 olmayana kadar matristeki iki satırın yerini değiştirir
long int** satir_degistirme(long int** matrix,int matrix_boyutu,int bulunulan_satir,int degistirilecek_satir) {

    for (int i = 0; i < matrix_boyutu; i++) {

        int temp = matrix[bulunulan_satir][i];
        matrix[bulunulan_satir][i] = matrix[degistirilecek_satir][i];
        matrix[degistirilecek_satir][i] = temp;
    }

    return matrix;
}

void printMatrix(long int** matrix,int matrix_boyutu) {
    for (int i = 0; i < matrix_boyutu; i++) {

        for (int j = 0; j < matrix_boyutu; j++) {
            printf("%ld   ",matrix[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(long int** matrix, int matrix_boyutu) {
    for (int i = 0; i < matrix_boyutu; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

/*matrix'ten baslangictaki_matrix'e kopyalama işlemi gerçekleştiriliyor.*/
long int** matrixCopy(long int** kopyalanacak,long int** kopyalanilacak,int matrix_boyutu) {

    for (int i = 0; i < matrix_boyutu; i++) {

        for (int j = 0; j < matrix_boyutu; j++) {

            kopyalanilacak[i][j] = kopyalanacak[i][j];
        }
    }

    return kopyalanilacak;

}

#endif