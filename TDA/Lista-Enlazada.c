#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int dato;
    struct nodo * sgte;
} lista;

int main () {

    return 0;
}

void listar (lista * i) {
    if (i != NULL) {
        printf ("elemento:= %d\n", i->dato);
        listar (i->sgte);
    }
}