#include "operaciones.h"
#include <stdio.h>
#include <stdlib.h>

void inicializar(struct nodo **arbol)
{
    *arbol = NULL;
}
void insertar(struct nodo **arbol, int valor)
{
	if (*arbol == NULL) {
		*arbol = (struct nodo*) malloc(sizeof(struct nodo) * 1);

		(*arbol)->dato = valor;
		(*arbol)->izq = NULL;
		(*arbol)->der = NULL;

		return;
	}

	if (valor < (*arbol)->dato) {
		insertar( &((*arbol)->izq), valor);
	} else {
		insertar( &((*arbol)->der), valor);
	}
}

void preorden_izq(struct nodo **arbol)
{
    if((*arbol)->dato != NULL)
        printf("  %d\n", (*arbol)->dato);
    if((*arbol)->izq != NULL)
    preorden_izq(&((*arbol)->izq));
}

void preorden_der(struct nodo **arbol)
{
    if((*arbol)->dato != NULL)
        printf("  %d\n", (*arbol)->dato);
    if((*arbol)->der != NULL)
        preorden_der(&((*arbol)->der));
}
