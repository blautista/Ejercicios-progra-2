#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    char dato;
    struct Nodo * sig;
} Nodo;

typedef Nodo * TLista;

void inicializar_lista(TLista * lista, char * contenido, int n) {
    for (int i = 0; i < n; i++) {
        TLista aux = (TLista) malloc(sizeof(Nodo));
        aux->sig = *lista;
        aux->dato = contenido[i];
        *lista = aux;
    }
}

void mostrar_lista(TLista lista) {
    TLista aux = lista;

    while (aux != NULL) {
        printf("%c", aux->dato);
        aux = aux->sig;
    }
}

int es_vocal(char c) {
    char vocales[5] = {'A', 'E', 'I', 'O', 'U'};

    for (int i = 0; i < 5; i++){
        if (c == vocales[i]) return 1;
    }

    return 0;
}

int obtener_cantidad_vocales(TLista lista) {
    int cant = 0;
    TLista aux = lista;

    while (aux != NULL) {
        if (es_vocal(aux->dato)) {
            cant++;
        }
        aux = aux->sig;
    }

    return cant;
}

int esta_ordenada(TLista lista) {
    TLista act = lista->sig;
    TLista ant = lista;

    while (act != NULL) {
        if (ant->dato > act->dato) {
            return 0;
        }
        ant = act;
        act = act->sig;
    }

    return 1;
}

void eliminar_elemento(TLista * lista, int pos) {
    TLista act = (*lista)->sig, ant = *lista;

    if (pos == 0) {
        *lista = act;
        free(ant);
    } else {
        int posActual = 1;

        while (posActual < pos && act->sig != NULL) {
            ant = act;
            act = act->sig;
            posActual++;
        }

        ant->sig = act->sig;
        free(act);
    }
}

void test() {
    TLista lista = NULL;
    TLista listaInversa = NULL;

    char arr[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char arr2[] = {'G', 'F', 'E', 'D', 'C', 'B', 'A'};

    inicializar_lista(&lista, arr, 7);
    inicializar_lista(&listaInversa, arr2, 7);

    //b
    printf("CANTIDAD DE VOCALES: %d\n", obtener_cantidad_vocales(lista));
    //c
    mostrar_lista(lista);
    printf(" ORDENADA?: %s\n", esta_ordenada(lista) ? "Si": "No");

    mostrar_lista(listaInversa);
    printf(" ORDENADA?: %s\n\n", esta_ordenada(listaInversa) ? "Si": "No");

    printf("Eliminando indice 3\n");
    eliminar_elemento(&lista, 0);
    mostrar_lista(lista);

    printf("\nEliminando indice 0\n");
    eliminar_elemento(&lista, 0);
    mostrar_lista(lista);

    printf("\nEliminando indice 9999 (borra el ultimo)\n");
    eliminar_elemento(&lista, 9999);
    mostrar_lista(lista);
}

int main() {
    test();
    return 0;
}
