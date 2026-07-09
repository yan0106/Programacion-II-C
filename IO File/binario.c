#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int result = EXIT_SUCCESS;
    char file_name[] = "output.bin";
    char str[] = "This is a binary file example";
    FILE * fp = fopen(file_name, "wb");

    if (fp == NULL) 
    {
        result = EXIT_FAILURE;
        fprintf(stderr, "fopen() failed for '%s'\n", file_name);
    }else{
        size_t element_size = sizeof *str;
        size_t elements_to_write = sizeof str;
    /* escribe str (_including_ the NUL-terminator) en el archivo binario. */
        size_t elements_written = fwrite(str, element_size, elements_to_write, fp);
        if (elements_written != elements_to_write)
        {
            result = EXIT_FAILURE;
        /* funciona para >=c99, sino el modificador z da error. */
            fprintf(stderr, "fwrite() failed: wrote only %zu out of %zu elements.\n",
            elements_written, elements_to_write);
        /* sino se usa  <c99: *
            fprintf(stderr, "fwrite() failed: wrote only %lu out of %lu elements.\n",
            (unsigned long) elements_written, (unsigned long) elements_to_write);
        */
        }
        fclose(fp);
    }
    return result;
}