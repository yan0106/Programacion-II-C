#include <stdio.h>
#include <stdlib.h> // para usar malloc

typedef struct {
    int n; // representa el grado n, es decir, el exponente más alto al que está elevada x
    double *coeficiente; // (n+1) , nros. que multiplican a la x. '+1', es por el término independiente x^0 = 1 // cantidad de términos que tiene el polinomio
    } Polinomio;

Polinomio* creaPolinomio (int orden); // crea y retorna un nuevo polinomio
void setCoef(int n, double c, Polinomio * P); // asigna el valor de c en el n_ésimo (n) coeficiente del Polinomio
double getCoef (int n, Polinomio * P); // retorna el n_ésimo coeficiente del Polinomio
double especializa (double x, Polinomio * P); // evalúa el polinomio en x
Polinomio* sum (Polinomio *p1, Polinomio *p2); // suma dos Polinomios y retorna un nuevo Polinomio con el resultado
Polinomio* mult (Polinomio *p1, Polinomio *p2); // multiplica dos Polinomios y retorna un nuevo Polinomio con el resultado
Polinomio* deriv (Polinomio *p); // deriva un nuevo Polinomio retornando un nuevo Polinomio con el resultado
void destruyePolinomio (Polinomio *p); // libera memoria asociada con el polinomio
double ceropol (Polinomio *p, double a, double b, double epsilon);

int main () {

    Polinomio *p_original = creaPolinomio(2); // creo el polinomio de grado 2

    setCoef(0, -7, p_original); // cargo C0 = -7
    setCoef(1, 5, p_original); // cargo C1 = 5
    setCoef(2, 3, p_original); // cargo C2 = 3

    double resultado = especializa(2, p_original); // evalúo el Polinomio en el valor de x = 2;
    printf("El resultado de P(2) es: %f\n", resultado);


return 0;
}

Polinomio* creaPolinomio (int orden) {
    Polinomio *p = (Polinomio*) malloc (sizeof(Polinomio)); // reserva memoria para la estructura en sí
    // verifica el primer malloc:
    if (p == NULL) {
        return NULL;
    }
    p->n = orden;
    p->coeficiente = (double*) malloc (orden+1 * sizeof(double)); // reserva memoria para el arreglo de doubles con el tamaño orden+1
    // verifica el segundo malloc:
    if (p->coeficiente == NULL){
        // si este falla, libero la memoria del primero, antes de salir, para no dejar basura
        free(p);
        return NULL;
    }
    return p;
}

void setCoef(int n, double c, Polinomio * P) {
    P->coeficiente[n] = c;
}

double getCoef (int n, Polinomio * P) {
    double c = P->coeficiente[n];
    return c;
}

// Evalúa el polinomio en x
double especializa (double x, Polinomio * P) {
    double total = 0;
    for (int i = P->n; i >= 0; i--){  // va del coeficiente n al coeficiente 0 (término independiente), incluyéndolo
            // aplica la fórmula de Horner: total = (total * x) + coeficiente_actual
            // esto calcula P(x) = (...(Cn*x + Cn-1)*x + ... + C1)*x + C0
            total = (total * x) + P->coeficiente[i];
    }
    return total;
}

Polinomio* sum (Polinomio *p1, Polinomio *p2) {
    int n_resultado = 0; // necesito conocer el orden del nuevo polinomio suma, para crearlo
    if (p1->n > p2->n) {
        n_resultado = p1->n;
    } else {
        n_resultado = p2->n;
    }

    Polinomio *p_suma = creaPolinomio(n_resultado);

    for (int i = 0; i <= n_resultado; i++) {


    return p_suma;
}
