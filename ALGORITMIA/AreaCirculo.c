#include <stdio.h>
#include <math.h>

#define PI 3.141592

int main(){
	double radio,area;

	printf("Ingrese el radio: ");
	scanf("%lf",&radio);
	area = PI*pow(radio,2);
	printf("El área del círculo es: %lf",area);
	
	return 0;
}
