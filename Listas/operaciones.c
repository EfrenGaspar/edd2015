#include "operaciones.h"
#include <stdio.h>
#include <stdlib.h>

int  main ()
{
	NODO *puntero;
        int val;
		
	puntero=(NODO*)malloc(sizeof(NODO) *1); 
	do{
		 printf("Ingrese el valor: ");
        	scanf("%d", &val);
	
		//inicializar(puntero);
	
		insertar_al_principio(puntero, val);
	
		//borrar_lista(puntero);

		//insertar_al_final(puntero, val);

		//insertar_despues_de(puntero, val);
	}

	while( val != -1);
                imprimir_lista(puntero);

        return 0;

}


void inicializar(NODO *cabecera)
{
	cabecera->sig = NULL;
}

void insertar_al_principio(NODO *cabecera, int valor_nuevo)
{
	NODO* nuevo;

	nuevo=(NODO*)malloc(sizeof(NODO) *1 );
	nuevo->val = valor_nuevo;
	nuevo->sig = cabecera->sig;
	cabecera->sig = nuevo;
}

void borrar_lista(NODO *cabecera)
{
	 NODO* actual;
	 NODO* borrar;

	/* Si es diferente de nulo borrar lista */
	if (cabecera->sig != NULL) {
		actual = cabecera->sig;
		borrar = cabecera->sig;
		/* Mientras el siguiente sea diferente de nulo */
		while ( actual->sig != NULL) {
			actual = actual->sig;
			free(borrar);
			borrar = actual;
		}
		free(borrar);
		cabecera->sig = NULL;
	}
}

void insertar_al_final(NODO *cabecera, int valor_nuevo)
{
	NODO *nuevo;
	nuevo = cabecera;	
	//Reservo el espacio de memoria
	nuevo=(NODO*)malloc(sizeof(NODO) * 1);
	nuevo->val  = valor_nuevo;
	
	 nuevo->sig = cabecera->sig;
	nuevo->sig = NULL;
}

void insertar_despues_de(NODO *cabecera, int valor_nuevo)
{
	NODO *nuevo;
	NODO *anterior;

	//Reservo el espacio de memoria.
	nuevo=(NODO*)malloc(sizeof(NODO) * 1);
	nuevo->val = valor_nuevo;	
	anterior=(NODO*)malloc(sizeof(NODO) * 1);
	
	anterior->sig = nuevo;
	nuevo->sig = cabecera->sig;
	
}

void imprimir_lista(NODO *cabecera)
{
	NODO* x;
 	x=cabecera;
	
	

	printf("La lista es: \n");
	
	while( x != NULL )
	{
		printf("%d\n", x->val);
		x = x->sig;
	}
}

