
//HEADER.h dosyası

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonksiyon prototipleri
long int ebob(long int a, long int b);
long int ekok(long int a, long int b);
long int** upperTriangularize(long int**matrix,int matrix_boyutu);
void printMatrix(long int** matrix,int matrix_boyutu);//matrisin 1 elemanı 212 vs olursa kayma oluyor.daha düzgün ekrana basmak için yeniden düzenle...
long int** allocateMatrix(int matrix_boyutu);
long int** fill_matris(long int**matrix,int matrix_boyutu);
void freeMatrix(long int** matrix, int matrix_boyutu);
long int** randomMatrixGenerator(long int** matrix,int matrix_boyutu);
long int** matrixCopy(long int** kopyalanacak,long int** kopyalanilacak,int matrix_boyutu);
void clearConsole();
long int calcDet(long int** matrix,int matrix_boyutu);
long int mutlakDeger(long int sayimiz);
long int** satirDegistirme(long int** matrix,int matrix_boyutu,int bulunulan_satir);
long int** sadelestirme(long int** matrix,int matrix_boyutu,int bulunulan_satir);


#endif
