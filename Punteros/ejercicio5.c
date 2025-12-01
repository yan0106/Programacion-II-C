#include <stdio.h>

int main () {

int i = 8, *pi=&i; // *pi (puntero a un entero) = &i (le asigno la dirección de memoria de i)
long long l = 8, *pl=&l;
float f = 102.8f, *pf=&f; // para que sea realmente un float se le agrega la f al final. Sino, por defecto el compilador lo interpreta como un double.
double d = 678.44, *pd=&d;
int vec[100];
vec[0] = 44;

printf ("variable int, tam.bytes:  %d \tdir.&i:  %p \tvalor:  %d\n", sizeof(i), &i, i);
// %p (imprime una dirección de memoria (un puntero) en formato hexadecimal)
// \t (es un tabulador, espacio grande).
// sizeof(i) (devuelve el tamaño en bytes de la variable i)
// &i (imprime la dirección de memoria de i (donde está guardada en RAM)
printf ("puntero int, tam bytes:  %d \tdir.&pi:  %p \tvalor:  %p\n", sizeof(pi), &pi, pi);
printf("variable long, tam.bytes:  %d \tdir.&l:  %p \tvalor:  %ld\n", sizeof(l), &l, l);
printf("puntero long, tam.bytes:  %d \tdir.&l:  %p \tvalor:  %p\n", sizeof(pl), &pl, pl);
printf("variable float, tam.bytes:  %d \tdir.&f:  %p \tvalor:  %.1f\n", sizeof(f), &f, f);
printf("puntero float, tam.bytes:  %d \tdir.&pf:  %p \tvalor:  %p\n", sizeof(pf), &pf, pf);
printf("variable double, tam.bytes:  %d \tdir.&d:  %p \tvalor:  %.21f\n", sizeof(d), &d, d);
printf("puntero double, tam.bytes:  %d \tdir.&pd:  %p \tvalor:  %p\n", sizeof(pd), &pd, pd);
printf("variable array, tam.bytes:  %d \tdir.&vec[0]:  %p \tvalor:  %d\n", sizeof(vec[0]), &vec[0], vec[0]);
printf("puntero array, tam.bytes:  %d \tdir.&vec:  %p \tvalor:  %p\n", sizeof(vec), &vec, vec);

return 0;
}
