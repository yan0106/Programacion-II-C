#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
    int valor;
    struct Nodo *sig;
} Nodo;

int main () {

    Nodo n1;
    n1.valor = 10;
    n1.sig = NULL;

    Nodo n2;
    n2.valor = 20;
    n1.sig = &n2;

    printf ("Valor de n1: %d\n", n1.valor);
    printf ("Valor de n2: %d\n", n1.sig->valor);

    Nodo *pn;
    pn = &n1;

    printf ("Valor de n1 con puntero: %d\n", pn->valor);
    printf ("Valor de n2 con puntero: %d", pn->sig->valor);

}
