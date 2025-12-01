#include <stdio.h>
#define FILAS 4
#define COLUMNAS 4

void generarMatriz1 (int Matriz1[FILAS][COLUMNAS]);
void generarMatriz2 (int Matriz2[FILAS][COLUMNAS]);
void imprimirMatriz1 (int Matriz1[FILAS][COLUMNAS]);
void sumarMatrices (int Matriz1[FILAS][COLUMNAS], int Matriz2[FILAS][COLUMNAS]);

int main () {

int Matriz1[FILAS][COLUMNAS];
int Matriz2[FILAS][COLUMNAS];
generarMatriz1(Matriz1);
imprimirMatriz1(Matriz1);

generarMatriz2([FILAS][COLUMNAS]);
imprimirMatriz2([FILAS][COLUMNAS]);


return 0;
}

void generarMatriz1 (int Matriz1[FILAS][COLUMNAS]){
    Matriz1[FILAS][COLUMNAS] = {
    {1, 2, 1, 3},
    {1, 4, 5, 6},
    {6, 2, 1, 6},
    {7, 4, 3, 1};
    }
}

void imprimirMatriz1 (int Matriz1[FILAS][COLUMNAS]){
    for (int i=0; i<FILAS; i++){
        for (int j=0; j<COLUMNAS; j++){
        printf("%d", Matriz1[i][j]);
        }
    }
}

void generarMatriz2 (int Matriz2[FILAS][COLUMNAS]) {


}

