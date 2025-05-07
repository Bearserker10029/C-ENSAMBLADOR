#include <stdio.h>
#include <math.h>

int main(){
	double lado1,lado2,lado3,area,semiperi;
	
	printf("Ingrese los lados del triángulo: ");
	scanf("%lf %lf %lf",&lado1,&lado2,&lado3);
	semiperi = (lado1+lado2+lado3)/2;
	area = sqrt(semiperi*(semiperi-lado1)*(semiperi-lado2)*(semiperi-lado3));
	printf("El área del triángulo es: %lf\n",area);
	
	return 0;
}
