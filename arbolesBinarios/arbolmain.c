#include <stdio.h>
#include "operaciones.c"
#include "operaciones.h"

int main()
{
    int valor;
    struct nodo arbol;

    inicializar(&arbol);

    while(valor != -1){
        printf("introduce un numero\n");
        scanf("%d", &valor);
        if(valor != -1)
            insertar(&arbol,valor);
    }
    printf("lado izquierdo de");
    preorden_izq(&arbol);
    printf("lado derecho de");
    preorden_der(&arbol);

    return 0;
}
