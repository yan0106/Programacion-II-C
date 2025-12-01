#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Dados las siguientes definiciones y prototipos

typedef struct{
    char nombre[20]; // arreglo
    int edad;
    float peso;
} mascota;

// Se pretende programar un directorio de mascotas
mascota* directorio[5];

int buscarMascota(char*);
int eliminarMascota(char*);
int agregarMascota(char*, int, float);
/**
Implementar un directorio de mascotas, el cual guardará mascotas.
a) Está formado por un arreglo de punteros a estructuras mascota.
b) La función buscarMascota recibe el nombre de la mascota y recorrerá el
   directorio; si encuentra la mascota la muestra por pantalla (nombre, edad y peso)
   y retorna 0 como OK. Cualquier otro número como error o registro no encontrado.
c) eliminarMascota elimina a la mascota, si es que existe en el directorio
   (antes muestra los datos por pantalla) retorna 0 si la operación se realizó
   correctamente; cualquier otro valor para cualquier otro error.
d) agregarMascota inserta, alocando previamente la memoria, una mascota en el
   directorio. Los parámetros de entrada son el nombre, la edad y el peso
   respectivamente. Retorna 0 en caso que la inserción sea correcta, y cualquier
   otro valor en caso de cualquier otro error.

*/
int main () {

    for (int i = 0; i < 5; i++){
        directorio[i] = NULL;
    }

return 0;
}

int buscarMascota(char *nombre) {
    for (int i = 0; i < 5; i++) {
        if (directorio[i] != NULL) {
            if (strcmp (nombre, directorio[i]->nombre) == 0) {
                printf ("Nombre: %s\n", directorio[i]->nombre);
                printf ("Edad: %d\n", directorio[i]->edad);
                printf ("Peso: %.2f\n", directorio[i]->peso);
                return 0;
            }
        }
    }
    printf ("Registro no encontrado.\n");
    return -1;
}

int eliminarMascota(char *nombre) {
    for (int i = 0; i < 5; i++){
        if (directorio[i] != NULL) {
            if (strcmp (nombre, directorio[i]->nombre) == 0) {
                printf ("Nombre: %s\n", directorio[i]->nombre);
                printf ("Edad: %d\n", directorio[i]->edad);
                printf ("Peso: %.2f\n", directorio[i]->peso);
                free (directorio[i]);
                directorio[i] = NULL; // para que no quede un puntero colgante
                return 0;
            }
        }
    }
    printf("Error");
    return -1;
}

int agregarMascota(char *nombre, int edad, float peso) {
    for (int i = 0; i < 5; i++) {
        if (directorio[i] == NULL) {
            directorio[i] = (mascota*) malloc (sizeof(mascota));
            strcpy (directorio[i]->nombre, nombre);
            directorio[i]->edad = edad;
            directorio[i]->peso = peso;
            return 0;
        }
    }
    printf ("No se pudo agregar el registro");
    return -1;
}
