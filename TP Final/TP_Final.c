#include <stdio.h>
#define MAX 10

// 0 1 2 3 4 5 6 7 8 9 

static int id = 0; // Contador de prioridad

/* Estructura proceso */
typedef struct proceso{
    int procesador;
    int id_proceso;
    int prioridad;
    char estado[MAX];
} proceso;

/* Arreglo estático de 10 posiciones de punteros a estructuras proceso. 
Reserva memoria para 10 punteros. Pone los 10 casilleros en NULL */
proceso * scheduling[MAX] = {NULL};

/* Asigna el siguiente estado según el orden enunciado antes */
void asignaEstado(proceso*);

/* Ingresa el proceso al Scheduler en el primer espacio libre que encuentre*/
void ingresaProceso() {
    static int posicion_actual = 0; // inicio con posición en 0
    int ingresado = 0; // bandera
    for (int i = 0; i < MAX; i++) {
        if (scheduling[posicion_actual] == NULL) {
            //1. si la posición es vacía, reserva memoria para el proceso
            scheduling[posicion_actual] = malloc(sizeof(struct proceso));

            //2. asigna datos...(continuar)

            //3. incrementa la posición
            posicion_actual++;
            //4. chequea que no se pase de MAX
            if (posicion_actual == MAX) {
                posicion_actual = 0; // si posicion_actual llega a MAX, pega la vuelta a 0
            };
            //5. asigna 1 a la bandera
            ingresado = 1;
            //6. frena el bucle
            break;
        } else {
            // si el casillero actual está ocupado, también avanza la posicion_actual para que en la 
            // próxima vuelta del for, revise el que sigue
            posicion_actual++;
            // vuelve a chequear que no se pase de MAX
            if (posicion_actual == MAX) {
                posicion_actual = 0;
            };
        };
    };
    // si salí del for e 'ingresado' sigue en 0, es porque nunca encontró NULL (todo lleno)
    if (ingresado == 0) {
        printf ("No es posible ingresar el proceso. Scheduling lleno.\n");
    };
}

/*Quita el proceso de la cola liberando y retornando el lugar liberado*/
int terminaProceso();
/*Recorrera todos los procesos de la cola, haciendo el cambio del estado de los mismos*/
void recorreCola();
/*Lista los procesos de la cola*/
void mostrarScheduler();
/*Lista los procesos registrados en el archivo*/
void listarFile();