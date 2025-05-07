#include <stdio.h>
#include <math.h>

int main(){
	double ladoa,ladob,ladoc,ladod,area;
	double parteIzq,numerador,parteDer;
	
	printf("Ingrese el valor de los lados: ");
	scanf("%lf %lf %lf %lf",&ladoa,&ladob,&ladoc,&ladod);
	parteIzq = (ladoa+ladob)/2;
	numerador = (pow(ladoc,2) - pow(ladod,2) + pow((ladoa-ladob),2));
	parteDer = sqrt(pow(ladoc,2) - pow((numerador/ (2*(ladoa-ladob))),2));
	area = parteIzq*parteDer;
	printf("El área del trapecio es: %lf\n",area);
	
	return 0;
}
