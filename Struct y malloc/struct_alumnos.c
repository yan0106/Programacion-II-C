#include <stdio.h>
#include <stdlib.h>

typedef struct Fecha{
    int dia,mes,anio;
}fecha;

typedef struct Alumno{
    char nombre[20];
    int edad;
    char asignatura[15];
    char carrera[20];
    float promedio;
    struct Alumno *amigo;
    fecha nacimiento;
}alumno;


void leerFecha(fecha *n){
    printf("Dia:");
    scanf("%d",&n->dia);
    printf("Mes:");
    scanf("%d",&(*n).mes);
    printf("A�o:");
    scanf("%d",&n->anio);
}

void leerAlumno( alumno *p){
    printf("Ingrese el nombre: ");
    fgets((*p).nombre,20,stdin); 
    printf("Ingrese la edad: ");
    scanf("%d",&p->edad);
    while (getc(stdin) != '\n');
    printf("Ingrese Asignatura: ");
    fgets(p->asignatura,15,stdin); 
    printf("Ingrese Carrera: ");
    fgets((*p).carrera,sizeof p->carrera,stdin); 
    printf("Ingrese Promedio: ");
    scanf("%f",&p->promedio);
    leerFecha(&p->nacimiento);


}
void imprimir( alumno *p){
    printf("Nombre del alumno:%s\n",p->nombre);
    printf("Edad del alumno:%d\n",p->edad);
    printf("Asignatura:%s\n",p->asignatura);
    printf("Carrera:%s\n",p->carrera);
    printf("Promedio: %.2f\n",p->promedio);
    printf("Fecha nacimiento:%d-%d-%d\n",p->nacimiento.dia,p->nacimiento.mes,p->nacimiento.anio);
    printf("Amigo de %s es:%s",p->nombre,p->amigo->nombre);
}



int main(){
    alumno a1;
    alumno *pa1=&a1;
    alumno *a2=malloc(sizeof *a2); 
    alumno a3 = {"Candela", 19, "Analista", "Programacion", 8.5, pa1,{18,4,2006}};
    leerAlumno(&a1); 
    pa1->amigo=&a3;
    imprimir(&a1);
    printf("\n");
    imprimir(&a3);

    free(a2);
    a2=NULL;
return 0;
}
