/*
EJERCICIO DE PRÁCTICA:
TEMA: Playlist Musical con Cadenas Dinámicas

OBJETIVOS:
1. Manejar un arreglo dinámico de estructuras (malloc del bloque).
2. Manejar memoria dinámica DENTRO de la estructura (malloc para strings).
3. Liberar memoria en el orden correcto (de adentro hacia afuera).

CONSIGNA:
Implementar un programa que cargue N canciones.
- El arreglo de canciones debe ser dinámico.
- Los textos (título y artista) deben usar la memoria JUSTA y NECESARIA.
  No se permite desperdiciar bytes (ej: no usar char[100] si el nombre es "Hola").
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *titulo;
    char *artista;
    int duracion;   // en segundos
} Cancion;

void cargarCancion(Cancion *c);
void mostrarPlaylist(Cancion *lista, int n);
void liberarPlaylist(Cancion *lista, int n);
Cancion* buscarPorTitulo(Cancion *lista, int n, char *titulo_buscado);
void cambiarTitulo(Cancion *c, char *nuevo_titulo);
void ordenarPorDuracion(Cancion *lista, int n);

int main() {

    int n;
    printf("Cuantas canciones queres cargar?: ");
    scanf("%d", &n);
    getc(stdin);

    Cancion *playlist = (Cancion*) malloc(n * sizeof(Cancion));

    // Inicializo los putneros de la estructura para que no contengan basura
    for (int i = 0; i < n; i++){
        playlist[i].artista = NULL;
        playlist[i].titulo = NULL;
    }

    // Verifico si se reservó memoria
    if (playlist == NULL) {
        printf("Error de memoria.\n");
        return 1;
    }

    // Cargar datos
    for (int i = 0; i < n; i++) {
        printf("\n--- Cancion %d ---\n", i+1);
        cargarCancion(&playlist[i]); // le pasa la dirección de la canción 'i'
    }

    // Muestra la playlist
    mostrarPlaylist(playlist, n);

    // Libera la memoria
    liberarPlaylist(playlist, n);

    return 0;
}

// Funciones

void cargarCancion(Cancion *c) {
    char buffer[100]; // un lugar temporal para escribir
    int largo;
    // Título
    printf("Ingrese Titulo: ");
    fgets(buffer, 100, stdin);
    // truco para borrar el \n
    if (buffer[strlen(buffer)-1] == '\n') buffer[strlen(buffer)-1] = '\0';

    largo = strlen (buffer); // calcula el largo del texto
    c->titulo = (char*) malloc ((largo+1) * sizeof(char)); // hace malloc para el título con el tamaño exacto y agrega +1 para el \0
    strcpy (c->titulo, buffer); // usar strcpy para cargar el título en el nuevo espacio

    // Artista
    printf("Ingrese Artista: ");
    fgets(buffer, 100, stdin);
    // borra el \n
    if (buffer[strlen(buffer)-1] == '\n') buffer[strlen(buffer)-1] = '\0';
    largo = strlen (buffer);
    c->artista = (char*) malloc ((largo+1) * sizeof(char));
    strcpy (c->artista, buffer);

    // Duracion
    printf("Duracion (seg): ");
    scanf("%d", &c->duracion);
    getc(stdin);
}

void mostrarPlaylist(Cancion *lista, int n) {
    printf("\n--- TU PLAYLIST ---\n");
    for(int i=0; i<n; i++) {
        printf("%d. %s - %s (%ds)\n", i+1, lista[i].titulo, lista[i].artista, lista[i].duracion);
    }
}

void liberarPlaylist(Cancion *lista, int n) {
    for (int i = 0; i < n; i++) {
        free (lista[i].titulo);
        free (lista[i].artista);
        lista[i].titulo = NULL;
        lista[i].artista = NULL;
    }
    free (lista);
}

Cancion* buscarPorTitulo(Cancion *lista, int n, char *titulo_buscado) {
    for (int i = 0; i < n; i++) {
        if (lista[i].titulo != NULL) {
            if (strcmp (titulo_buscado, lista[i].titulo) == 0) {
                if (strcmp (titulo_buscado, lista[i].titulo) == 0) {
                    return &lista[i]; // retorna la dirección de lista[i]
                }
            }
        }
    return NULL;
    }
}

void cambiarTitulo(Cancion *c, char *nuevo_titulo) { // Demolicion y Reconstruccion
    free (c->titulo);
    c->titulo = NULL;
    int largo = strlen (nuevo_titulo);
    c->titulo = (char*) malloc ((largo+1) * sizeof(char));
    strcpy (c->titulo, nuevo_titulo);
}

void ordenarPorDuracion(Cancion *lista, int n) {
    Cancion temp;
    for (int i = 0; i < n - 1; i ++) { // me indica la cantidad de veces que se va a repetir la comparacion. n - 1 es suficiente
        for (int j = 0; j < n - 1; j++) { // hace la comparación hasta n-1, porque si me paso, leeo memoria prohibida
            if (lista[j].duracion > lista[j+1].duracion) {
                // Al copiar la estructura entera, los punteros internos (título/artista) viajan con ella. No se rompen ni se pierden.
                temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }
        }
    }
}
