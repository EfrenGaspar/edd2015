//Declaracion de librerias
/*programa de ordenamiento de Mergesort efectivo 
del cual la llamada mergeSort(A,auxArray,0,n-1)
 */
#include <iostream>
using namespace std;

#include <string.h>

//Prototipo de la funcion
void mergeSort(float A[], float aux[], int inicio, int final);
void merge(float A[],  float aux[], int inicio, int mitad, int final);
//Programa principal
int  main()
{
    float A[20], auxArray[20];
    int n=0, i;
    cout<<endl<<endl;//visualizacion en pantalla//
    cout<<"\t\t\t"<<"////////////////////////////////"<<endl;
    cout<<"\t\t\t"<<"///  Metodo de ordenamiento  ///"<<endl;
    cout<<"\t\t\t"<<"///        MERGE SORT        ///"<<endl;
    cout<<"\t\t\t"<<"////////////////////////////////"<<endl;
    cout<<endl;
	 cout<<"Ingrese la dimension del arreglo:"; //usuario detrmina//
	 cin>>n;
    cout<<endl;
	 for(i=0;i<=n-1;i++) //ciclo para la posicion del arreglo//
	    {
		  cout<<"Elemento A["<<i<<"]:";
		  cin>>A[i];
	    }
     mergeSort(A,auxArray,0,n-1);
     cout<<endl;
     cout<<"Ordenando por Merge Sort:";
     cout<<endl<<endl;
     for(i=0;i<=n-1;i++)
		  {
		   cout<<"\t"<<A[i];
		  }
}
void mergeSort( float A[],  float aux[], int inicio, int final)
{
	            int mitad;
	            if(final > inicio)
		           {
                  mitad = (final + inicio) / 2;
		            mergeSort(A, aux, inicio, mitad);
		            mergeSort(A, aux, mitad+1, final);
		            merge(A, aux, inicio, mitad+1, final);
		           }

}
void merge( float A[], float aux[], int inicio, int mitad, int final)
{
	        int i, inicio_end, num_elementos, aux_pos;
	        inicio_end = mitad - 1;
	        aux_pos = inicio;
	        num_elementos = final - inicio + 1;
           while((inicio <= inicio_end) && (mitad <= final))
	             {
		           if(A[inicio] <= A[mitad])
		             {
			           aux[aux_pos] = A[inicio];
			           aux_pos = aux_pos + 1;
			           inicio = inicio + 1;
		             }
	              else
                     {
			             aux[aux_pos] = A[mitad];
			             aux_pos = aux_pos + 1;
			             mitad = mitad + 1;
                     }
		           }
	        while(inicio <= inicio_end)
	             {
		           aux[aux_pos] = A[inicio];
		           inicio = inicio + 1;
		           aux_pos = aux_pos + 1;
		          }
	        while(mitad <= final)
	             {
		           aux[aux_pos] = A[mitad];
		           mitad = mitad + 1;
		           aux_pos = aux_pos + 1;
		          }
           for(i=0; i <= num_elementos; i++)
		        {
		         A[final] = aux[final];
		         final = final - 1;
	           }
}
