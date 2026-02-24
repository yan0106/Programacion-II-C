// Pila TDA (con arrays)
// LIFO

/*El orden de las operaciones:
- Al apilar, primero incrementar el índice y luego guardar el dato.
- Al desapilar, primero capturar el dato y luego decrementar el índice. 
Las precondiciones: No olvidar las validaciones de "Pila Llena" (Overflow) y 
"Pila Vacía" (Underflow) antes de mover el índice */

#include <stdio.h>
#include "PilaArray.h"

// variables globales
int elementos [CAPACIDAD];
int cima = -1; // posición del último elem del array

int main () {

    // Armar código de main para probar la Pila

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
        return -1; // hubo un error, el array está vacío
    } else {
        int elem = elementos[cima]; // 1. Leo el elemento
        cima = cima -1; // 2. Bajo cima
        return elem; // 3. retorno el elemento eliminado
    } 
}

void vaciaPila() {
    cima = -1;
}

int tamaño() {
    return cima+1;
}

/* int estaVacia(){
    if (cima == -1){
        return 1; // verdadero
    } else {
        return 0; // falso
    }
}*/

int estaVacia() {
    return cima == -1; // si se cumple retorna 1, sino retorna 0
}

int obtenerCima() {
    if (estaVacia()) {
        return -1;
    } else {
        return elementos[cima] ;
    }
}