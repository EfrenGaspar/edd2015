
#include<stdio.h>
#include<stdlib.h>
#include <string.h>


#include "operaciones_expresion.h"
#include "operaciones_expresion.c"
#include "expresionodo.h"
int main()
{

  char expresion[50];
   nodo *posfija;
   int opcion;

   do{
       printf("\n\n------menu-----\n\n");

       printf("(1) Convertir expresion infija a posfija\n");
    printf("(2) Convertir expresion infija a prefija\n");
     printf("(3) evaluar expresion  posfija\n");
     printf("(4) Salir\n");
     printf("opcion: ");

     scanf("%d", &opcion);

      switch (opcion)
      {
         case 1:
            printf("Expresion infija: ");
            scanf("  %[^\n]", expresion);
           if(expresionBalanceada(expresion))
            {

             posfija = infijaPosfija(expresion);
             imprimirExpresion(posfija);
            }
            else
               printf("Expresion no aceptada ");
        break;


       case 4:
         printf("adios");
      }

     }while(opcion !=4);


return 0;
}
