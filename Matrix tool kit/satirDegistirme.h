#ifndef satirDegistirme_H
#define satirDegistirme_H

#include "detDiv.h"

long int mutlakDeger(long int sayimiz) {

    if (sayimiz < 0) {
        sayimiz *= -1;//Negatiften pozitif yaptık.
    }
    
    return sayimiz;
}

long int** satirDegistirme(long int** matrix,int matrix_boyutu,int bulunulan_satir) {

    long int* p_detDivCarpim = &detDivCarpim;

    long int kucukSayi  = matrix[bulunulan_satir][bulunulan_satir];
    int sayininKonumu = bulunulan_satir;
    long int sayimiz;

    for (int i = bulunulan_satir + 1; i < matrix_boyutu; i++) {
        
        sayimiz = mutlakDeger(matrix[i][bulunulan_satir]);

        if (sayimiz == 0) {

            continue;
        }else if ((kucukSayi == 0) /*&& (sayimiz != 0)*/) {//yukarıda (sayimiz == 0) olursa zaten continue ile çıkar buraya gelmez buraya geldiğine göre (sayimiz != 0) koşulu her zaman true dur yani boşuna kontrol etmenin bir anlamı yoktur.

            sayininKonumu = i;
            kucukSayi = sayimiz;
        }else if(sayimiz < mutlakDeger(kucukSayi)) {//sayimiz ve kucukSayi ikisi de sıfır olmazsa çalışır

            sayininKonumu = i;
            kucukSayi = sayimiz;

        }

    }

    if (kucukSayi == 0) {//hiçbir değişiklik olmamıştır demektir ve sütundaki tüm elemanları 0'dır demektir
        return matrix;
    } else if(sayininKonumu == bulunulan_satir) {
        return matrix;//Herhangi bir satır değiştirme yapılmamış demektir.
    }

    long int* temp = matrix[bulunulan_satir];
    matrix[bulunulan_satir] = matrix[sayininKonumu];
    matrix[sayininKonumu] = temp;

    *p_detDivCarpim *= -1;//her satır değişikliğinde determinant işaret değiştirir.
    
    return matrix;
}

#endif
