#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre [30];
    int edad;
} Persona;


int main () {

    Persona p1;

    Persona *pp;
    pp = &p1;

    strcpy(pp->nombre, "Ana");
    pp->edad = 25;

    printf ("%d\n", p1.edad);
    printf ("%s\n", p1.nombre);

return 0;
}
