#include <stdlib.h>
#include <stdio.h>

void printAllWords(FILE *);

int main(void)
{
    FILE *fp;
    if ((fp = fopen("archivo.txt", "r")) == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    printAllWords(fp);

    fclose(fp);

    return EXIT_SUCCESS;
}

void printAllWords(FILE * fp)
{
    char tmp[20];
    int i = 1;
    while (fscanf(fp, "%19s", tmp) != EOF) {
        printf("Word %d: %s\n", i, tmp);
        i++;
    }
}