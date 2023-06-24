#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo * sig;
} Nodo;

typedef Nodo * TLista;

void generar_lista_normal(TLista * lista, int * arr, int n) {
    TLista aux, act;
    for (int i = 0; i < n; i++) {
        aux = (TLista) malloc(sizeof(Nodo));
        aux->sig = NULL;
        aux->dato = arr[i];

        if (*lista == NULL) {
            *lista = aux;
        } else {
            act->sig = aux;
        }

        act = aux;
    }
}

void generar_lista_invertido(TLista * lista, int * arr, int n) {
    TLista aux;

    for (int i = 0; i < n; i++) {
        aux = (TLista)malloc(sizeof(Nodo));
        aux->sig = *lista;
        aux->dato = arr[i];
        *lista = aux;
    }
}

void generar_lista_ordenada(TLista * lista, int * arr, int n) {
    TLista aux, act, ant;

    for (int i = 0; i < n; i++) {
        aux = (TLista)malloc(sizeof(Nodo));
        aux->sig = NULL;
        aux->dato = arr[i];

        if (*lista == NULL || (*lista)->dato > aux->dato) {
            aux->sig = *lista;
            *lista = aux;
        } else {
            act = *lista;
            ant = NULL;

            while (act != NULL && act->dato < aux->dato) {
                ant = act;
                act = act->sig;
            }

            ant->sig = aux;
            aux->sig = act;
        }
    }
}

void mostrar_lista (TLista lista) {
    TLista aux = lista;

    while (aux != NULL) {
        printf("%d, ", aux->dato);
        aux = aux->sig;
    }

    printf("\n");
}

void test() {
    TLista listaOrdenada = NULL;
    TLista listaInvertida = NULL;
    TLista listaNormal = NULL;

    int arr[] = {8,7,6,5,6,7};

    generar_lista_ordenada(&listaOrdenada, arr, 6);
    printf("ORDENADA: ");
    mostrar_lista(listaOrdenada);

    generar_lista_invertido(&listaInvertida, arr, 6);
    printf("ORDEN INVERTIDO: ");
    mostrar_lista(listaInvertida);

    generar_lista_normal(&listaNormal, arr, 6);
    printf("MISMO ORDEN: ");
    mostrar_lista(listaNormal);
}

int main() {
    test();
    return 0;
}
