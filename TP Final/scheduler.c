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

    // llamada a recorreCola
    recorreCola();
    printf ("Luego de recorrer la cola: \n");
    mostrarScheduler();

    // simula terminarProceso()
    scheduling[0] = NULL;
    scheduling[1] = NULL;

    recorreCola();
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

// Listo -> Esperando ; Esperando -> Listo ; Corriendo -> Terminado
void asignaEstado (proceso * p) { // se encarga de los procesos que no dependen de los procesadores
    if (strcmp(p->estado, "Listo") == 0) {
        strcpy (p->estado, "Esperando");
    } else if (strcmp(p->estado, "Esperando") == 0) {
        strcpy (p->estado, "Listo"); // no consiguió procesador, vuelve a la fila
    } else if (strcmp(p->estado, "Corriendo") == 0) {
        strcpy (p->estado, "Terminado");
    }
}

// Nuevo -> Corriendo ; Esperando -> Corriendo
void recorreCola () { // realiza el trabajo "inteligente" de asignar los procesadores
    int procesador1 = 0; // 0 = libre ; 1 = ocupado
    int procesador2 = 0;

    int minimo_prioridad = 9999; // para guardar la prioridad de los procesos "Esperando"
    int indice = -1; // para saber el casillero

    // 1. Chequeo quién ya está corriendo + valor minimo de prioridad de los "Esperando":
    for (int i = 0; i < MAX_PROCESOS; i++){
        if (scheduling[i] != NULL) {
            if (strcmp(scheduling[i]->estado, "Corriendo") == 0){
                if (scheduling[i]->procesador == 1) { // si el proceso está corriendo, tiene asignado el procesador1
                    procesador1 = 1; // el procesador 1 está ocupado
                } else if (scheduling[i]->procesador == 2) { // si el proceso está corr, si tiene asignado el procesador2
                    procesador2 = 1; // el procesador 2 está ocupado
                }
            }
            if (strcmp(scheduling[i]->estado, "Esperando") == 0){
                if (scheduling[i]->prioridad < minimo_prioridad){
                    minimo_prioridad = scheduling[i]->prioridad;
                    indice = i; // cuando termina el bucle, se queda con la posición del proc. de mayor prioridad
                }
            }
        }
    }

    // 2. Lógica para procesos "Esperando"
    // si indice es distinto de -1, significa que encontró un proc. "Esperando"
    if (indice != -1) {
        if (procesador1 == 0){ // si el procesador 1 está libre
            strcpy(scheduling[indice]->estado, "Corriendo"); // cambia el estado
            scheduling[indice]->procesador = 1; // le asigna 1 al procesador
            procesador1 = 1; // cambia a procesador ocupado
        }
        else if (procesador2 == 0){
            strcpy(scheduling[indice]->estado, "Corriendo");
            scheduling[indice]->procesador = 2;
            procesador2 = 1;
        }        
    }
    
    // 3. Recorrido para "Nuevo" (procesador1 = libre; procesador2 = libre; o todo lleno)
    for (int i = 0; i < MAX_PROCESOS; i++) {
        if (scheduling[i] != NULL) {
            if (strcmp(scheduling[i]->estado, "Nuevo") == 0 && scheduling[i]->procesador == 0) {
                if (procesador1 == 0) { // si el procesador1 está libre
                    strcpy(scheduling[i]->estado, "Corriendo"); // el proceso pasa de "Nuevo" a "Corriendo"
                    scheduling[i]->procesador = 1; // el procesador cambia a 1
                    procesador1 = 1; // el procesador1 está ocupado
                }
                else if (procesador2 == 0) {
                    strcpy(scheduling[i]->estado, "Corriendo");
                    scheduling[i]->procesador = 2; // el procesador cambia a 2
                    procesador2 = 1; // el procesador está ocupado
                }
                else {
                    // si ninguno de los procesadores está libre, el proceso "Nuevo" pasa al estado "Listo"
                    strcpy(scheduling[i]->estado, "Listo");
                    // este proceso no está usando ningun procesador. Está afuera, esperando su turno en la fila
                    scheduling[i]->procesador = 0; 
                }
            // Si el proceso está en "Esperando", no entra en asignaEstado()
            // De esta forma los proc. "Esperando" no pierden su prioridad, la vuelta que sigue
            } else if (strcmp(scheduling[i]->estado, "Esperando") != 0) {
                asignaEstado(scheduling[i]); // solo entran los "Listo" y los "Corriendo" viejos
            }
        }
    }
}