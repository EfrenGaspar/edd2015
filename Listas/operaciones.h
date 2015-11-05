#ifndef _OPERACIONES_H_
#define _OPERACIONES_H_

#include "nodo.h"

void insertar_al_principio(NODO *cabecera, int valor_nuevo);

void insertar_al_final(NODO *cabecera, int valor_nuevo);

void insertar_despues_de(NODO *cabecera, int valor_nuevo);

void imprimir_lista(NODO *cabecera);

void borrar_lista(NODO *cabecera);

void inicializar(NODO *cabecera);

#endif
