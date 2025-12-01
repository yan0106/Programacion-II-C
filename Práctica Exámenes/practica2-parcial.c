#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Definición base

typedef struct {
    char nombre[20]; // arreglo
    int edad;
    float peso;
} mascota;

mascota* directorio[5]; // Global

int buscarMascota(char*);
int agregarMascota(char*, int, float);
int eliminarMascota(char*);

int contarMascotas();
void mostrarTodas();
int modificarMascota(char *nombre, char *n_nombre, int n_edad, float n_peso);
void mostrarMayorPeso();

int main () {

return 0;
}

// 1) contarMascotas()
//   Debe recorrer el directorio y retornar la cantidad de posiciones
//   que contienen una mascota (punteros NO NULL).
int contarMascotas() {
    int contador = 0;
    for (int i = 0; i < 5; i++) {
        if (directorio[i] != NULL) {
            contador = contador + 1;
        }
    }
    return contador;
}

// 2) mostrarTodas()
// Debe recorrer el directorio y mostrar por pantalla todas las mascotas
// registradas. Si el directorio está vacío, mostrar un mensaje indicándolo.

void mostrarTodas() {
    printf ("---Mascotas---\n");
    int contador = 0;
    for (int i = 0; i < 5; i++) {
        if (directorio[i] != NULL) {
            printf ("Mascota %d:\n", i+1);
            printf ("Nombre: %s\n", directorio[i]->nombre);
            printf ("Edad: %d\n", directorio[i]->edad);
            printf ("Peso: %.2f\n", directorio[i]->peso);
            contador = contador + 1;
            }
    }
    if (contador == 0) {
        printf ("El directorio está vacío.\n");
    }
}

int modificarMascota(char *nombre, char *n_nombre, int n_edad, float n_peso) {
    for (int i = 0; i < 5; i++) {
        if (directorio[i] != NULL) {
            if (strcmp (nombre, directorio[i]->nombre) == 0) {
                strcpy (directorio[i]->nombre, n_nombre);
                 directorio[i]->edad = n_edad;
                 directorio[i]->peso = n_peso;
                 return 0;
            }
        }
    }
    printf ("Mascota no encontrada.\n");
    return -1;
}

// mostrarMayorPeso()
// Debe encontrar la mascota de mayor peso del directorio.
// Mostrar sus datos por pantalla.
// Si el directorio está vacío, indicarlo.
void mostrarMayorPeso() {
    mascota* mayor = NULL; // puntero a mascota
    for (int i = 0; i < 5; i++) {
        if (directorio[i] != NULL){ // verifico que no sea NULL
            if (mayor == NULL) {
                mayor = directorio [i]; // le asigno al puntero al menos una direccion para poder empezar a comparar
            } else if (directorio[i]->peso > mayor->peso) { // comparo dos float
                    mayor = directorio[i]; // le paso la direccion de la mascota entera porque mayor es un puntero
            }
        }
    }
    if (mayor == NULL) {
        printf ("No hay mascotas registradas.\n");
    } else {
            printf ("---Mascota de Mayor peso---\n");
            printf ("Nombre: %s\n", mayor->nombre);
            printf ("Edad: %d\n", mayor->edad);
            printf ("Peso: %.2f\n", mayor->peso);
    }
}
