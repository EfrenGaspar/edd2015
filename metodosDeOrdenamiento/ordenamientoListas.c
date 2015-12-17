/*
 ordenamiento con el metodo de burbuja pero con listas enlazadas  de igual eficiencia
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo          // erstructura base para crear nodos 
{
        int dato;
        struct Nodo *sgt;
}TNodo;

typedef struct LE  // estructura para crea una lista //
{
        TNodo *inicio;
}TLE;

TNodo *crearNodo(int x)  //nodo crear//
{
      TNodo *nodo=(TNodo*)malloc(sizeof(TNodo));
      nodo->dato=x;
      nodo->sgt=NULL;
      return nodo;
}

TLE *crearLista()  //crea la secuencia de una lista definido con el typedef anteriormente
{
    TLE *lista=(TLE*)malloc(sizeof(TLE)); //asigancion de memoria, casteo, tipo longitud//
    lista->inicio=NULL;
    return lista;
}



void ordenamiento(TLE *lista)
{
    TNodo *p=NULL; //punteros a null
    TNodo *t=NULL;
    int temp; // funciona como auxiliar ir moviendo cada elemento sin perder su numero
    int band=1;  // bandera
    while(band!=0)
    {
                  band=0;
    p=lista->inicio;
    while(p!=NULL)
    {
                        t=p; //igualdad
                        p=p->sgt;
                        if(p!=NULL)
                        {
                                  if(t->dato>p->dato)
                                  {
                                          temp=t->dato;
                                          t->dato=p->dato;
                                          p->dato=temp;
                                          band++;
                                  }
                        }
    }

    }
}

void insertar (TLE *lista, int x)
{
    TNodo *nodo=crearNodo(x);
    TNodo *p=NULL;
    if(lista->inicio==NULL)
    {
    lista->inicio=nodo;
    }
    else
    {
        p=lista->inicio;
        while(p->sgt!=NULL)
        {
        p=p->sgt;
        }
        p->sgt=nodo;
    }
}

void reportar(TLE *lista)
{
    TNodo *p=NULL;
    p=lista->inicio;
    while(p!=NULL)
    {
                  printf("%d, ",p->dato);
                  p=p->sgt;
    }
}





int main()
{
    TLE *lista=crearLista();
    int i,num,n;
    printf("\n\tIngrese en numero de datos q desea ingresar : ");
    scanf("%d",&n);
    printf("\n");
    for(i=0;i<n;i++)
    {
                    printf("\tElemento[%d] : ",i);
                    scanf("%d",&num);
                    insertar(lista,num);
    }
    printf("\n\tElementos Ingresados : \n\t");
    reportar (lista);
    ordenamiento(lista);
    printf("\n\n\tElementos Ordenados : \n\t");
    reportar (lista);

    return 0;
}
