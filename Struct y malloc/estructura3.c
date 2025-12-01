#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia, mes, anio;
} Fecha;

typedef struct {
    char nombre [30];
    Fecha cumple;
} Persona;

void crearPersona(Persona *p);
void imprimirPersona (Persona p);

int main () {

    Persona p;
    Persona *pp = &p;

    /*p.cumple.dia = 1;
    p.cumple.mes = 6;
    p.cumple.anio = 1990;
    strcpy(p.nombre, "Yandira");*/

    crearPersona(pp);
    imprimirPersona(p);



return 0;
}

void crearPersona(Persona *p) {
    printf ("Nombre: ");
    fgets (p->nombre, 30, stdin);
    printf ("Fecha de cumpleanios (dd/mm/aaaa): ");
    //getc (stdin);
    scanf("%d/%d/%d", &p->cumple.dia, &p->cumple.mes, &p->cumple.anio);
}

void imprimirPersona (Persona p) {
     printf("\n%s", p.nombre);
     printf("%d/%d/%d", p.cumple.dia, p.cumple.mes, p.cumple.anio);
}

