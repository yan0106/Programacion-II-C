#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 2

typedef struct {
    int mayor;
    int menor;
    int parche;
} Version;

// Ejemplo: 3.1.0

typedef struct {
    char nombre[50];
    Version ver; // estructura anidada
} Software;

void imprimirVersion(Version v); // recibe una copia de la estructura Versión
int compararVersiones(Version *v1, Version *v2); // recibe dos punteros a la estructura Versión
void ordenarVersion(Software inventario[ ], int n);

int main () {

Software *inventario_software = (Software*) malloc(N * sizeof(Software)); // es un arreglo porque tengo N cantidad

// verifico si se reservó memoria
if (inventario_software == NULL) {
        printf("Error: La reserva de memoria falló\n");
        return 1;
    }

// carga de un elementos:
strcpy (inventario_software[0].nombre, "Antivirus");
inventario_software[0].ver.mayor = 3;
inventario_software[0].ver.menor = 1;
inventario_software[0].ver.parche = 0;

strcpy (inventario_software[1].nombre, "IDE");
inventario_software[1].ver.mayor = 4;
inventario_software[1].ver.menor = 2;
inventario_software[1].ver.parche = 5;

// llamada a funciones:



// libero memoria:
// free(p_version1);
// free(p_version2);
free(inventario_software);

return 0;
}

// Ejemplo: v3.1.0
void imprimirVersion(Version v) {
    printf("v%d.%d.%d\n", v.mayor, v.menor, v.parche);
}

//Debe devolver:
// 1 si v1 es anterior a v2.
// -1 si v1 es posterior a v2.
// 0 si son idénticos.
int compararVersiones(Version *v1, Version *v2){
    if (v1->mayor < v2->mayor){
        return 1;
    } else if (v1->mayor > v2->mayor){
        return -1;
    } else if (v1->menor < v2->menor) {
        return 1;
    } else if (v1->menor > v2->menor){
        return -1;
    } else if (v1->parche < v2->parche){
        return 1;
    } else if (v1->parche > v2->parche){
        return -1;
    } else {
        return 0; // si todo es igual
    }
} // En cuanto encuentra una diferencia (return 1 o return -1), sale de la función sin hacer comparaciones innecesarias

void ordenarVersion(Software inventario[ ], int n) {

}
