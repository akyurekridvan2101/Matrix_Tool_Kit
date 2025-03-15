#include "detDiv.h"
#include "ebobEkok.h"
#include <stdio.h>

long int** sadelestirme(long int** matrix,int matrix_boyutu,int bulunulan_satir) {

    long int* p_detDivBolum = &detDivBolum;

    for (int t = bulunulan_satir; t < matrix_boyutu; t++) {

        long int ebobu = matrix[t][bulunulan_satir];

        for (int e = bulunulan_satir + 1; e < matrix_boyutu; e++) {

            ebobu = ebob(ebobu , matrix[t][e]);

            if (ebobu == 1)
                break;
        }

        if (ebobu != 1) {

            for (int b = bulunulan_satir; b < matrix_boyutu; b++) {

                matrix[t][b] /= ebobu;
            }

            *p_detDivBolum *= ebobu;
        }
    }

    return matrix;
}
