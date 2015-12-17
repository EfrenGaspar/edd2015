#ifndef _PILAENLAZADA_H_
#define _PILAENLAZADA_H_

typedef struct nodo{
	int dato;

	struct nodo *sig;
}NODO;		

void inicializar(NODO *cabecera);
void push (NODO *cabecera, int valor_nuevo);
void pop(NODO *cabecera);
void cima(NODO *cabecera);


#endif
