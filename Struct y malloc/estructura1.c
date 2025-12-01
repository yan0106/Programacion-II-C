#include <stdio.h>
#include <string.h> // para la función strcmp()
#define N 3

typedef struct tiempo {
    int anio, mes, dia, hora, minuto, segundo;
} Tiempo;

typedef struct {
    char *nombre;
    Tiempo ultima_mod;
} Archivo;

int compara_tiempos (Tiempo *t1, Tiempo *t2);
void imprime_tiempo (Tiempo t);
void ordena_alfa (Archivo *lista, int n); // utilizar la función strcmp()
void ordena_temporal (Archivo *lista, int n);

int main () {

    Tiempo t1 = {2025, 10, 14, 10, 36, 24};
    Tiempo t2 = {2024, 05, 24, 14, 02, 44};

    // Prueba función compara_tiempos()
    int resultado = compara_tiempos(&t1, &t2);

    if (resultado == 1) {
        printf("El tiempo t1 es anterior al t2.\n");
    } else if (resultado == -1) {
        printf("El tiempo t1 es posterior al t2.\n");
    } else {
        printf("Ambos tiempos son iguales.\n");
    }

    // Prueba función imprime_tiempo()
    imprime_tiempo(t1);

    // Prueba función ordena_alfa()
    Archivo lista_de_archivos [N]; // declaro un arreglo de 3 elementos de tipo Archivo. SE PODRIA CREAR EL ARREGLO CON MALLOC()

    /*Archivo *lista_de_archivos = (Archivo *) malloc(N * sizeof(Archivo));

    //Verificar si funcionó malloc()
    if (lista_de_archivos == NULL) {
        printf("Error: No se pudo reservar memoria.\n");
        return 1; // Termina con error
    }*/

    // cargo el arreglo con datos
    lista_de_archivos[0].nombre = "notas.txt"; // accedo con . porque no es un puntero
    lista_de_archivos[0].ultima_mod = (Tiempo) {2025, 12, 24, 14, 05, 23};

    lista_de_archivos[1].nombre = "algebra.c";
    lista_de_archivos[1].ultima_mod = (Tiempo) {2025, 10, 03, 18, 20, 34};

    lista_de_archivos[2].nombre = "programacion.doc";
    lista_de_archivos[2].ultima_mod = (Tiempo) {2025, 06, 01, 06, 05, 34};

    printf("\n--Archivos antes de ordenar--\n");
    for (int i = 0; i < N; i++){
        printf("%s\n", lista_de_archivos[i]);
    }

    ordena_alfa(lista_de_archivos, N);

    printf("\n--Archivos luego de ordenar--\n");
    for (int i = 0; i < N; i++){
        printf("%s\n", lista_de_archivos[i]);
    }

    // Prueba de ordena_temporal()
    printf("\n**Archivos de tiempo sin ordenar**\n");
    for (int i = 0; i < N; i++){
        imprime_tiempo (lista_de_archivos[i].ultima_mod);
    }

    ordena_temporal(lista_de_archivos, N);

    printf("\n**Archivos de tiempo ordenados**\n");
    for (int i = 0; i < N; i++){
        imprime_tiempo (lista_de_archivos[i].ultima_mod);
    }


return 0;
}

int compara_tiempos (Tiempo *t1, Tiempo *t2){
    if (t1->anio < t2->anio ){
        return 1;
    } else if (t1->anio > t2->anio) {
        return -1;
    } else { // si los años son iguales
        if (t1->mes < t2->mes){
            return 1;
        } else if (t1->mes > t2->mes) {
            return -1;
        } else { // si los meses son iguales
            if (t1->dia < t2->dia){
                return 1;
            } else if (t1->dia > t2->dia){
                return -1;
            } else { // si los días son iguales
                if (t1->hora < t2->hora){
                    return 1;
                } else if (t1->hora > t2->hora){
                    return -1;
                } else { // si las horas son iguales
                    if (t1->minuto < t2->minuto){
                        return 1;
                    } else if (t1->minuto > t2->minuto){
                        return -1;
                    } else { // si los minutos son iguales
                        if (t1->segundo < t2->segundo) {
                            return 1;
                        } else if (t1->segundo > t2->segundo){
                            return -1;
                        } else { // si los segundos son iguales
                            return 0;  // las fechas son iguales, retorna 0;
                        }
                    }
                }
            }
        }
    }
}

void imprime_tiempo (Tiempo t) {
    printf ("\n%d/%d/%d  %d:%d:%d\n", t.dia, t.mes, t.anio, t.hora, t.minuto, t.segundo);
}

/* La función strcmp() compara dos cadenas de caracteres alfabéticamente.
Funciona como si estuviera buscando las palabras en un diccionario.
Toma dos cadenas, cadena1 y cadena2, y devuelve un número entero:

-Un número negativo (< 0): si cadena1 va antes que cadena2 en el diccionario.
-Cero (0): si cadena1 y cadena2 son idénticas.
-Un número positivo (> 0): si cadena1 va después que cadena2 en el diccionario.*/

void ordena_alfa (Archivo *lista, int n){ // *lista funciona como puntero al primer elemento del arreglo (como si hubiese puesto lista[ ])
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++){
            int resultado = strcmp(lista[i].nombre, lista[j].nombre);
            if (resultado > 0) {
                // intercambiar posiciones
                Archivo temp = lista[i]; // variable temporal del mismo tipo que lista // temp = A
                lista[i] = lista[j]; // A = B
                lista[j] = temp; // B = temp
            }
        }
    }
}

void ordena_temporal (Archivo *lista, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++){
            int resultado = compara_tiempos (&lista[i].ultima_mod, &lista[j].ultima_mod); // compara_tiempos() recibe como parámetros a dos punteros
            if (resultado == -1) {
                // intercambiar posiciones
                Archivo temp = lista[i]; // variable temporal del mismo tipo que lista // temp = A
                lista[i] = lista[j]; // A = B
                lista[j] = temp; // B = temp
            }
        }
    }
}



