#include"pilaarray.h"
#include<stdio.h>
#include<stdlib.h>
#define tope 7

int main()
{
	int *puntero, array[tope], val, opcion, tam = 0;
	puntero=(int*)malloc(sizeof(int) *1);

	inicializar(array);
	do{
		printf("Elija la opción deseada\n 1- push\n 2- pop\n 3- cima\n");
		scanf("%d", &opcion);
		switch (opcion){
			case 1: 
				if (tam <= tope){
					printf("Ingrese el valor\n");
					scanf("%d", &val);	
					push(array, puntero, val, tam);
					tam++;
				}
				else 
					printf("Overflow\n");	
				break;
			case 2: 
				pop(array, puntero);
				break;
			case 3:
				cima(array, puntero);
				break;
			case 4:
				break;
			default:
				printf("estas mal\n");
		}
	}	
	while(opcion <=4);
	
	return 0;	
}

void inicializar(int array[])
{	
	int i;
	for (i = 0; i <= tope; i++){
		array[i] = 0;
	} 
}

void push(int array[], int* escalador, int valor, int tam)
{
	
		array[*escalador] = valor;
		tam++;
		
}

void pop(int array[], int* escalador)
{
	array[*escalador] = 0;
	escalador--;
}

void cima(int array[], int* escalador)
{
	printf("El ultimo valor es:  %d\n ", array[*escalador]);
}


