#include "HEADER.h"
#include "ebobEkok.h"
#include "upperTriangularize.h"
#include "matrixOperations.h"
#include "randomMatrixGenerator.h"
#include "detDiv.h"
#include "calcDet.h"
#include "satirDegistirme.h"
#include "sadelestirme.h"
#include "matrixIzi.h"
#include "transpoze.h"
#include "solveUsingCramer.h"

long int detDivCarpim = 1;//DETERMİNANT SAYACINA 1 VERDİK ÇÜNKÜ 1 BÖLMEDE ETKİSİZ ELEMANDIR.
long int detDivBolum = 1;


int main()
{
    int matrix_boyutu;

    printf("Kare matrisin boyutunu giriniz : ");
    scanf("%d",&matrix_boyutu);

    long int** matrix = allocateMatrix(matrix_boyutu);//Ana matrisimiz
    long int** baslangictaki_matrix = allocateMatrix(matrix_boyutu);//ilk girilen matrisi kopyalayıp en son ekrana yazdıracağımız matrisimiz

    while (1)
    {
        int tercih;
        printf("\n\nMatrisin elemanlarini kendiniz atamak istiyorsaniz ---> 1\n"
        "Gireceginiz araliga gore sistem tarafindan atanmasini istiyorsaniz ---> 2\n"
        "yazip ENTER tusuna basiniz : ");
        scanf("%d",&tercih);

        if (tercih == 1) {
            matrix = fill_matris(matrix,matrix_boyutu);//Matrise eleman atanıyor
            break;
        }else if (tercih == 2) {
            matrix = randomMatrixGenerator(matrix,matrix_boyutu);
            break;
        } else {
            clearConsole();
            printf("YANLIS TUSLAMA");
        }
    }

    baslangictaki_matrix = matrixCopy(matrix,baslangictaki_matrix,matrix_boyutu);
    
    matrix = upperTriangularize(matrix,matrix_boyutu);//Üst üçgen matris haline getiriliyor

    

    clearConsole();

    printf("GIRILEN MATRIX\n");
    printMatrix(baslangictaki_matrix,matrix_boyutu);//İlk yazılan matrisi ekrana yazdırdı
    printf("\nUST UCGEN MATRIX\n");
    printMatrix(matrix,matrix_boyutu);//İlk yazılan matrisin üst üçgen halini ekrana yazdırdı

    long int detA = calcDet(matrix,matrix_boyutu);
    printf("\nDeterminant = %ld",detA);
    long int* determinantlar = (long int*)(malloc(sizeof(long int) * matrix_boyutu));
    determinantlar = solveUsingCramer(baslangictaki_matrix , matrix_boyutu);

    for (int i = 0; i < matrix_boyutu; i++) {

        printf("\nX%d = %lf" , i+1 , (float)determinantlar[i] / detA);
    }
    

    printf("\n\nMatrix izi = %ld\n\n",matrisIzi(baslangictaki_matrix,matrix_boyutu));
    printf("Matrix elemanlar toplami = %ld\n\n",matrixElemanlarToplami(baslangictaki_matrix,matrix_boyutu));
    printf("TRANSPOZ MATRIX\n");

    long int** transpoz = transpoze(baslangictaki_matrix,matrix_boyutu);
    printMatrix(transpoz , matrix_boyutu);    

    freeMatrix(transpoz,matrix_boyutu);

    freeMatrix(matrix,matrix_boyutu);//matrix ve baslangictaki_matrix değişkenlerinin tuttuğu belleği serbest bırakarak bellek sızıntılarının önüne geçiyoruz
    freeMatrix(baslangictaki_matrix,matrix_boyutu);

    return 0;
}



void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
