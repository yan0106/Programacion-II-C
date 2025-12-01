#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x, y;
} Punto;

void cargarPunto (Punto *p);
void mostrar (Punto p);
void mover (Punto *p, int dx, int dy);

int main () {

    Punto *pp = malloc(sizeof(Punto));
    cargarPunto(pp);

    mostrar (*pp);
    mover (pp, 2, 1);
    mostrar (*pp);

    free(pp);
}

void cargarPunto (Punto *p) {
    printf ("Ingrese un entero x: ");
    scanf ("%d", &p->x);
    printf ("Ingrese un entero y: ");
    scanf ("%d", &p->y);
}

void mostrar (Punto p) {
    printf ("El punto es: %d, %d\n", p.x, p.y);
}

void mover (Punto *p, int dx, int dy) {
    p->x = p->x + dx;
    p->y = p->y + dy;
}
