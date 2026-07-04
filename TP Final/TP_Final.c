#include <stdio.h>
#define MAX 10

// 0 1 2 3 4 5 6 7 8 9 

// Tenga en cuenta los siguientes prototipos:

static int id = 0;

typedef struct proceso{
    int procesador;
    int id_proceso;
    int prioridad;
    char estado[MAX];
} proceso;

proceso * scheduling[MAX]; // Arreglo estático de 10 posiciones de punteros a estructura proceso

/* Asigna el siguiente estado según el orden enunciado antes */
void asignaEstado(proceso*);
/* Ingresa el proceso al Scheduler en el primer espacio libre que encuentre*/
void ingresaProceso();
/*Quita el proceso de la cola liberando y retornando el lugar liberado*/
int terminaProceso();
/*Recorrera todos los procesos de la cola, haciendo el cambio del estado de los mismos*/
void recorreCola();
/*Lista los procesos de la cola*/
void mostrarScheduler();
/*Lista los procesos registrados en el archivo*/
void listarFile();