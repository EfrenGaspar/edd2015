#include"pilaenlazada.h"
#include <stdio.h>
#include<stdlib.h>

int main()
{
	NODO *puntero;
	int val,op;
	puntero=(NODO*)malloc(sizeof(NODO) *1);

	inicializar(puntero);
	do {

		printf("Elija una opcion\n 1- Push\n 2-Pop\n 3- Cima\n");
		scanf("%d", &op); 

		switch (op){
			case 1:
				printf("Escriba el numero a ingresar\n");
				scanf("%d", &val);
				push(puntero, val);
				break;
			case 2:
				pop(puntero);
				break;
			case 3:
				cima(puntero);
				break;
			default:
				puts("Estas mal\n");
		}
	}
		while (op < 4);

	
	return 0;
}
void inicializar(NODO *cabecera)
{
	cabecera -> sig = NULL;
}	

void push(NODO *cabecera, int valor_nuevo)
{
	NODO* primer;
        NODO* aux;

        aux = cabecera;

        primer=(NODO*)malloc(sizeof(NODO) *1);
        primer -> dato = valor_nuevo;

        while(aux -> sig != NULL){
                aux = aux -> sig;
        }

        aux -> sig = primer;
        primer -> sig = NULL;

	
			
}

void pop(NODO *cabecera)
{
	NODO* ultimo;

	if (cabecera -> sig != NULL){
		ultimo = cabecera -> sig;
		cabecera -> sig = ultimo -> sig;
		free(ultimo);
	}
	else {
		puts("VOID STACK\n");
	}
	
	cabecera -> sig = ultimo -> sig;
	//cabecera -> sig = NULL;	
	
}

void cima (NODO *cabecera)
{
	NODO* aux;
	NODO *actual;
	aux = cabecera;

	while (aux -> sig != NULL){
	        aux = aux -> sig;
	}
	actual = aux;
	printf("El ultimo en entrar es: %d \n", actual -> dato);
}
