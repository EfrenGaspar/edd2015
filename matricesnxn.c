#include <stdio.h>
#include <stdlib.h>

int main()
{
	int filas1, columnas1, filas2, columnas2, cont1, cont2, cont3;
	int **matriz1;
	int **matriz2;
	int **matrizR;
//primer matriz	
	printf("Ingresa el numero de filas y columnas de la primer matriz respectivamente:\n");
	scanf("%d%d", &filas1, &columnas1);
	//Se reserva el tamaño en bytes
	matriz1=(int**) malloc(filas1*sizeof(int*));
	for(cont1=0; cont1<filas1; cont1++)
		matriz1[cont1]=(int*) malloc(columnas1*sizeof(int));
	//se capturan los datos
	for(cont1=0; cont1<filas1; cont1++)
	{	
		for(cont2=0; cont2<columnas1; cont2++)
		{
			printf("Ingresa los valores de primer matriz en la posicion: [%d][%d] ", cont1+1, cont2+1);
			scanf("%d", &matriz1[cont1][cont2]);
		}
	}
	printf("La matriz ingresada es:\n");
	for(cont1=0; cont1<filas1; cont1++)
	{
		printf("[");
		for(cont2=0; cont2<columnas1; cont2++)
			printf(" %d ", matriz1[cont1][cont2]);	
		printf("]\n");
	}
//segunda matriz
	printf("Ingresa el numero de filas y columnas de la segunda matriz respectivamente:\n");
        scanf("%d%d", &filas2, &columnas2);
        //Se reserva el tamaño en bytes
        matriz2=(int**) malloc(filas2*sizeof(int*));
        for(cont1=0; cont1<filas2; cont1++)
                matriz2[cont1]=(int*) malloc(columnas2*sizeof(int));
        //se capturan los datos
        for(cont1=0; cont1<filas2; cont1++)
        {
                for(cont2=0; cont2<columnas2; cont2++)
                {
                        printf("Ingresa los valores de la segunda matriz en la posicion: [%d][%d] ", cont1+1, cont2+1);
                        scanf("%d", &matriz2[cont1][cont2]);
                }
        }
        printf("La matriz ingresada es:\n");
        for(cont1=0; cont1<filas2; cont1++)
        {
                printf("[");
                for(cont2=0; cont2<columnas2; cont2++)
                        printf(" %d ", matriz2[cont1][cont2]);
                printf("]\n");
        }
//tercer matriz
        //Se reserva el tamaño en bytes
        matrizR=(int**) malloc(filas1*sizeof(int*));
        for(cont1=0; cont1<filas1; cont1++)
	{
		matrizR[cont1]=(int*) malloc(columnas2*sizeof(int));
	}
        //se realizan las operaciones y se imprime en pantalla el resultado
        printf("El resultado de la multiplicacion de las matrices ingresadas es:\n");
        for(cont1=0; cont1<filas1; cont1++)
        {
                printf("[");
                for(cont2=0; cont2<columnas2; cont2++)
		{
			for(cont3=0; cont3<filas2; cont3++);
			{	
				matrizR[cont1][cont2]+= matriz1[cont1][cont3]*matriz2[cont3][cont2];  
			}             
        		printf(" %d ", matrizR[cont1][cont2]);
		}
                printf("]\n");
        }
	return 0;
}
