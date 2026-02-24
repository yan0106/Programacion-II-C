#include <stdio.h>
#define CAPACIDAD 15

// Pila:
extern int elementos [CAPACIDAD];
extern int cima;

// Prototipos:
void apila(int); // agrega un elemento
int desapila(); // elimina y retorna el primer elemento
void vaciaPila(); // vacía la pila (pasa a tener tamaño 0)
int tamaño(); // da la  cantidad de elementos que posee la pila
int estaVacia(); // indica si la pila tiene o no elementos
int obtenerCima(); // retorna el primer elemento pero no lo elimina

