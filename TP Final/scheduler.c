#include <stdio.h>
#include <stdlib.h> // para usar la función malloc
#include <string.h> // para usar strcpy
#include <time.h> // para usar time
#define MAX_PROCESOS 10 // capacidad máxima de procesos
#define TAM_ESTADO 10 // tamaño máximo del string para el estado
#define TAM_BUFFER 100 // tamaño del arreglo para guardar los datos

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

// --- Funciones auxiliares ---

int estadoProcesador(int nro_procesador);
int buscarPrioridadEsperando();
void mostrarMenu();

// -- Main --

int main() {

    srand(time(NULL)); // inicia la semilla aleatoria con la hora actual, para tener siempre nros distintos

    mostrarMenu();
   
return 0;  
}

// -- Desarrollo de las funciones --

void ingresaProceso() {
    
    static int posicion_actual = 0; // inicia con posición en 0
    int ingresado = 0; // bandera
    
    for (int i = 0; i < MAX_PROCESOS; i++) {
        if (scheduling[posicion_actual] == NULL) { // Si la posición es vacía

            // 1. Reserva memoria para el proceso
            scheduling[posicion_actual] = malloc(sizeof(struct proceso));
            if (scheduling[posicion_actual] == NULL) {
                printf("No se pudo reservar memoria");
                return;
            }

            // 2. Asigna datos
            scheduling[posicion_actual]->procesador = 0;
            scheduling[posicion_actual]->id_proceso = rand();
            id++; // (primero incrementa, pasa 1 la primera vez)
            scheduling[posicion_actual]->prioridad = id;
            strcpy(scheduling[posicion_actual]->estado, "Nuevo");            
            
            // 3. Incrementa la posición
            posicion_actual++;
            
            // 4. Chequea que no se pase de MAX
            if (posicion_actual == MAX_PROCESOS) {
                posicion_actual = 0; // si posicion_actual llega a MAX, pega la vuelta a 0
            }
            
            // 5. Asigna 1 a la bandera
            ingresado = 1;
            
            // 6. Frena el bucle
            break;

        } else {
            // si el casillero actual está ocupado, también avanza la posicion_actual para que en la 
            // próxima vuelta del for, revise el que sigue
            posicion_actual++;
            // vuelve a chequear que no se pase de MAX
            if (posicion_actual == MAX_PROCESOS) {
                posicion_actual = 0;
            }
        }
    }
    // Si sale del for e 'ingresado' sigue en 0, es porque nunca encontró NULL (todo lleno)
    if (ingresado == 0) {
        printf("No es posible ingresar el proceso. Scheduler lleno.\n");
    }
}

void mostrarScheduler() {
    
    printf ("\n-- Los procesos registrados son: -- \n\n");
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
}

void asignaEstado (proceso * p) { // se encarga de los procesos que no dependen de los procesadores
    
    // Listo -> Esperando
    if (strcmp(p->estado, "Listo") == 0) {
        strcpy (p->estado, "Esperando");
    } 
    // Corriendo -> Terminado 
    else if (strcmp(p->estado, "Corriendo") == 0) {
        strcpy (p->estado, "Terminado");
    }
}

void recorreCola () {

    // Consulta el estado de los procesadores
    int proc1_libre = estadoProcesador(1); 
    int proc2_libre = estadoProcesador(2);

    // 1. Corriendo -> Terminado
    for (int i = 0; i < MAX_PROCESOS; i++) {
        if (scheduling[i] != NULL && strcmp(scheduling[i]->estado, "Corriendo") == 0) {
            asignaEstado(scheduling[i]);
        }
    }

    // 2. Esperando -> Corriendo
    while (proc1_libre == 1 || proc2_libre == 1) {
        int indice = buscarPrioridadEsperando();
        
        if (indice == -1) {
            break; // no hay procesos "Esperando"
        }

        if (proc1_libre == 1) { 
            strcpy(scheduling[indice]->estado, "Corriendo");
            scheduling[indice]->procesador = 1;
            proc1_libre = 0; 
        } else if (proc2_libre == 1) {
            strcpy(scheduling[indice]->estado, "Corriendo");
            scheduling[indice]->procesador = 2;
            proc2_libre = 0; 
        }
    }

    // 3. Listo -> Esperando
    for (int i = 0; i < MAX_PROCESOS; i++) {
        if (scheduling[i] != NULL && strcmp(scheduling[i]->estado, "Listo") == 0) {
            asignaEstado(scheduling[i]); 
        }
    }

    // 4. Nuevo -> Corriendo || Nuevo -> Listo
    for (int i = 0; i < MAX_PROCESOS; i++) {
        if (scheduling[i] != NULL && strcmp(scheduling[i]->estado, "Nuevo") == 0) {
            if (proc1_libre == 1) { // si el procesador1 está libre
                strcpy(scheduling[i]->estado, "Corriendo");
                scheduling[i]->procesador = 1;
                proc1_libre = 0; // actualiza el procesador1 a ocupado
            } else if (proc2_libre == 1) { // si el procesador2 está libre
                strcpy(scheduling[i]->estado, "Corriendo");
                scheduling[i]->procesador = 2;
                proc2_libre = 0; // actualiza el procesador2 a ocupado
            } else {
                // si no hay procesadores libres, va a hacer la fila
                strcpy(scheduling[i]->estado, "Listo");
                scheduling[i]->procesador = 0;
            }
        }
    }
}

// -- Funciones Auxiliares --

// Busca si un procesador en particular (1 o 2) está libre. Devuelve 1 si está libre, o 0 si está ocupado.
int estadoProcesador(int nro_procesador) {
    
    for (int i = 0; i < MAX_PROCESOS; i++) {
        if (scheduling[i] != NULL && strcmp(scheduling[i]->estado, "Corriendo") == 0) {
            if (scheduling[i]->procesador == nro_procesador) {
                return 0; // lo encontró ocupado, devuelve 0 y corta la función
            }
        }
    }

return 1; // terminó de buscar y nadie lo está usando, devuelve 1 (libre)
}

// Busca el proceso "Esperando" con mayor prioridad (número más bajo). Devuelve su índice, o -1 si no hay ninguno.
int buscarPrioridadEsperando() {
    
    int minimo_prioridad = 9999;
    int indice = -1;

    for (int i = 0; i < MAX_PROCESOS; i++) {
        if (scheduling[i] != NULL && strcmp(scheduling[i]->estado, "Esperando") == 0) {
            if (scheduling[i]->prioridad < minimo_prioridad) {
                minimo_prioridad = scheduling[i]->prioridad;
                indice = i;
            }
        }
    }

return indice;
}

int terminaProceso() {
    
    int posicion_liberada = -1;

    FILE *fp = fopen("archivo_terminados.txt", "a"); // para abrir archivo y agregar datos al final
    
    if (fp == NULL) {
        printf("Error al abrir el archivo");
        return -1;
    } 

    for (int i = 0; i < MAX_PROCESOS; i++) {
        if (scheduling[i] != NULL && strcmp(scheduling[i]->estado, "Terminado") == 0) {
            fprintf(fp, "Procesador: %d | ID Proceso: %d | Prioridad: %d | Estado: %s\n",
                    scheduling[i]->procesador,
                    scheduling[i]->id_proceso,
                    scheduling[i]->prioridad,
                    scheduling[i]->estado);
            free(scheduling[i]); // libera espacio de memoria
            scheduling[i] = NULL; // pone el puntero en null
            posicion_liberada = i;
            break; // solo quita 1 por llamada
        }
    }

fclose(fp); // cierra el archivo
return posicion_liberada;    
}

void listarFile() {

    char buffer[TAM_BUFFER];

    FILE *fp = fopen("archivo_terminados.txt", "r");

    printf("\n--- Contenido del archivo ---\n\n");

    if (fp == NULL) {
        printf("No hay procesos terminados guardados todavia.\n");
        return;
    }    

    while (fgets(buffer, TAM_BUFFER, fp) != NULL) { // mientras que lo que devuelva la f sea distinto de NULL
        printf("%s", buffer); // imprime lo que lee
    }
    
    fclose(fp);
}

void mostrarMenu() {
    
    int opcion = -1; // para que ingrese al while
    
    while (opcion != 0) {
        
        printf("\n--- SISTEMA SCHEDULER ---\n");
        printf("\n1. Ingresar proceso\n");
        printf("2. Recorrer cola\n");
        printf("3. Terminar procesos\n");
        printf("4. Mostrar Scheduler\n");
        printf("5. Listar archivo\n");
        printf("0. Salir\n");
        
        printf("\nSeleccione una opcion: ");

        // si scanf no devuelve 1, no pudo leer un número entero
        if (scanf("%d", &opcion) != 1) {
            int c;
            // este bucle barre los caracteres del buffer hasta limpiar el Enter
            while ((c = fgetc(stdin)) != '\n' && c != EOF);
            opcion = -1; // le asigna un valor inválido para que el switch caiga en el "default"
        }

        switch(opcion) {
            case 1:
                ingresaProceso();
                break;
            case 2:
                recorreCola();
                break;
            case 3: {
                int terminado = terminaProceso();                
                
                if (terminado == -1) {
                    printf("\nNo hay procesos terminados para quitar.\n");
                } else {
                    printf("\nProceso terminado con exito en la posicion [%d]!\n", terminado);
                }
                break;
            }
            case 4:
                mostrarScheduler();
                break;
            case 5:
                listarFile();
                break;
            case 0: {
                // libera toda la memoria antes de terminar el programa y pone los punteros en NULL
                for (int i = 0; i < MAX_PROCESOS; i++){
                    if (scheduling[i] != NULL) {
                        free(scheduling[i]);
                        scheduling[i] = NULL;
                    }
                }
                printf("\nSaliendo del sistema...\n");
                break;
            }
            default:
                printf("\nOpcion invalida.\n");
        }
    }
    
    listarFile();
}