#include <stdio.h>
#include "Pila.h"

void cargar_pila(TPila * P) {
    FILE * archivo = fopen("..\\numeros.txt", "r");
    IniciaP(P);

    int numActual;
    while (fscanf(archivo, "%d", &numActual) == 1) {
        poneP(P, numActual);
    }
}

void mostrar_pila(TPila P) {
    for (int i = 0; i <= P.tope; i++) {
        printf("%d: %d\n", i, P.datos[i]);
    }
}

void mostrar_pila_quitando_elementos(TPila * P) {
    int num;
    while (!VaciaP(*P)) {
        sacaP(P, &num);
        printf("%d\n", num);
    }
}

int main() {
    TPila P;

    cargar_pila(&P);
    mostrar_pila(P);
    mostrar_pila_quitando_elementos(&P);

    return 0;
}
