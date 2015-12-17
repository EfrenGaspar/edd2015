#include"colas.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
        NODO *puntero;
        int val,op;
        puntero=(NODO*)malloc(sizeof(NODO) *1);

        inicializar(puntero);
        do {

                printf("Elija una opcion\n 1- Inserta un numero\n 2-Borrar dato\n 3- Imprimir frente\n 4- Imprimir cola\n");
                scanf("%d", &op);

                switch (op){
                        case 1:
                                printf("Escriba el numero a ingresar\n");
                                scanf("%d", &val);
                                insertar(puntero, val);
                                break;
                        case 2:
                                sacar(puntero);
                                break;
                        case 3:
                                imprimir_frente(puntero);
				break;
			case 4:
				imprimir_cola(puntero);
				break;
                        default:
                                puts("Estas mal\n");
                }
        }
                while (op < 5);


        return 0;
}


void inicializar(NODO *cabecera)
{
	cabecera -> sig= NULL;
}

void insertar(NODO *cabecera, int valor_nuevo)
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


void sacar(NODO *cabecera)
{
	 NODO* ultimo;
	
        if (cabecera -> sig != NULL){
                ultimo = cabecera -> sig;
		free(ultimo);
    
        }
        else {
                puts("VOID STACK\n");
        }

        cabecera -> sig = ultimo -> sig;	
	
}

void imprimir_frente(NODO *cabecera)
{
	NODO *actual;
	actual = cabecera;


	if(actual != NULL){
		actual = actual -> sig;
		printf("El utlimo es : %d \n", actual -> dato);

	}
	else 
		puts("Void stack \n");
}

void imprimir_cola(NODO *cabecera)
{
	NODO *actual = cabecera -> sig;

	puts("La cola es: ");
	
	while ( actual != NULL){
		printf("%d\t", actual -> dato);
		actual = actual -> sig;
	}

	printf("\n");
}
