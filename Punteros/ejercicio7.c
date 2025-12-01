#include <stdio.h>
#define N 10
void cargarNumeros (float V[N]);
void imprimirVector (float V[N]);
void imprimirVectorInverso (float *pf);

int main () {

float V[N], *pf;
cargarNumeros(V);
imprimirVector(V);

pf = V; // le paso la dirección del primer elemento del arreglo. No es lo mismo pasarle pf=&V
imprimirVectorInverso(pf);


return 0;
}

void cargarNumeros (float V[N]) {
    for (int i=0; i<10; i++){
        printf("Por favor, ingrese un numero real: ");
        scanf("%f", &V[i]);
    }
}

void imprimirVector (float V[N]) {
    printf("\nLos numeros ingresados son: \n");
    for (int i=0; i<10; i++){
        printf("%.2f\t", V[i]);
    }
}

void imprimirVectorInverso(float *pf) { //recibo un puntero al primer elemento del array
    printf("\n\nEl vector inverso es: \n");
    for (float *ptr = pf + 9; ptr >= pf; ptr--) { //declaro un puntero temporal que apunte al último elemento del array  por eso pi+9, mientras el puntero temporal sea >= pi, el puntero temporal decrementa
        printf("%.2f\t", *ptr); // imprimo el valor que va tomando el puntero temporal
    }
    printf("\n");
}

/*void imprimirVectorInverso (int V[10]) {
    printf("\n\nEl vector inverso es: \n");
    for (int i=9; i>=0; i--) {
        printf("%d\t", V[i]);
    }
    printf("\n");
}*/
