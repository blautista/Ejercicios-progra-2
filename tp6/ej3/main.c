#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Palabra {
    char valor[30];
    int apariciones;
    struct Palabra * sig;
} Palabra;

typedef Palabra * TLista;

TLista crear_nodo(char palabra[30]) {
    TLista aux = (TLista)malloc(sizeof(Palabra));

    aux->apariciones = 1;
    aux->sig = NULL;

    strcpy(aux->valor, palabra);

    return aux;
}

void procesar_palabra(TLista * lista, char palabra[30]) {
    TLista nuevo, act, ant;

    if (*lista == NULL || strcmp(palabra, (*lista)->valor) < 0) {
        nuevo = crear_nodo(palabra);
        nuevo->sig = *lista;
        *lista = nuevo;
    } else {
        act = *lista;
        ant = NULL;

        while (act != NULL && strcmp(palabra, act->valor) > 0) {
            ant = act;
            act = act->sig;
        }

        if (act == NULL) {
            nuevo = crear_nodo(palabra);
            ant->sig = nuevo;
        } else if (strcmp(palabra, act->valor) == 0) {
            act->apariciones++;
        } else {
            nuevo = crear_nodo(palabra);
            ant->sig = nuevo;
            nuevo->sig = act;
        }
    }
}

void iniciar_lista(TLista * lista) {
    FILE * archivo = fopen("..\\palabras.txt", "r");

    if (archivo == NULL) {
        printf("el archivo no ta maestro");
    }

    char palabra[30];

    while (fscanf(archivo, "%s", palabra) == 1) {
        procesar_palabra(lista, palabra);
    }

    fclose(archivo);
}

void mostrar_lista(TLista lista) {
    TLista aux = lista;

    while (aux != NULL) {
        printf("PALABRA: %s. APARICIONES: %d.\n", aux->valor, aux->apariciones);
        aux = aux->sig;
    }
}

int main() {
    TLista lista;
    iniciar_lista(&lista);
    mostrar_lista(lista);
    return 0;
}
