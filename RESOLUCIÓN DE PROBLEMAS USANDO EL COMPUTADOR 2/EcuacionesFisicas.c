#include <stdio.h>
#include <math.h>

#define GRAVEDAD 9.8

double CalcularMRU(double posInicial,double velocidad,double tiempo);
double CalcularMRUV(double posInicial,double velocidad,double tiempo,double aceleracion);
double CalcularCaidaLibre(double altura,double tiempo);

int main(){
	int cantEvaluaciones,i;
	char opcion;
	double posInicial,velocidad,tiempo,posFinal,aceleracion,altura;
	
	printf("Ingrese la cantidad de evaluaciones a realizar: ");
	scanf("%d",&cantEvaluaciones);
	
	i=1;
	while (i<=cantEvaluaciones){
		printf("Ingrese la opci�n de la ecuaci�n a realizar: ");
		scanf("\n%c",&opcion);
		if (opcion=='A'){
			printf("Ingrese la posici�n inicial: ");
			scanf("%lf",&posInicial);
			printf("Ingrese la velocidad: ");
			scanf("%lf",&velocidad);
			printf("Ingrese el tiempo: ");
			scanf("%lf",&tiempo);
			posFinal = CalcularMRU(posInicial,velocidad,tiempo);
			printf("La posici�n final con MRU es: %.2lf\n",posFinal);
		}
		else if (opcion=='B'){
			printf("Ingrese la posici�n inicial: ");
			scanf("%lf",&posInicial);
			printf("Ingrese la velocidad: ");
			scanf("%lf",&velocidad);
			printf("Ingrese el tiempo: ");
			scanf("%lf",&tiempo);
			printf("Ingrese la aceleraci�n: ");
			scanf("%lf",&aceleracion);
			posFinal = CalcularMRUV(posInicial,velocidad,tiempo,aceleracion);
			printf("La posici�n final con MRUV es: %.2lf\n",posFinal);
		}
		else if (opcion=='C'){
			printf("Ingrese la altura: ");
			scanf("%lf",&altura);
			printf("Ingrese el tiempo: ");
			scanf("%lf",&tiempo);
			posFinal = CalcularCaidaLibre(altura,tiempo);
			printf("La posici�n final con ca�da libre es: %.2lf\n",posFinal);		
		}
		i++;
	}	
	return 0;
}

double CalcularMRU(double posInicial,double velocidad,double tiempo){
	return (posInicial+velocidad*tiempo);
}

double CalcularMRUV(double posInicial,double velocidad,double tiempo,double aceleracion){
	return (posInicial+velocidad*tiempo + ((double)1/2)*aceleracion*pow(tiempo,2));
}

double CalcularCaidaLibre(double altura,double tiempo){
	return (altura - 0.5*GRAVEDAD*pow(tiempo,2));
}



