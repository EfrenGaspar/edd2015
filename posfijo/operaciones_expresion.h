#ifndef _OPERACIONES_EXPRESION_H_
#define _OPERACIONES_EXPRESION_H_
#include "expresionodo.h"
nodo *crearLista(nodo *lista);
nodo *push(char simbolo, nodo *pila);
nodo *insertarNodoFinal(char simbolo, nodo *lista);
nodo *pop(char *valor, nodo *pila);
void imprimirExpresion(nodo *lista);

int expresionBalanceada(char expresion[]);
int esOperador(char simbolo);
int prioridad(char operador);
nodo *infijaPosfija(char expresion[]);

#endif
