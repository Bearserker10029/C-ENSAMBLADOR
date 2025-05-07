#include <stdio.h>

int main(){
	double gradosC, gradosF;
	
	printf("Ingrese los grados Celcius: ");
	scanf("%lf",&gradosC);
	gradosF = (double)9/5 * gradosC + 32;
	printf("Los grados Fahrenheit convertidos son: %.1lf\n",gradosF);
	
	return 0;
}
