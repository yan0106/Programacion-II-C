#include <stdio.h>

int main () {

int i = 5, j [] = {1,2,3,4,5,6,7,8,9,10};
char x = 'a', pal [] = "texto en c";
int *pi;
char *pc;

printf("Por Variable: 'i'  Valor: %d  Direccion: %p\n", i, &i);   //muestra el valor de i y la dirección
pi = &i;
printf("Por Puntero: 'pi'  Valor: %d  Direccion: %p\n", *pi, pi); //muestra los mismos valores a través del puntero pi

for (int i=0; i<10; i++){ //recorre el vector 'j'
    printf("Por Variable: 'j[%d]'  Valor: %d  Direccion: %p\n", i, j[i], &j[i]); //muestra cada elemento, su dirección y valor
}

pi = j;
for (int i=0; i<10; i++){ //recorre el vector 'j' con puntero
    printf("Por Puntero: 'pi (=&j)+(%d)'  Valor:%d  Direccion: %p\n", i, *(pi+i), pi+i); // *(pi+i) calcula la direccion, por los parentesis, y dsps muestra el contenido. // pi+i muestra la dirección en memoria
}

printf("Por Variable: 'x'  Valor: %c  Direccion: %p\n", x, &x); //muestra el valor de x y la direccion
pc = &x;
printf("Por Puntero: 'pc'  Valor: %c  Direccion:%p\n", *pc, pc); //muestra los mismos valores a través del puntero pc

for (int i=0; i<11; i++){ //recorre el vector 'pal'
    printf("Por Variable: 'pal[%d]'  Valor: %c  Direccion: %p\n", i, pal[i], &pal[i]); //muestra cada elemento, su valor y direccion
}

pc = pal;
for (int i=0; i<11; i++) { //recorre el vector 'pal' con puntero
    printf("Por Puntero: 'pal(=&pal)+(%d)'  Valor: %c  Direccion:%p\n", i, *(pc+i), pc+i);
}

printf("Direccion de '*pi': %p  De '*pc': %p\n", &pi, &pc); // muestra las direcciones donde se almacenan ambos punteros

return 0;
}
