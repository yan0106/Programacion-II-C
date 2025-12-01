#include <stdio.h>
#define ALUMNOS 4
#define NOTAS 4

void crearMatrizNotas(float Matriz[ALUMNOS][NOTAS]);
void imprimirMatrizNotas (float Matriz[ALUMNOS][NOTAS]);
void imprimirPromedio (float Matriz[ALUMNOS][NOTAS]);

/*visualizar en pantalla el numero de cada estudiante seguido por su promedio,
ademas se debera imprimir al lado "libre", regular.o "promovido", si dicho promedio
esta en los intervalos [0,6), [6,8) y [8,10] respectivamente*/

int main () {

float Matriz [ALUMNOS][NOTAS] = {0.0}; // inicializo en 0 la matriz para que no tenga basura

crearMatrizNotas(Matriz);

printf("\nEsta es la Matriz de Notas:\n\n");
imprimirMatrizNotas(Matriz);

imprimirPromedio(Matriz);

return 0;
}

void crearMatrizNotas(float Matriz[ALUMNOS][NOTAS]) {
    for (int i=0; i<ALUMNOS; i++){
        printf ("\nAlumno %d:\n", i+1);
        for (int j=0; j<NOTAS; j++ ){
            printf ("Por favor, ingrese la nota obtenida %d: ", j+1);
            scanf("%f", &Matriz[i][j]);
        }
    }
}

void imprimirMatrizNotas (float Matriz[ALUMNOS][NOTAS]) {
    for (int i=0; i<ALUMNOS; i++){
        for (int j=0; j<NOTAS; j++) {
                printf("%6.1f ", Matriz[i][j]);
            }
        printf("\n");
    }
}

void imprimirPromedio (float Matriz[ALUMNOS][NOTAS]) {
    for (int i=0; i<ALUMNOS; i++){
        float suma = 0;
        for (int j=0; j<NOTAS; j++){
            suma = suma + Matriz [i][j];
        }
        float promedio = suma / NOTAS;
        printf("\nAlumno %d: promedio = %.2f\n", i+1, promedio);
        if (promedio < 6) {
            printf ("Libre\n");
        } else if (promedio < 8) {
            printf("Regular\n");
        } else { // el else no tiene que tener condicion
            printf("Promovido\n");
        }
    }
}



