#include <stdio.h>
#include "PilaArray.h"

// variables globales
int elementos [CAPACIDAD];
int cima = -1; // posición del último elem del array

int main () {


    return 0;
}

void apila(int e) {
    if (cima == CAPACIDAD - 1) {
        printf ("Error: no caben más elementos");
    } else {
        cima = cima + 1; // cima = posición 0 
        elementos[cima] = e; // en la posición 0 agrega e
    }
}


