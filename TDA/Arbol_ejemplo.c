#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo *izq;
    struct Nodo *der;
} nodo;

nodo* createNode(int v);
void preOrden(nodo *n);
void enOrden(nodo *n);
void postOrden(nodo *n);
nodo* search(nodo *n, int v);
nodo* insert(nodo *raiz, int v);

int main() {

   return 0;
}

nodo* createNode(int v) {
   nodo* n = malloc(sizeof(nodo));
   n->valor = v;
   n->izq = NULL;
   n->der = NULL;
   return n;
}

nodo* search(nodo *n, int v) {
   if(n == NULL || n->valor == v) {
       return n;
   } else if(n->valor > v) {
       return search(n->izq, v);
   } else if (n->valor < v) {
       return search(n->der, v);
   }
}

nodo *insert(nodo *n, int v) {
    if (n == NULL) {
         return createNode(v);
    } else if(n->valor > v) {
	n->izq = insert(n->izq, v);
    } else if(n->valor < v) {
	n->der = insert(n->der, v);
    }
    return n;
}

void preOrden(nodo *n) {
    printf("%d\n", n->valor);
    preOrden(n->izq);
    preOrden(n->der);
}

void enOrden(nodo *n) {
    preOrden(n->izq);
    printf("%d\n", n->valor);
    preOrden(n->der);
}
 
void postOrden(nodo *n) {
    preOrden(n->izq);
    preOrden(n->der);
    printf("%d\n", n->valor);
}
