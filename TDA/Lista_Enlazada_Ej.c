#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int dato ;
    struct nodo * sgte ;
} lista ;

void listar ( lista * i ) {
    if ( i != NULL ) {
        printf ( " elemento := %d \n " , i->dato ) ;
        listar (i->sgte ) ;
    }
};

void insertar(int d, lista **i) {
    if (*i == NULL) {
        printf("Insertando %d en la lista\n", d);
        *i = (lista *) malloc(sizeof(lista));
        (*i)->dato = d;
        (*i)->sgte = NULL; // Es buena práctica asegurar que el nuevo nodo apunte a NULL
    } else {
        if ((*i)->dato > d) { // Cuando va al inicio
            printf("Insertando %d en la lista\n", d);
            lista *nuevo = (lista *) malloc(sizeof(lista));
            nuevo->dato = d;
            nuevo->sgte = *i;
            *i = nuevo;
        } else if ((*i)->dato < d && (*i)->sgte != NULL && (*i)->sgte->dato > d) { // Cuando está entre dos
            printf("Insertando %d en la lista\n", d);
            lista *nuevo = (lista *) malloc(sizeof(lista));
            nuevo->dato = d;
            nuevo->sgte = (*i)->sgte;
            (*i)->sgte = nuevo;
        } else if ((*i)->dato == d) {
            printf("Ya existe el elemento %d en la lista\n", d);
        } else {
            insertar(d, &(*i)->sgte);
        }
    }
}

void eliminar(int d, lista **i) {
    if (*i == NULL) {
        printf("No existe el elemento a eliminar\n");
    } else {
        if ((*i)->dato == d) { // Elimino al primero
            printf("Elimino a %d\n", d);
            lista *aux = (*i);
            (*i) = (*i)->sgte;
            free(aux);
        } else if ((*i)->dato < d && (*i)->sgte != NULL && (*i)->sgte->dato == d) { // Elimino al siguiente
            printf("Elimino a %d\n", d);
            lista *aux = (*i)->sgte;
            (*i)->sgte = (*i)->sgte->sgte;
            free(aux);
        } else {
            eliminar(d, &(*i)->sgte); // llama a eliminar de forma recursiva, pasándole el sig nodo
        }
    }
}

int main() {
    lista *inicio;
    inicio = NULL;

    insertar(5, &inicio);
    insertar(3, &inicio);
    insertar(4, &inicio);
    insertar(10, &inicio);
    insertar(6, &inicio);
    insertar(8, &inicio);
    insertar(1, &inicio);
    insertar(8, &inicio); // Este va a avisar que ya existe
    insertar(1, &inicio); // Este también va a avisar que ya existe

    printf("Listo elementos\n");
    listar(inicio);
    printf("Fin del listado\n");

    eliminar(4, &inicio);  // Elimina uno del medio
    eliminar(1, &inicio);  // Elimina al primero de todos
    eliminar(10, &inicio); // Elimina al último de todos
    eliminar(14, &inicio); // Este va a decir que no existe

    printf("Listo elementos\n");
    listar(inicio);
    printf("Fin del listado\n");

    return 0;
}


