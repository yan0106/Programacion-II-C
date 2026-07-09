#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    int e = EXIT_SUCCESS;
/* Toma el path por argumento, sino define output.txt */
    char *path = (argc > 1) ? argv[1] : "salida.txt";

/* Abre el archivo en modo escritura */
    FILE *file = fopen(path, "w");

/* Si fopen() falla, imprime error */
    if (!file)
    {
        perror(path);
        return EXIT_FAILURE;
    }

/* Escribe en el archivo. A diferencia de puts(), fputs() no agrega \n. */
    if (fputs("Salida en el archivo.\n", file) == EOF)
    {
        perror(path);
        e = EXIT_FAILURE;
    }

/* Cierre del archivo */
    if (fclose(file))
    {
        perror(path);
        return EXIT_FAILURE;
    }
    return e;
}


/*

void savewlt(FILE *fout, int wins, int losses, int ties)
{
fprintf(fout, "Wins: %d\nTies: %d\nLosses: %d\n", wins, ties, losses);
}
*/