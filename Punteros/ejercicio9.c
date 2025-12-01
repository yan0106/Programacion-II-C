#include <stdio.h>
#include <stdlib.h> // para usar malloc()
#include <ctype.h>

typedef enum {MAYUSCULAS, MINUSCULAS} may_min;
int strLargo(const char *origen); // Cantidad de caracteres
int strVacio(const char *origen); // Retorna 1 si tiene al menos un caracter, 0 en otro caso
void strCopia(char *destino, const char *origen); //Copiador
/*prototipo modificado para permitir argumentos de tipo string literales, en casi todos los compiladores un literal string es considerado una constante, osea,
la funcion no podra modificarlos pero, en algunos compiladores tales como GCC es posible modificarlos (según K&R el comportamiento es indefinido)*/
char* reverse (char *string); // Retorna una cadena que es string invertida
void strIzq (char *destino, const char *origen); // Saca blancos Izq.
void strDer (char *destino, const char *origen); // Saca blancos Der.
void strAmbos (char *destino, const char *origen); // Saca blancos Izq. y Der.
void strMayMin (char *destino, const char *origen, may_min m); // Convierte May. Min. // Usa el typedef enum de arriba


int main () {
    char *text1 = " Sera Cierto ?? ";
    int largo = strLargo(text1) + 1; // Sumarle 1 reserva espacio suficiente para copiar la cadena incluyendo el \0, lo cual es fundamental para evitar errores de memoria en C
    char *result = (char *) malloc(largo); // Pido memoria dinámica

    // Es una buena práctica verificar si malloc pudo darme memoria:
    if (result == NULL) {
        printf("Error: No se pudo reservar memoria.\n");
        return -1; // Termina el programa con un código de error
    }

    // --- Pruebas para cada función ---

    // Prueba para strLargo()
    printf("La cadena: ");
    puts(text1);
    printf("Largo: %d\n", strLargo(text1));

    // Prueba para strVacio()
    printf("Se encuentra: %s\n", (strVacio(text1) ? "No vacia" : "Vacia"));

    // Prueba para strCopia()
    strCopia(result, text1);
    printf("Copia: [%s]\n", result);

    // Prueba para reverse()
    char* reves;
    reves = reverse (text1);
    printf ("La cadena: %s Invertida queda: %s\n", text1, reves);

    // Prueba para strIzq()
    strIzq(result, text1);
    printf("Sin blancos a la Izq:");
    puts(result);

    // Prueba para strDer()
    strDer(result, text1);
    printf("Der: [%s]\n", result);

    // Prueba para strAmbos()
    strAmbos(result, text1);
    printf("Ambos: [%s], sin blancos al principio ni al final.\n", result);

    // Prueba para strMayMin()
    strMayMin(result, text1, MAYUSCULAS);
    printf("Mayusculas: [%s]\n", result);
    strMayMin(result, text1, MINUSCULAS);
    printf("Minusculas: [%s]\n", result);

    free(result); // Se libera la memoria que pedí con malloc
    free(reves);

    return 0;
}

// Desarrollo de las funciones:

int strLargo(const char *origen) {
    const char *p = origen; // Puntero auxiliar apunta al inicio
    while (*p != '\0') {    // Mientras el caracter al que apunta no sea el nulo...
        p++;                // ...avanza el puntero a la siguiente dirección
    }
    return p - origen;      // La resta de punteros da la distancia (el largo)
}

int strVacio(const char *origen) {
    if (*origen != '\0') {
        return 1;
    } else { return 0;}
}

void strCopia(char *destino, const char *origen){
    int i = 0;
    // Recorre 'origen' hasta encontrar el final
    while (origen[i] != '\0') {
        // Copia el caracter de origen a destino
        destino [i] = origen [i];
        i ++;
    }
    destino[i] = '\0'; // ¡Fundamental! Cierra la cadena 'destino' con el terminador nulo
}

char* reverse (char *string) {
    // Para saber el largo que debe recorrer el for
    int largo = strLargo(string);
    //Reservo espacio en memoria para el puntero +1 (caracter '\0')
    char *invertida = (char*) malloc(largo + 1);
    int i, j;
    for (i=0, j=largo-1; i < largo; i++, j--) {
    invertida[i] = string [j];
    }
    invertida[i] = '\0';
    // Retorna el puntero
    return invertida;
}

void strIzq (char *destino, const char *origen) {
    // Avanza 'origen' hasta el primer no-espacio
    while (*origen == ' '){
        origen++;
    }
    // Llama a la función copia, con el puntero en el primer caracter no-espacio
    strCopia(destino, origen);
}

void strDer (char *destino, const char *origen){ // Estrategia de copiar primero y luego "recortar" el final retrocediendo
    // Copia el string para trabajarlo
    strCopia(destino, origen);
    // Revisa destino, que ya es la copia
    int largo = strLargo(destino);
    // Inicia el i en el anteúltimo lugar
    int i = largo-1;
    while (i>=0 && destino[i] == ' ') { // Retrocede mientras encuentre espacios y no se pase del inicio
        i--;
    }
    destino[i+1] = '\0'; // En una posición siguiente a encontrar un caracter no-espacio, coloca el final de la cadena
}

void strAmbos (char *destino, const char *origen) {
    // Quita los espacios de la izquierda. El resultado queda guardado en 'destino'
    strIzq(destino, origen);
    // Toma el resultado de 'destino' y le quita los espacios de la derecha
    strDer(destino, destino);
}

void strMayMin (char *destino, const char *origen, may_min m) {
    int i = 0;
    while (origen[i] != '\0') {
        if (m == MAYUSCULAS) {
            // Convierte el caracter de origen y lo GUARDA en destino
            destino[i] = toupper(origen[i]);
        } else if (m == MINUSCULAS) {
            destino[i] = tolower(origen[i]);
        } else {
            // Por si acaso, si 'm' no es ninguna de las dos, solo copia
            destino[i] = origen[i];
        }
        i++;
    }
    destino[i] = '\0';
}


