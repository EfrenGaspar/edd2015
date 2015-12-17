/*
programa que muestre una expresion prefija a partir de una expresion infija
para ello  una estructura forma parte de la base determinado por un char
definir un tipo
de igual mananera las funciones de agregar (push), pop(quitar) y determinar si la pila esta vacia
 
la funcion principal se declara  y hace null  a  ptrPila pila1 = NULL;
declaramos nuestro arreglo con los caracteres (char)
  char expr[] = {'a','+','(','b','-','c', '*','d','^','e',')','/','a'};
ademas contiene a partir de switch la condicion que detrmine que convierta la expresion 

*/ 
#include <iostream>

#include <stdlib.h>
using namespace std;

typedef struct nodo_s{
 char simbolo;
 struct nodo_s *siguiente;

}nodo_t;

typedef nodo_t *ptrNodo;
typedef nodo_t *ptrPila;

void push(ptrPila *pila, char s){
  ptrNodo nodo;
  nodo = (ptrNodo)malloc(sizeof(nodo_t));
    if(nodo != NULL){
     nodo->simbolo = s;
     nodo->siguiente = *pila;
     *pila = nodo;

    }

}

char pop(ptrPila *pila){
  ptrNodo nodo;
  char s;
  nodo = *pila;
  s = (*pila)->simbolo;
  *pila = (*pila)->siguiente;
  free(nodo);
  return s;

}

int pila_vacia(ptrPila *pila){
  return (*pila == NULL ? 1:0);
}

int main()
{
  ptrPila pila1 = NULL;

  char expr[] = {'a','+','(','b','-','c', '*','d','^','e',')','/','a'};
   char dato;

   cout<<"infijo: \t";
   for(int i = 0; i < 13; i++)
     cout<<expr[i] << " ";

     cout<< "\n\n prefijo : \t";

     for(int i = 0; i < 13; i++){
     switch(expr[i]){
      case'a': case'b': case 'c': case 'd': case 'e': case '(':
        push(&pila1, expr[i]);
       break;

       case'+': case'-': case'*': case'/': case'^':
        cout << expr[i] << " ";
        break;
        case ')':
         if(pila1 !=NULL)
         {
           dato = pop(&pila1);
           while (pila1 != NULL && dato != '('){
             cout << dato<< " ";
             dato = pop(&pila1);
           }

         }
         break;
     }

   }
   while(pila1 != NULL)
     cout <<  pop(&pila1) << " ";



}
