#include <stdio.h>
#include <stdlib.h>

int ingresarDia ();
char* calcularDia(int dia);

int main () {

int dia = ingresarDia();

char *pdia = calcularDia(dia);

printf ("\nEl dia es: %s\n", pdia); // %s --> espera un puntero a una cadena de caracteres, no le puedo pasar *pdia porque sino mostraría el primer caracter

return 0;
}

int ingresarDia () {
    int dia = 0;
    while (dia < 1 || dia > 7){
    printf("Por favor, ingrese un numero del 1 al 7: \n");
    scanf("%d", &dia);
    }
    return dia;
}

char* calcularDia(int dia) {
    switch (dia) {
        case 1:
            return "Lunes";
        case 2:
            return "Martes";
        case 3:
            return "Miercoles";
        case 4:
            return "Jueves";
        case 5:
            return "Viernes";
        case 6:
            return "Sabado";
        case 7:
            return "Domingo";
    }
}


