#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char * nombre;
    int edad;
} Persona;


int main () {

    Persona p;
    char texto[ ] = "Luciano";
    p.nombre = texto;

    printf ("Nombre: %s\n", p.nombre);

    char otro[ ] = "Martina";

    Persona *pp = &p;
    pp->nombre = otro;

    printf ("Nombre: %s\n", pp->nombre);

return 0;
}
