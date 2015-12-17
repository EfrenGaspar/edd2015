#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operaciones_expresion.h"


nodo *crearLista(nodo *lista)
{
  return lista = NULL;
}
nodo *push(char simbolo, nodo *pila)
{
   nodo *nodoNuevo;
   nodoNuevo = (nodo *)malloc(sizeof(nodo));
   if(nodoNuevo!= NULL)
   {
     nodoNuevo->simbolo = simbolo;
     nodoNuevo->siguiente = pila;

     pila = nodoNuevo;

   }
 return pila;
}



nodo *insertarNodoFinal(char simbolo, nodo *lista)
{
   nodo *nodoNuevo, *nodoAuxiliar;
   nodoNuevo = (nodo *) malloc(sizeof(nodo));
   if(nodoNuevo != NULL)
   {
      nodoNuevo->simbolo = simbolo;
      nodoNuevo->siguiente = NULL;
      if(lista == NULL)
         lista = nodoNuevo;

      else
       {
          nodoAuxiliar = lista;
          while(nodoAuxiliar->siguiente != NULL)
                nodoAuxiliar = nodoAuxiliar->siguiente;
           nodoAuxiliar->siguiente = nodoNuevo;
       }
    }
      return lista;
}



nodo *pop(char *valor, nodo *pila)
{
    nodo *nodoAuxiliar;
     char dato;
    if(pila == NULL)
       printf("pila Vacia");
    else
     {
        nodoAuxiliar = pila;
        dato = nodoAuxiliar->simbolo;
        pila =nodoAuxiliar->siguiente;
        *valor = dato;
        free(nodoAuxiliar);
     }
   return pila;
}



void imprimirExpresion(nodo *lista)
{
   nodo *nodoAuxiliar;
   nodoAuxiliar = lista;
   printf("POSFIJA: ");
   while(nodoAuxiliar!=NULL)
   {
      printf("%c ", nodoAuxiliar->simbolo);
      nodoAuxiliar = nodoAuxiliar->siguiente;

   }
}

int expresionBalanceada(char expresion[]) // expression de parentesis los identifica
{
   nodo *pilaAuxiliar;
   int longitudExpresion, i;
   char valor;

   pilaAuxiliar=crearLista(pilaAuxiliar);
   longitudExpresion = strlen(expresion);
   for(i=0; i<longitudExpresion; i++)
   {
     if (expresion[i]== '(')  // caracter      //
         pilaAuxiliar = push(expresion[i], pilaAuxiliar);

     if(expresion[i]== ')')   //caracter //
        pilaAuxiliar = pop(&valor, pilaAuxiliar);
   }

   if (pilaAuxiliar == NULL)
       return 1;
    return 0;
}


int esOperador(char simbolo)
{
  if((simbolo == '+') || (simbolo == '-') || (simbolo == '*') || (simbolo == '/') || (simbolo == '^'))  // caracter//
      return 1;
    return 0;

}



int prioridad(char operador)
{
   if(operador == '^')
      return 3;
   if ((operador == '*') || (operador == '/'))
      return 2;
   if((operador == '+') || (operador == '-'))
      return 1;
   if(operador == '(')
      return 0;
}


nodo *infijaPosfija(char expresion[])
{
   nodo *pila,*posfija;
   int longitudExpresion, i;
    char valor;

   pila = crearLista(pila);  //inicilar la pila con la funcion//
   posfija = crearLista(posfija); // inicializar

   longitudExpresion = strlen(expresion); // se necesita para ir recorriendo la lista 1 en 1 (longitud);

   for(i = 0; i<longitudExpresion; i++)
     {
        if  (((expresion[i]>=48) && (expresion[i]<=57)) ||((expresion[i]>=65) && (expresion[i]<=90)) || ((expresion[i]>=97) && (expresion[i]<=122)))
             posfija =insertarNodoFinal(expresion[i],posfija);
       else
       {
         if (expresion[i]== '(')
             pila = push(expresion[i], pila);
         else
         {
            if(esOperador(expresion[i]))
             {
                if(pila == NULL)
                     pila = push(expresion[i],pila);
                else
                 {
                  while(pila!=NULL)
                 {
                  if((prioridad (pila->simbolo)>= prioridad(expresion[i])))
                  {
                     pila =pop(&valor, pila);
                     posfija = insertarNodoFinal(valor, posfija);

                  }
                  else
                     break;
                 }
               pila = push(expresion[i],pila);
            }
           }
          }

       }


         if(expresion[i]== ')')
          {
             while((pila->simbolo!= '(') &&(pila!=NULL))
             {
             pila= pop(&valor,pila);
             posfija = insertarNodoFinal(valor,posfija);
             }
               pila =pop(&valor,pila);
         }

    }
     while(pila!=NULL)
     {
       pila =pop(&valor, pila);
       posfija=insertarNodoFinal(valor,posfija);
     }

   return posfija;
}











