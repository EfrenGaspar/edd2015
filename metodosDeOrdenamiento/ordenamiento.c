/* programa que determina 3 metodos de ordenamiento permite al usuario elegir cada uno de ellos segun la eficiencia que se requiera.
*/

#include <stdlib.h>
#include <stdio.h>
/*prototipo*/
void burbuja(int a [], int n);
void insercion(int a[], int n);
void seleccion(int  a[], int  n);


/*funcion principal*/
int main ()
{


   int tam, n, opcion, a;
   /* definir el tamaño del arreglo*/
   printf("\ningrese el tamaño del arreglo:n");
   scanf("%d", &tam);
   int arreglo[tam];
   /*ingresando los valores del arreglo */
   printf("ingrese los valores al arreglo:n");
   for(n = 0; n < tam; n++)
       scanf("%d", &arreglo[n]);
       printf("n");
   /* mostrar el arreglo original*/
   printf("arreglo original:n");
   for(n = 0; n < tam; n++)
       printf("%d", arreglo[n]);
       printf("n");

   /* hacer un menu para determinar que funcion se requiere*/
   /*antes se determina el arreglo original sin ser ordenado*/
   do{
     printf("----MENU-----\n\n");
     printf("(1)ordenar por medio de burbuja \n");
     printf("(2)ordenar pr medio de insercion\n");
     printf("(3)ordenar por medio de seleccion\n");


     printf("(4) salir de la pantalla \n  ");
     printf("opcion");
     scanf("%d", &opcion);

     switch(opcion)
     {
       case 1:
       printf("\nMetodo  de ordenamiento de Burbuja\n");
       /*hacer el llamado a la funcion de burbuja a la cual se le pasa parametros del arreglo y tamano*/
    burbuja(arreglo, tam);
    /*mostrar el arreglo ordenando */
    printf("arreglo ordenado /n");
    for(n=0; n<tam; n++)
        printf("%d", arreglo[n]);
        printf("n");
       break;


       case 2:
       printf("\n Metodo de ordenamiento por medio de insercion\n");

       insercion(arreglo, tam);
       printf("arreglo ordenando \n");
       for(n =0; n<tam; n++)
       printf("%d",arreglo[n]);
       printf("\n");



       break;

       case 3:
       printf("\n Metodo de ordenamiento por medio de seleccion\n");
       seleccion(arreglo, tam);
       printf("arreglo ordenado por seleccion \n");
       for(n = 0; n<tam; n++)
       printf("%d", arreglo[n]);
       printf("\n");


       break;








       case 4:
        printf("\n salir del sistema");
       break;
       default:
       printf("opcion erronea");
       break;
     }


   }while(opcion != 4);


return 0;
}
/*implementacion*/
void burbuja(int a [], int  n)
{
  int interruptor = 1;
  int pasada, j;
  for (pasada = 0;pasada < n-1 && interruptor; pasada++)
  {
   /*bucle controla el numero de pasadas */
   interruptor = 0;
     for (j = 0; j < n-pasada-1; j++)
       if (a[j] > a[j+1])
       {
        /*aqui los elemntos estan desordenados se necesita ordenarlos  */
       int aux;
       interruptor = 1;
       aux = a[j];
       a[j] = a[j+1];
       a[j+1] = aux;
       }
   }
}

void insercion(int a[], int n)
{
   int i, j;
   int aux;
   for(i = 1; i< n; i++)
   {
   //indice j  busca la posicion correcta
    j = i;
    aux  = a[i];
    //se  localixa el punto de insercion  explorado hacia abaj
    while (j > 0 && aux < a[j-1])
    {
     //desplazar elementos haca arriba  para hacer espacio
     a[j] = a[j-1];
     j--;

    }
    a[j] = aux;

   }


}

void seleccion(int  a[], int n)
{
    int indiceMenor, i, j;
    //ordenadar a[0], a[n-2], en cada pasada
    for(i = 0; i < n-1; i++)
    {
       // comienzo de exploracion  en indice i
       indiceMenor = i;
       //j explora la sublista de a[i+1]
       for(j = i+1; j<n; j++)
         if(a[j] < a[indiceMenor])
           indiceMenor = j;
           //situael elemrnt mas pequeño en a[i];
           if(i != indiceMenor)
           {
              int aux = a[i];
              a[i] = a[indiceMenor];
              a[indiceMenor] = aux;


           }
    }




}



