#include <stdio.h>
#include <stdlib.h>
long fibonacci(long numero);

int main()
{
  int resultado, i, num;
  printf("La Serie de Fibonacci");
  printf("intrduzca un numero");
  scanf("%d",&num);

  resultado = fibonacci(num); //invocacion//

  printf("fibonacci(%1d) = 1%d", num, resultado);

  return 0;

}
long fibonacci(long numero)
{
   if(numero == 0 || numero == 1)
   {
     return numero;
   }
   else{
   return  fibonacci(numero-1)+ fibonacci(numero-2);
   }
}
