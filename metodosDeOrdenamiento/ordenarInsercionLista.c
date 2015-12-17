
#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo
{
        int dato;
        struct Nodo *sgt;
}TNodo;

typedef struct LE
{
        TNodo *inicio;
}TLE;

TNodo *crearNodo(int x)
{
      TNodo *nodo=(TNodo*)malloc(sizeof(TNodo));
      nodo->dato=x;
      nodo->sgt=NULL;
      return nodo;
}

TLE *crearLista()
{
    TLE *lista=(TLE*)malloc(sizeof(TLE));
    lista->inicio=NULL;
    return lista;
}



void ordenamiento(TLE *lista)
{
    TNodo *p=NULL;
    TNodo *t=NULL;
    int temp;
    int band=1;
    while(band!=0)
    {
                  band=0;
    p=lista->inicio;
    while(p!=NULL)
    {
                        t=p;
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
