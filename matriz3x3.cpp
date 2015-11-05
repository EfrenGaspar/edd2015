#include<iostream>
using namespace std;

int main()
{
	int matrizA[3][3];
	int matrizB[3][3];
	int matrizR[3][3]={};
	int cont1, cont2, cont3;

	for (cont1=0; cont1<3; cont1++)
		for (cont2=0; cont2<3; cont2++)
		{
			cout<<"Ingrese el valor de la primera matriz en la posicion: Fila "<<cont1+1<<", Columna "<<cont2+1<<" ";
			cin>>matrizA[cont1][cont2];
			cout<<endl; 
		}		
	for (cont1=0; cont1<3; cont1++)
                for (cont2=0; cont2<3; cont2++)
                {
			cout<<"Ingrese el valor de la segunda matriz en la posicion: Fila "<<cont1+1<<", Columna "<<cont2+1<<" ";
                        cin>>matrizB[cont1][cont2];
                        cout<<endl;
		}
	cout<<"La primer matriz ingresada es:"<<endl;
	for (cont1=0; cont1<3; cont1++)
        {
        	cout<<"[";
                 for (cont2=0; cont2<3; cont2++)
                {
                        cout<<" "<<matrizA[cont1][cont2]<<" ";
                }
                cout<<"]"<<endl;
        }
	cout<<"La segunda matriz ingresada es:"<<endl;
	for (cont1=0; cont1<3; cont1++)
        {
        	cout<<"[";
                 for (cont2=0; cont2<3; cont2++)
                {
                        cout<<" "<<matrizB[cont1][cont2]<<" ";
                }
                cout<<"]"<<endl;
        }
	cout<<"El resultado de la multiplicacion de las matrices ingresadas es:"<<endl;
	for (cont1=0; cont1<3; cont1++)
	{
		cout<<"[";
                for (cont2=0; cont2<3; cont2++)
		{
			for (cont3=0; cont3<3; cont3++)
			{
				matrizR[cont1][cont2]+=matrizA[cont1][cont3]*matrizB[cont3][cont2];
			}
			cout<<" "<<matrizR[cont1][cont2]<<" ";
		}
		cout<<"]"<<endl;
	}
}
