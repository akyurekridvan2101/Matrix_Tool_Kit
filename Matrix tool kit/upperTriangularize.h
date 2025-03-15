#ifndef upperTriangularize_H
#define upperTriangularize_H


#include "HEADER.h"
#include "detDiv.h"
#include "satirDegistirme.h"
#include "satirDegistirme.h"

long int** upperTriangularize(long int**matrix,int matrix_boyutu) {

    long int* p_detDivCarpim = &detDivCarpim;

    for(int bulunulan_satir = 0 , bulunulan_sutun = 0 ; bulunulan_sutun < matrix_boyutu - 1 ;bulunulan_sutun++ , bulunulan_satir++) {//son sütunu gezmediği için 4 boyutlu ise 3 sütun gezer.

        matrix = satirDegistirme(matrix,matrix_boyutu,bulunulan_satir);

        sadelestirme(matrix,matrix_boyutu,bulunulan_satir);

        if (matrix[bulunulan_satir][bulunulan_satir] == 0) {
            continue;//alt satır ve yan sütuna geçeriz.Çünkü bu tüm sütunun 0 olduğu anlamına gelir ve bu durumda da determinant = 0 olur çünkü köşegen üstünde en az 1 tane sıfır olmuş olur ve çarpma ve bölme sonucunu 0 yapar.
        }

        //satir_degistirme(matrix,matrix_boyutu,bulunulan_sutun); fonksiyonundan sonra yazmamızın neden satır değiştirme olabilme ihtimalidir.
        int r_1 = matrix[bulunulan_satir][bulunulan_sutun];//r_1 sütun için o sütun bitene kadar değişmeyeceği için en dış for döngüsüne aldıık...

        for (int i = bulunulan_satir + 1; i < matrix_boyutu; i++) {

            if(matrix[i][bulunulan_sutun] == 0)//r_2 = 0 ise zaten o satır için koşul sağlanıyordur.
                continue;
            
            int r_2 = matrix[i][bulunulan_sutun];
            int ekoklari = ekok(r_1,r_2);
            int carpim_r_1;
            int carpim_r_2; 

            if((r_1 > 0 && r_2 > 0) || (r_1 < 0 && r_2 < 0)) {//aynı işaretli ise
            
                carpim_r_1 = -(ekoklari / r_1);
                carpim_r_2 = (ekoklari / r_2);//bu sayıları float det = 1; det *= carpim_r_2; yap en sonda çıkan determinantı bu sayıya böl baştaki matrisin determinantını verir.
            }else if(r_1 > 0 && r_2 < 0) {

                carpim_r_1 = (ekoklari / r_1);
                carpim_r_2 = (ekoklari / (-r_2));//else if e  girmesi için r_2 < 0 ooduğu için (-r_2) satırında pozitif yapıyoruz...
            }else if(r_1 < 0 && r_2 > 0) {

                carpim_r_1 = (ekoklari / (-r_1));//else if e  girmesi için r_1 < 0 ooduğu için (-r_1) satırında pozitif yapıyoruz...
                carpim_r_2 = (ekoklari / r_2);
            }//zaten ikisinden birinin 0 olma ihtimalini yukarıda for dışındaki forda işledik...

            *p_detDivCarpim *= carpim_r_2;

            for (int k = bulunulan_sutun; k < matrix_boyutu; k++) {

                matrix[i][k] = carpim_r_1 * matrix[bulunulan_satir][k] + carpim_r_2 * matrix[i][k];//satır işlemleri yaparak sıfırlanır.
            }

        }
    }

    return matrix;
}

#endif
