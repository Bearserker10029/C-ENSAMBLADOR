#include <stdio.h>

void LeerDatos(double *x,int *n);
double CalcularLogaritmoNatural(double x,int n);

int main(){
	double x,resultadoLog;
	int n;
	
	LeerDatos(&x,&n);
	
	if (x==0){
		printf("El logaritmo de %lf es -inf\n",x);
	}
	else if (x<0){
		printf("El logaritmo de %lf es nan\n",x);
	}
	else{
		resultadoLog = CalcularLogaritmoNatural(x,n);
		printf("El logaritmo de % lf es %lf\n",x,resultadoLog);
	}	
	return 0;
}

void LeerDatos(double *x,int *n){
	printf("Ingrese el valor de x: ");
	scanf("%lf",x);
	printf("Ingrese la cantidad de términos: ");
	scanf("%d",n);
}
double CalcularLogaritmoNatural(double x,int n){
	int i;
	double suma,termino;
	
	i = 0;
	suma = 0;
	while (i<=n){
		termino = (1/(2*(double)i+1))*(pow((x-1)/(x+1),(2*i+1)));
		suma += termino; /* suma = suma + termino; */
		i++;
	}
	return (2*suma);	
}



