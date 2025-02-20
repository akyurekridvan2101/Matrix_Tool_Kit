#ifndef randomMatrixGenerator_H
#define randomMatrixGenerator_H

#include <time.h>
#include <stdlib.h>
#include <stdio.h>


long int** randomMatrixGenerator(long int** matrix,int matrix_boyutu) {

    long int minSayi, maxSayi;

    clearConsole();

    while (1) {
        printf("Min sayiyi giriniz: ");
        scanf("%ld", &minSayi);

        printf("Max sayiyi giriniz: ");
        scanf("%ld", &maxSayi);

        if (minSayi < maxSayi) {
            break;  // Koşul sağlandığında döngüden çık
        }
        else {
            clearConsole();
            printf("\nHatali giris! Min sayi, max sayidan kucuk olmalidir.\n\n");
        }
    }

    srand((unsigned int)time(NULL));
    for (int i = 0; i < matrix_boyutu; i++) {
        for (int j = 0; j < matrix_boyutu; j++) {
            matrix[i][j] = rand() % (maxSayi - minSayi + 1) + minSayi;// Belirli aralıkta rastgele sayı üretme formülü
        }
    }

    return matrix;

}

#endif