#include <stdio.h>
#include <stdlib.h>

int main () {

    char *mensaje = "ABC"; // tiene el \0
    char arr[4] = { 'A', 'B', 'C', '\0' };

    printf("%c\n", arr[1]);
    printf("%s\n", arr);

    char *parr = arr; // se comporta como puntero al primer elemento
    printf("%p\n", parr); // muestra la dirección
    printf("%c\n", *parr); // desreferencia parr y muestra el contenido: 'A'

    printf("%c\n", *(parr+2)); // aritmética de punteros

    // Dos formas de recorrer y mostrar el contenido del array:
    for (int i = 0; i < 3; i++) {
        printf("%c", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf("%p: %c\n", (parr+i), *(parr+i)); // sin * accedo a la dirección de memoria, con * accedo al contenido
    }
    printf("\n");

    return 0;
}
