#include <stdio.h>
#include <math.h>

int main(){
	double lado, area;
	
	printf("Ingrese el lado del cuadrado: ");
	scanf("%lf",&lado);
	area = pow(lado,2);
	printf("El área del cuadrado es: %.4lf\n",area);
	
	return 0;
}
