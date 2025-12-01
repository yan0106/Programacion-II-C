#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 2

typedef struct estudiante {
    char nombre[50];
    int edad;
    float promedio;
} Estudiante;

void ingresarEstudiantes (Estudiante *);
void mostrarEstudiante (Estudiante);
Estudiante* encontrarMejorPromedio(Estudiante *lista_estudiantes, int n);

int main (){

Estudiante *estudiante = (Estudiante*) malloc (N * sizeof(Estudiante)); // arreglo de N 2 para la estructura Estudiante

// verificación de malloc
if (estudiante == NULL) {
    printf ("Error: no se puedo reservar memoria\n");
    return 1;
}

// llama a función ingresarEstudiantes()
for (int i = 0; i < N; i++) { // para cargar N estudiantes
    ingresarEstudiantes(&estudiante[i]);
}

// lama a función mostrarEstudiante()
for (int i = 0; i < N; i++) {
    mostrarEstudiante(estudiante[i]);
}

// llama a la función encontrarMejorPromedio()
Estudiante *mejor_promedio = encontrarMejorPromedio(estudiante, N); // no uso malloc pq no estoy creando un nuevo estudiante. Solo estoy guardando la dirección de uno que ya tenía

printf("El estudiante con el mejor promedio es:\n");
printf("Nombre: %s", mejor_promedio->nombre);
printf("Promedio: %.2f\n", mejor_promedio->promedio);

free(estudiante);
return 0;
}

void ingresarEstudiantes(Estudiante *estudiante){
    printf ("\nPor favor, ingrese los datos del estudiante: \n");
    printf ("Nombre: ");
    fgets (estudiante->nombre, 50, stdin);
    printf ("Edad: ");
    scanf ("%d", &estudiante->edad);
    getc (stdin);
    printf ("Promedio: ");
    scanf ("%f", &estudiante->promedio);
    getc (stdin);
}

void mostrarEstudiante (Estudiante est) {
    printf ("\n***Datos cargados de los estudiantes***\n");
    printf ("Nombre: %s", est.nombre);
    printf ("Edad: %d\n", est.edad);
    printf ("Promedio: %.2f\n", est.promedio);
}

Estudiante* encontrarMejorPromedio(Estudiante *lista_estudiantes, int n) {
    float max_promedio = 0;
    Estudiante *mejor_promedio = NULL;
    for (int i = 0; i < n; i++){
        if (lista_estudiantes[i].promedio > max_promedio) {
            max_promedio = lista_estudiantes[i].promedio;
            mejor_promedio = &lista_estudiantes[i]; // le tengo que asignar la dirección de lista_estudiantes[i] al puntero
        }
    }
return mejor_promedio;
}

