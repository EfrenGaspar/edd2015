#include <iostream>
using namespace std;

int main()
{//Declaracion de variables y pnteros
	int **matrizM1;
	int **matrizM2;
	int **matrizR;
	int filasM1, columnasM1, filasM2, columnasM2, cont1, cont2, cont3;
	cout<<"Ingresa el numero de filas y columnas de la primer matriz respectivamente: \n";//captura del tamaño de la primer matriz
	cin>>filasM1>>columnasM1;
	cout<<"Ingresa el numero de filas y columnas de la segunda matriz respectivamente: \n";//captura del tamaño de la segunda matriz
        cin>>filasM2>>columnasM2;
	if(columnasM1==filasM2)
	{
//primer matriz
	matrizM1 = new int *[filasM1];//reserva de espacio de memoria para la primer matriz
	for (cont1 = 0; cont1<filasM1; cont1++)
		matrizM1[cont1] = new int [columnasM1];
	cout<<"Ingresa los valores de la primer matriz segun su posicion:\n";
	for (cont1 = 0; cont1<filasM1; cont1++)//captura de los valores de la primer matriz 
	{
		for(cont2=0; cont2<columnasM1; cont2++)
		{
			cout<<"fila["<<cont1+1<<"], columna["<<cont2+1<<"]:  ";
			cin>>matrizM1[cont1][cont2];
		}
	}
	cout<<"La primer matriz es:\n";//impresion en pantalla de la primer matriz 
	for (cont1 = 0; cont1<filasM1; cont1++)
        {
		cout<<"[";
                for(cont2=0; cont2<columnasM1; cont2++)
                {
                        cout<<" "<<matrizM1 [cont1][cont2]<<" ";
                }
		cout<<"]"<<endl;
        } 
//segunda matriz	
	matrizM2 = new int *[filasM2];//reserva de espacio de memoria para la segunda matriz
        for (cont1 = 0; cont1<filasM2; cont1++)
                matrizM2[cont1] = new int [columnasM2];
        cout<<"Ingresa los valores de la primer matriz segun su posicion:\n";
        for (cont1 = 0; cont1<filasM2; cont1++)//captura de los valores de la segunda matriz
        {
                for(cont2=0; cont2<columnasM2; cont2++)
                {
                        cout<<"fila["<<cont1+1<<"], columna["<<cont2+1<<"]:  ";
                        cin>>matrizM2[cont1][cont2];
                }
        }
        cout<<"La primer matriz es:\n"; //impresion en pantalla de la segnda matriz
        for (cont1 = 0; cont1<filasM2; cont1++)
        {
                cout<<"[";
                for(cont2=0; cont2<columnasM2; cont2++)
                {
                        cout<<" "<<matrizM2 [cont1][cont2]<<" ";
                }
                cout<<"]"<<endl;
        } 
//tercer matriz (matriz resultado)
	matrizR = new int *[filasM1];//reserva de espacio de memoria para la tercer matriz (matriz resultado)
        for (cont1 = 0; cont1<filasM1; cont1++)
                matrizR[cont1] = new int [columnasM2];
	cout<<"El resultado de la multiplicacion de las matrices ingresadas es:"<<endl;
	for (cont1=0; cont1<filasM1; cont1++)//obtencion de los valores de la tercer matriz e impresion en pantalla de la misma 
	{
		cout<<"[";
                for (cont2=0; cont2<columnasM2; cont2++)
		{
			for (cont3=0; cont3<filasM2; cont3++)
			{
				matrizR[cont1][cont2]+=matrizM1[cont1][cont3]*matrizM2[cont3][cont2];
			}
			cout<<" "<<matrizR[cont1][cont2]<<" ";
		}
		cout<<"]"<<endl;
	}
//liberar memoria 
	for(cont1=0; cont1<filasM1; cont1++)
	{
		delete[] matrizM1[cont1];
		delete[] matrizR[cont1];
	}	
	for(cont1=0; cont1<filasM2; cont1++)
		delete[] matrizM2[cont1];
	delete[] matrizM1;
	delete[] matrizM2;
	delete[] matrizR;
	}
	else
	{
		cout<<"La multiplicación de dos matrices con los tamaños ingresados no es válida (para que sea posibles multiplicar dos matrices el número de columnas de la primer matriz debe de ser igual al número de filas de la segunda matriz.)"<<endl;
	}
	return 0;
}
