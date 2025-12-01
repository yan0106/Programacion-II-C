#include <stdio.h>
char* calcularDia (char (*pc)[10]); // char* porque devuelve un puntero a char

int main (){

char Dias [7][10] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
char (*pc)[10] = Dias; // pc es un puntero a un arreglo de 10 caracteres. Los paréntesis (*pc) indican que el operador * se aplica a pc antes que el [10].
// Sin paréntesis, char *pc[10] sería un arreglo de 10 punteros a char.

char *punteroChar = (calcularDia(pc)); // *punteroChar porque la función retorna un puntero a char
printf("\nEl dia de la semana es: %s\n", punteroChar);


return 0;
}

char* calcularDia (char (*pc)[10]) { //retorna un puntero a char
    int nro = 0;
    while (nro<1 || nro>7) {
        printf("Por favor, ingresa un numero del 1 al 7: ");
        scanf("%d", &nro);
    }
    /*if (nro == 1) return pc[0];  // Se puede hacer de esta forma manual o de la otra
    else if (nro == 2) return pc[1];
    else if (nro == 3) return pc[2];
    else if (nro == 4) return pc[3];
    else if (nro == 5) return pc[4];
    else if (nro == 6) return pc[5];
    else return pc[6];*/
    return pc[nro-1];
}
