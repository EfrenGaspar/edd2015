#include <stdio.h>
#include <stdlib.h>

int main()
{
	int matriz1[3][3];
	int matriz2[3][3];
	int matrizR[3][3]={};
	int cont1, cont2, cont3;
//primer matriz
	for(cont1=0; cont1<3; cont1++)
	{	
		for(cont2=0; cont2<3; cont2++)
		{	
			printf("Ingresa el valor de la primer matriz en la posicion [%d][%d]",cont1+1, cont2+1);
			scanf("%d", &matriz1[cont1][cont2]);
		}
	}
	printf("La matriz ingresada es:");
	for(cont1=0; cont1<3; cont1++)
        {
		printf("\n[");
                for(cont2=0; cont2<3; cont2++)
                {
                        printf(" %d ", matriz1[cont1][cont2]);
                }
		printf("]");
        }
	printf("\n");
//segunda matriz 
	for(cont1=0; cont1<3; cont1++)
        { 
                for(cont2=0; cont2<3; cont2++)
                { 
                        printf("Ingresa el valor de la primer matriz en la posicion [%d][%d]",cont1+1, cont2+1);
                        scanf("%d", &matriz2[cont1][cont2]);
                }
        }
        printf("La matriz ingresada es:");
        for(cont1=0; cont1<3; cont1++)
        {
                printf("\n[");
                for(cont2=0; cont2<3; cont2++) 
                {
                        printf(" %d ", matriz2[cont1][cont2]);
                }
                printf("]"); 
        }
        printf("\n");
//tercer matriz 
	printf("El resultado de la multiplicacion de las matrices ingresadas es:");
	for (cont1=0; cont1<3; cont1++)
	{
		printf("\n[");
                for (cont2=0; cont2<3; cont2++)
		{
			for (cont3=0; cont3<3; cont3++)
			{
				matrizR[cont1][cont2]+=matriz1[cont1][cont3]*matriz2[cont3][cont2];
			}
			printf(" %d ", matrizR[cont1][cont2]);
		}
		printf("]");
	}
	printf("\n");
	return 0;
}
