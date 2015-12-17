/*programa de ordenamiento quicksort
 */
#include <stdio.h>
#include <stdlib.h>

//prototipos//
void qs(int lista[], int limite_izq, int limite_der);
void quicksort(int lista[], int n);
//funcion principal//
int main()
{
   int i;
   int lista[] = {100, 56, 0,1, -46, 2, 46, 5, 9, 6, 67, 23, 5};
   int size = sizeof(lista)/sizeof(int);

  printf("lista desordenada \n");

  for(i =0; i<size; i++)
   {
     printf("%d", lista[i]);
     if (i<size-1)
         printf(",");
   }

   printf("\n");
  quicksort(lista, size);

   printf("lista ordenada \n");
    for( i =0; i<size; i++) {
       printf("%d", lista[i]);
        if(i<size-1)
          printf(",");
  }
 return 0;
}

//implementcion//
void qs(int lista[], int limite_izq, int limite_der)
{
   int izq, der, temporal, pivote;  //aguarda en variables//izq der:indices que se mueven, temporal:ayudar intercambia los valores del algoritmo,  pivote: punto de referwncia
   izq = limite_izq;
   der = limite_der;
   pivote = lista[(izq+der)/2];
   do{

    //6,1,5,4,7,2,3  cambia si en lado der es mayor que pivote y lado izq  menor al pivote
  //todo esto va  moviendose  hacia el centro los indices pasan al siguiente numro//

    while(lista[izq]<pivote && izq< limite_der)izq++;
    while(pivote < lista[der] && der > limite_izq)der--;
    if(izq <= der)
      {
         temporal = lista[izq];
         lista[izq] = lista[der];
         lista[der] = temporal;
          izq++;
           der--;

      }
   }while(izq <=der);

  if(limite_izq < der) {qs(lista, limite_izq,der);}
  if(limite_der>izq){qs(lista,izq, limite_der);}
}




void quicksort(int lista[], int n)
{
  qs(lista, 0, n-1);  // manda a llamar el metodo recursivo

}


