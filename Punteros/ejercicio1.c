#include <stdio.h>
#define N 10

// Matriz identidad: es una matriz cuadrada N×N en la que todos los elementos de la diagonal principal son 1s y todos los demás elementos son 0s

void crearMatrizIdentidad(int matriz[N][N]);

int main () {

    int matriz[N][N];
    crearMatrizIdentidad(matriz);

    printf("Esta es la matriz de identidad: \n\n");
    for (int i=0; i < N; i++) {
        for (int j=0; j < N; j++ ){
            printf ("%d ", matriz[i][j]);
        }
        printf ("\n");
    }

return 0;
}

void crearMatrizIdentidad(int matriz[N][N]) {
for (int i=0; i < N; i++) {
    for (int j=0; j <N; j++) {
        if (i == j) {
            matriz[i][j] = 1;
        } else {
            matriz[i][j] = 0;
        }
    }
}
}
