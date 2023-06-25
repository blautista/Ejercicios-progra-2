#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo * sig;
} Nodo;

typedef Nodo * TLista;

typedef struct NodoDoble {
    int dato;
    struct NodoDoble * sig;
    struct NodoDoble * ant;
} NodoDoble;

typedef NodoDoble * PNodoDoble;

typedef struct {
    PNodoDoble pri, ult;
} TListaDoble;

void inicializar_lista(TLista * lista) {
    int arr[] = { 8,7,6,5,4,3,2,1};

    for (int i = 0; i < 8; i++) {
        TLista nuevo = (TLista) malloc(sizeof(Nodo));
        nuevo->dato = arr[i];
        nuevo->sig = *lista;
        (*lista) = nuevo;
    }
}

void copiar_simple_a_circular(TLista lista, TLista * listaCircular) {
    TLista act = lista;

    while (act != NULL) {
        TLista nuevo = (TLista) malloc(sizeof(Nodo));

        nuevo->dato = act->dato;

        if (*listaCircular == NULL) {
            nuevo->sig = nuevo;
            *listaCircular = nuevo;
        } else {
            nuevo->sig = (*listaCircular)->sig;
            (*listaCircular)->sig = nuevo;
            *listaCircular = nuevo;
        }

        act = act->sig;
    }
}

void copiar_simple_a_doble(TLista lista, TListaDoble * listaDoble) {
    TLista act = lista;

    listaDoble->pri = NULL;
    listaDoble->ult = NULL;

    while (act != NULL) {
        PNodoDoble nuevo = (PNodoDoble) malloc(sizeof(NodoDoble));

        nuevo->dato = act->dato;
        nuevo->sig = NULL;
        nuevo->ant = NULL;

        if (listaDoble->pri == NULL) {
            listaDoble->pri = nuevo;
            listaDoble->ult = nuevo;
        } else {
            listaDoble->ult->sig = nuevo;
            nuevo->ant = listaDoble->ult;
            listaDoble->ult = nuevo;
        }

        act = act->sig;
    }
}

void mostrar_lista(TLista lista) {
    TLista aux = lista;

    while (aux != NULL) {
        printf("%d, ", aux->dato);
        aux = aux->sig;
    }

    printf("\n");
}

void mostrar_lista_doble(TListaDoble lista) {
    PNodoDoble aux = lista.pri;

    while (aux != NULL) {
        printf("%d, ", aux->dato);
        aux = aux->sig;
    }

    printf("\n");
}

void mostrar_lista_circular(TLista lista) {
    TLista aux = lista->sig;

    do {
        printf("%d", aux->dato);
        aux = aux->sig;
    } while (aux != lista->sig);

    printf("\n");
}

/*
 * Copiar el contenido completo de una lista simplemente enlazada en una lista doblemente
 * enlazada y en una lista circular. En ambos casos se debe mantener el orden de la lista original.
 * La lista original no debe ser modificada.
 */
int main() {
    TLista lista = NULL;
    TLista listaCircular = NULL;
    TListaDoble listaDoble;

    inicializar_lista(&lista);
    mostrar_lista(lista);

    copiar_simple_a_circular(lista, &listaCircular);
    mostrar_lista_circular(listaCircular);

    copiar_simple_a_doble(lista, &listaDoble);
    mostrar_lista_doble(listaDoble);
    return 0;
}
