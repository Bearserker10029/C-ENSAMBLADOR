#include <stdio.h>
#include <math.h>

#define PI_REAL 3.1415926535

void LeerMaximoError(double *errorMaximoIngresado);
void CalcularValoresReportes(double errorMaximoIngresado,double *piCalculado,double *errorAbsCalculado,int *cantTerminos);
void ImprimirReporte(double piCalculado,double errorAbsCalculado,int cantTerminos);

int main(){
	double errorMaximoIngresado,piCalculado,errorAbsCalculado;
	int cantTerminos;
	
	LeerMaximoError(&errorMaximoIngresado);
	if (errorMaximoIngresado>0 && errorMaximoIngresado<1){
		CalcularValoresReportes(errorMaximoIngresado,&piCalculado,&errorAbsCalculado,&cantTerminos);
		ImprimirReporte(piCalculado,errorAbsCalculado,cantTerminos);
	}
	else{
		printf("El error absoluto debe ser mayor a cero y menor a 1");
	}
	
	return 0;
}

void LeerMaximoError(double *errorMaximoIngresado){
	printf("Ingrese el máximo error absoluto permitido: ");
	scanf("%lf", errorMaximoIngresado);
}
void CalcularValoresReportes(double errorMaximoIngresado,double *piCalculado,double *errorAbsCalculado,int *cantTerminos){
	int i;
	double termino, productoria;
	i=1;
	*errorAbsCalculado = 1;
	productoria = 1;
	
	while (*errorAbsCalculado>=errorMaximoIngresado){
		termino = (pow(2*i,2))/((2*i-1)*(2*i+1));
		productoria *= termino;
		*piCalculado = 2*productoria;
		*errorAbsCalculado = fabs(PI_REAL - *piCalculado);
		i++;
	}
	*cantTerminos = i-1;
}

void ImprimirReporte(double piCalculado,double errorAbsCalculado,int cantTerminos){
	printf("El valor de PI calculado es: %.10lf\n",piCalculado);
	printf("El error absoluto es: %.10lf\n",errorAbsCalculado);
	printf("La cantidad de términos obtenida es: %d\n",cantTerminos);
}



