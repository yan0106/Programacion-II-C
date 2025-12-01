#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre [20];
    float sueldo;
} Empleado;

void cargarEmpleados (Empleado *e, int cant);
void imprimirEmpleados (Empleado *e, int cant);
void buscarEmpleado(char *nombreBuscado, Empleado *e, int cant);

int main() {
    Empleado empleados[5];

    cargarEmpleados(empleados, 5);
    imprimirEmpleados(empleados, 5);
    buscarEmpleado("Yandira", empleados, 5);

return 0;
}

void cargarEmpleados (Empleado *e, int cant) {
    for (int i = 0; i < cant; i++) {
        printf ("Empleado %d:\n", i+1);
        printf ("Nombre: ");
        fgets (e[i].nombre, 20, stdin);
        printf ("Sueldo: ");
        scanf ("%f", &e[i].sueldo);
        getc(stdin);
    }
}

void imprimirEmpleados (Empleado *e, int cant) {
    printf("\n--- Empleados ---\n\n");
    for (int i = 0; i < cant; i++) {
        printf("Empleado %d:\n", i+1);
        printf ("Nombre: %s", e[i].nombre);
        printf ("Sueldo: %.2f\n\n", e[i].sueldo);
    }
}

void buscarEmpleado(char *nombreBuscado, Empleado *e, int cant) {

    // eliminar salto de línea del nombre buscado
    // nombreBuscado[strcspn(nombreBuscado, "\n")] = '\0';

    for (int i = 0; i < cant; i++) {
        if (strcmp(e[i].nombre, nombreBuscado) == 0) {
            printf("\nEmpleado encontrado:\n");
            printf("Nombre: %s\n", e[i].nombre);
            printf("Sueldo: %.2f\n", e[i].sueldo);
            return;
        }
    }
    printf("\nNo se encontro el empleado.\n");
}
