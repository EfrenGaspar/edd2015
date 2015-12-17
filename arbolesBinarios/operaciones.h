#ifndef _OPERACIONES_H_
#define _OPERACIONES_H_

#include "nodo.h"

void insertar(struct nodo **arbol, int valor);
void inicializar(struct nodo **arbol);
void preorden_izq(struct nodo **arbol);
void preorden_der(struct nodo **arbol);
#endif

