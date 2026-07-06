#include <stdio.h>
#include <stdlib.h> // para usar la función malloc
#include <string.h> // para usar strcpy
#include <time.h> // para usar time
#define MAX_PROCESOS 10 // capacidad máxima de procesos
#define TAM_ESTADO 10 // tamaño máximo del string para el estado

// -- Variable global --
static int id = 0; // para incrementar la prioridad

// -- Estructura proceso -- 
typedef struct proceso{
    int procesador;
    int id_proceso;
    int prioridad;
    char estado[TAM_ESTADO];
} proceso;

// Arreglo estático de 10 posiciones de punteros a estructuras proceso. 
// Reserva memoria para 10 punteros. Pone los 10 casilleros en NULL.
proceso * scheduling[MAX_PROCESOS] = {NULL};

// --- Prototipo de funciones ---

// Asigna el siguiente estado según el orden enunciado
void asignaEstado(proceso*);
// Ingresa el proceso al Scheduler en el primer espacio libre que encuentre
void ingresaProceso();
// Quita el proceso de la cola liberando y retornando el lugar liberado
int terminaProceso();
// Recorrera todos los procesos de la cola, haciendo el cambio de estado de los mismos
void recorreCola();
// Lista los procesos de la cola
void mostrarScheduler();
// Lista los procesos registrados en el archivo
void listarFile();

// -- Main --

int main () {

    srand(time(NULL)); // inicia la semilla aleatoria con la hora actual, para tener siempre nros distintos

    // al principio el arreglo está vacío (todo en NULL)
    
    // prueba ingresaProceso()
    ingresaProceso(); // se guarda en scheduling[0]
    ingresaProceso(); // se guarda en scheduling[1]
    ingresaProceso(); // se guarda en scheduling[2]

    // mostrarScheduler() para verlos en pantalla
    mostrarScheduler();

    // prueba asignaEstado()
    strcpy(scheduling[0]->estado, "Listo");
    asignaEstado(scheduling[0]);
    printf ("Luego de llamar a la f asignaEstado: \n");
    mostrarScheduler();


return 0;  
}

// -- Desarrollo de las funciones --

void ingresaProceso() {
    static int posicion_actual = 0; // inicia con posición en 0
    int ingresado = 0; // bandera
    for (int i = 0; i < MAX_PROCESOS; i++) {
        if (scheduling[posicion_actual] == NULL) {
            //1. Si la posición es vacía, reserva memoria para el proceso
            scheduling[posicion_actual] = malloc(sizeof(struct proceso));
            //2. Asigna datos
            scheduling[posicion_actual]->procesador = 0;
            scheduling[posicion_actual]->id_proceso = rand();
            id++; // (primero incrementa, pasa 1 la primera vez)
            scheduling[posicion_actual]->prioridad = id;
            strcpy(scheduling[posicion_actual]->estado, "Nuevo");            
            //3. Incrementa la posición
            posicion_actual++;
            //4. Chequea que no se pase de MAX
            if (posicion_actual == MAX_PROCESOS) {
                posicion_actual = 0; // si posicion_actual llega a MAX, pega la vuelta a 0
            };
            //5. Asigna 1 a la bandera
            ingresado = 1;
            //6. Frena el bucle
            break;
        } else {
            // si el casillero actual está ocupado, también avanza la posicion_actual para que en la 
            // próxima vuelta del for, revise el que sigue
            posicion_actual++;
            // vuelve a chequear que no se pase de MAX
            if (posicion_actual == MAX_PROCESOS) {
                posicion_actual = 0;
            };
        };
    };
    // Si sale del for e 'ingresado' sigue en 0, es porque nunca encontró NULL (todo lleno)
    if (ingresado == 0) {
        printf ("No es posible ingresar el proceso. Scheduler lleno.\n");
    };
}

void mostrarScheduler() {
    printf ("-- Los procesos registrados son: -- \n");
    for (int i = 0; i < MAX_PROCESOS; i++) {
        if (scheduling[i] != NULL) { // verifica que la posición no esté vacía
            printf("[%d] -> {%d;%d;%d;\"%s\"}\n", 
                    i,
                    scheduling[i]->procesador, 
                    scheduling[i]->id_proceso, 
                    scheduling[i]->prioridad, 
                    scheduling[i]->estado);
        } else { // si está vacía
            printf("[%d] -> [Vacio]\n", i);
        }
    }
};

void asignaEstado (proceso * p) {
    /*if (strcmp(p->estado, "Nuevo") == 0) {
        strcpy (p->estado, "Listo");
    } VER */ 
    if (strcmp(p->estado, "Listo") == 0) {
        strcpy (p->estado, "Esperando");
    } else if (strcmp(p->estado, "Esperando") == 0) {
        strcpy (p->estado, "Listo"); // vuelve a la fila
    } else if (strcmp(p->estado, "Corriendo") == 0) {
        strcpy (p->estado, "Terminado");
    }
}