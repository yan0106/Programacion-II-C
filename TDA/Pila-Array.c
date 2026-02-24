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

int desapila() {
    if (estaVacia()) { // verifico si la cola está vacía
        printf("Error: pila vacía");
        return 1; // hubo un error, el array está vacío
    } else {
        int elem = elementos[cima]; // 1. Leo el elemento
        cima = cima -1; // 2. Bajo cima
        return elem; // 3. retorno el elemento eliminado
    } 
}
