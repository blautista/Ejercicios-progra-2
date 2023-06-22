#include <stdio.h>

/*
 * Dada una matriz de NxM enteros, determinar si la suma de los elementos de cada fila es mayor
 * a la suma de los elementos de la fila anterior. Para la primera fila se debe cumplir que la suma
 * de sus elementos sea par.
 */
int resolucion(int arr[][10], int i, int j, int n, int suma, int sumaAnterior) {
    int nuevaSuma = suma + arr[i][j];
    if (i == 0 && j == 0) {
        return nuevaSuma < sumaAnterior && nuevaSuma % 2 == 0;
    }

    if (j == 0) {
        return nuevaSuma < sumaAnterior && resolucion(arr, i - 1, n, n, 0, nuevaSuma);
    }

    return resolucion(arr, i, j - 1, n, nuevaSuma, sumaAnterior);
}

void test() {
    int arr[][10] = {
            { 1, 2, 3, 4}, // 10 y par
            { 3, 3, 4, 5}, // 15
            { 4, 3, 4, 5}, // 16
            { 5, 3, 4, 5}, // 17
    };

    printf("%d", resolucion(arr, 3, 3, 3, 0, 99));
}

int main() {
    test();
    return 0;
}
