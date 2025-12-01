#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char titulo[50];
    int anio;
} Libro;

Libro* estante[5];

int agregarLibro(char *t, int a);
int eliminarLibro(char *titulo_a_borrar);

int main() {

    for(int i = 0; i < 5; i++) {
            estante[i] = NULL;
    }

    if (agregarLibro("El Principito", 1943) == 0) {
        printf("Libro 1 agregado con exito.\n");
        printf("Chequeo: %s (%d)\n", estante[0]->titulo, estante[0]->anio);
    }
    return 0;
}

int agregarLibro(char *t, int a) {
    for (int i = 0; i < 5; i++){
        if (estante[i] == NULL) {
            estante[i] = (Libro*) malloc(sizeof(Libro));
            strcpy (estante[i]->titulo, t);
            estante[i]->anio = a;
            return 0;
        }
    }
    printf ("Estante lleno");
    return -1; // (Por si está lleno)
}

int eliminarLibro(char *titulo_a_borrar) {
    for (int i = 0; i < 5; i++) {
        if (estante[i] != NULL) {
            if (strcmp (titulo_a_borrar, estante[i]->titulo) == 0){
                free(estante[i]);
                estante[i] = NULL;
                return 0;
            }
        }
    }
    printf("El libro no se encontró\n");
    return -1;
}
