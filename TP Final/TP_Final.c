#include <stdio.h>

// Tenga en cuenta los siguientes prototipos:

static int id = 0;

typedef struct proceso{
    int procesador;
    int id_proceso;
    int prioridad;
    char estado[10];
} proceso;

proceso* scheduling[10];