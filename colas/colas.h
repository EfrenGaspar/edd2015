#ifndef _COLAS_H_
#define _COLAS_H_

typedef struct nodo{
	int dato;

	struct nodo *sig;
}NODO;

void inicializar(NODO *cabecera);
void insertar (NODO *cabecera, int valor_nuevo);
void sacar(NODO *cabecera);
void imprimir_frente(NODO *cabecera);
void imprimir_cola(NODO *cabecera);
#endif
