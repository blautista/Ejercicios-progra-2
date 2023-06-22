#include <stdio.h>

/*
 * Determinar mediante una función “lógica” si una matriz cuadrada de dimensión NxN es
 * simétrica (aij = aji) con respecto a su diagonal.
 */
int es_simetrica_rec(int arr[][10], int i, int j, int n) {
    if (i == -1) {
        return 1;
    }

    if (arr[i][j] != arr[j][i]) {
        return 0;
    }

    if (j == 0) {
        //Recorremos solo el triangulo inferior
        return es_simetrica_rec(arr, i - 1, n - 1, n - 1);
    }

    return es_simetrica_rec(arr, i, j - 1, n);
}

int es_simetrica(int arr[][10], int n) {
    return es_simetrica_rec(arr, n - 1, n - 1, n - 1);
}

void test() {
    int n = 4;
    int simetrica[][10] = {
            {1,2,3,4},
            {2,3,4,5},
            {3,4,5,6},
            {4,5,6,7}
    };

    int noSimetrica[][10] = {
            {1,3,3,4},
            {2,3,4,5},
            {3,4,5,6},
            {4,5,6,7}
    };

    printf("%d\n", es_simetrica(simetrica, n));
    printf("%d\n", es_simetrica(noSimetrica, n));
}

int main() {
    test();
    return 0;
}
