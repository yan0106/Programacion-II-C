#include <stdlib.h>
#include <stdio.h>
#define FILENAME "ejemplo.txt"

int main(void)
{

/* Abre el archivo para lectura */
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int line_count = 0;
    ssize_t line_size;
    FILE *fp = fopen(FILENAME, "r");

    if (!fp)
    {
        fprintf(stderr, "Error al abrir archivo '%s'\n", FILENAME);
        return EXIT_FAILURE;
    }

/* Toma la primera linea. */
    line_size = getline(&line_buf, &line_buf_size, fp);

/* Lee hasta el final del archivo. */
    while (line_size >= 0)
    {
/* Incrementa nunmero de linea */
        line_count++;
/* Muestra el detalle */
        printf("line[%06d]: chars=%06zd, buf size=%06zu, contents: %s", line_count,
        line_size, line_buf_size, line_buf);
/* Lee la siguiente linea */
        line_size = getline(&line_buf, &line_buf_size, fp);
    }

/* Libera el buffer */
    free(line_buf);
    line_buf = NULL;

/* Cierra el archivo */
    fclose(fp);
    
    return EXIT_SUCCESS;
}