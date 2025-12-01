#include <stdio.h>
#include <stdlib.h> // para usar malloc()
#define CANT_PACIENTES 2

// orden (includes -> structs -> prototipos -> main -> implementaciones)

typedef struct domicilio {
    char calle [20];
    int numero;
    char barrio [20];
    char ciudad [20];
    char codigo_postal [20];
    char telefono[20];
} Domicilio;

typedef struct paciente {
    char nombre [20];
    char apellido [20];
    char sexo;
    int condicion; // condición es un entero  entre 1 y 5, 1 mínimo de gravedad, 5 máximo de gravedad
    struct domicilio dom; // esta línea RESERVA el espacio para un domicilio. Cuando se crea una varible de tipo Pacientes, se reserva automáticamente memoria para el domicilio.
} Paciente;

void cargarDom(Domicilio *p_domicilio); // recibe un puntero a la estructura para poder modificarla
void cargarPaciente (Paciente *p_paciente);
void imprimirPaciente (Paciente *p_paciente, int n);

int main () {

    Paciente *p_paciente = (Paciente*) malloc(CANT_PACIENTES * sizeof(Paciente));

    // se verifica si pudo reservar memoria
    if (p_paciente == NULL) {
    printf("Error: La reserva de memoria falló\n");
    return 1;
    }

    // para cargar varios pacientes
    printf("--- Carga de %d Pacientes ---", CANT_PACIENTES);
    for (int i = 0; i < CANT_PACIENTES; i++ ){
            printf("\n\n*** Ingresando datos del Paciente %d ***\n", i + 1);
            // llamo a cargarDom para el domicilio del paciente 'i'
            cargarDom(&p_paciente[i].dom); // es lo mismo que hacer: &(*(p_paciente + i))
            // llamo a cargarPaciente para los datos del paciente 'i'
            cargarPaciente (&p_paciente[i]);
    }

    imprimirPaciente(p_paciente, 2);


    // LIBERO la memoria
    free(p_paciente);

return 0;
}

void cargarDom(Domicilio *p_domicilio) {
    printf ("\nPor favor, ingrese el domicilio del paciente: \n");
    printf ("Calle: ");
    fgets (p_domicilio->calle, 20, stdin);
    printf ("Numero: ");
    scanf ("%d", &p_domicilio->numero);
    getc (stdin);
    printf ("Barrio: ");
    fgets (p_domicilio->barrio, 20, stdin);
    printf ("Ciudad: ");
    fgets (p_domicilio->ciudad, 20, stdin);
    printf ("Codigo Postal: ");
    fgets (p_domicilio->codigo_postal, 20, stdin);
    printf ("Por favor, ingrese el telefono del paciente: ");
    fgets (p_domicilio->telefono, 20, stdin);
}

void cargarPaciente (Paciente *p_paciente) {
    printf ("\nPor favor, ingrese los datos del paciente: \n");
    printf ("Nombre: ");
    fgets (p_paciente->nombre, 20, stdin);
    printf ("Apellido: ");
    fgets (p_paciente->apellido, 20, stdin);
    printf ("Sexo (M/F): ");
    scanf (" %c", &p_paciente->sexo); // el espacio " %c" es para ignorar los '\n'
    printf ("Condicion (1-5): ");
    scanf ("%d", &p_paciente->condicion);
    getc(stdin); // se limpia el buffer para futuros fgets
}

void imprimirPaciente (Paciente *p_paciente, int n) {
    printf("\n::: Pacientes cargados :::\n");

    for (int i = 0; i < n; i++) {
        printf ("\n--- Datos del Paciente %d ---\n", i+1);
        printf ("\nNombre: %s", p_paciente[i].nombre);
        printf ("Apellido: %s", p_paciente[i].apellido);
        printf ("Sexo: %c", p_paciente[i].sexo);
        printf ("Condicion: %d\n", p_paciente[i].condicion);

        printf ("--- Domicilio ---\n");
        printf ("Calle: %s", p_paciente[i].dom.calle);
        printf ("Numero: %d\n", p_paciente[i].dom.numero);
        printf ("Barrio: %s", p_paciente[i].dom.barrio);
        printf ("Ciudad: %s", p_paciente[i].dom.ciudad);
        printf ("Codigo Postal: %s", p_paciente[i].dom.codigo_postal);
        printf ("Telefono: %s", p_paciente[i].dom.telefono);
    }
}


