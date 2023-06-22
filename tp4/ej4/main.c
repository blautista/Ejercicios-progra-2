#include <stdio.h>

int apariciones(int i, int j, int m, float x, float arr[][10]) {
    if (i == -1) {
        return 0;
    }

    int igual = arr[i][j] == x;

    if (j == 0) {
        return igual + apariciones(i - 1, m, m, x, arr);
    }

    return igual + apariciones(i, j - 1, m, x, arr);
}

void test() {
    int n = 4, m = 4;

    float mat[][10] = {{1, 2, 3, 4},
                       {2, 3, 4, 5},
                       {3, 4, 5, 6},
                       {4, 5, 6, 7}};

    printf("%d", apariciones(n - 1, m - 1, m - 1, 4, mat)); // 4
}

int main() {
    test();
    return 0;
}
