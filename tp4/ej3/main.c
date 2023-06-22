#include <stdio.h>

float promedio(int *arr, int n) {
    if (n == 0) {
        return 0;
    }

    float res = arr[n - 1] + promedio(arr, n - 1) * (n - 1);

    return res / n;
}

void mostrar_caso(float num) {
    printf("%f\n", num);
}

void test() {
    int arr[] = {1, 6, 5, 7, 5, 4, 7, 6};
    int arr2[] = {-31, 67, 52, 67, 5, 4, 57, 6};
    int arr3[] = {-82, -6, -5, -7, -5, 4, 7, 6};
    int arr4[] = {};
    int arr5[] = {-1};

    mostrar_caso(promedio(arr, 8)); // 5.125
    mostrar_caso(promedio(arr2, 8)); // 28.375
    mostrar_caso(promedio(arr3, 8)); // 11
    mostrar_caso(promedio(arr4, 0)); // 0
    mostrar_caso(promedio(arr5, 1)); // -1
}

int main() {
    test();
    return 0;
}
