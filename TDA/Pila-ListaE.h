typedef struct nodo{
    int dato;
    struct nodo* sgte;    
}pila;

void apila (pila**, int);
void desapila (pila**);
void vaciaPila (pila**);
void tamanio (pila*);
int estaVacia (pila**);
int cima (pila*);