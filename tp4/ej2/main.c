#include <stdio.h>

int producto(unsigned int a, unsigned int b) {
    if (b == 0) {
        return 0;
    }

    return a + producto(a, b - 1);
}

int resto(unsigned int a, unsigned int b) {
    if (a < b) {
        return a;
    }

    return resto(a - b, b);
}

int cociente(unsigned int a, unsigned int b) {
    if (a < b) {
        return 0;
    }

    return 1 + cociente(a - b, b);
}

int max(int a, int b) {
    return a > b ? a : b;
}

int arr_max(int * arr, int N) {
    if (N == 0) {
        return arr[0];
    }

    return max(arr[N], arr_max(arr, N - 1));
}

void arr_max_void(int * arr, int n, int max) {
    if (n >= 0) {
        int nuevoMax = max;

        if (arr[n] > max) {
            nuevoMax = arr[n];
        }

        arr_max_void(arr, n - 1, nuevoMax);
    } else {
        printf("MAX (funcion void): %d", max);
    }
}

void test() {
    printf("COCIENTE 7/3: %d\n", cociente(7, 3)); //2
    printf("RESTO 7/3: %d\n", resto(7, 3)); //1
    printf("COCIENTE 24/16: %d\n", cociente(24, 16)); //1
    printf("RESTO 24/16: %d\n", resto(24, 16)); //8

    int arr[] = {-18,16,5,-8,17,9, 0};
    printf("MAX (funcion int): %d\n", arr_max(arr, 5));
    arr_max_void(arr, 5, -99);
}

int main() {
    test();
    return 0;
}
