#include "HEADER.h"
#include "ebobEkok.h"
#include "upperTriangularize.h"
#include "matrixOperations.h"
#include "randomMatrixGenerator.h"


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

    printf("\x1b[31m\n");//Rengi kırmızı yaptı
    printMatrix(baslangictaki_matrix,matrix_boyutu);//İlk yazılan matrisi ekrana yazdırdı
    printf("\x1b[32m\n");//Rengi yeşil yaptı
    printMatrix(matrix,matrix_boyutu);//İlk yazılan matrisin üst üçgen halini ekrana yazdırdı
    printf("\x1b[0m\n");//Rengi default değer yaptı

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
