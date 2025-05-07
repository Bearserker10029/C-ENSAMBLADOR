#include <stdio.h>

void LeerDatosEntrada(double *n,int *cantIteraciones);
void CalcularCocientePromedio(double n,double a,double *nEntreA,double *promedio);

int main(){
	double n,a,nEntreA,promedio;
	int cantIteraciones,i;
	
	LeerDatosEntrada(&n,&cantIteraciones);
	if (n>0 && cantIteraciones>=2){
		a=1;
		i=1;
		printf("i\t N\t\t a\t\t N/a\t\t Promedio\n");
		while (i<=cantIteraciones){
			printf("%d\t",i);
			CalcularCocientePromedio(n,a,&nEntreA,&promedio);
			a=promedio;
			i++;
		}
		printf("La raíz cuadrada de %lf obtenida es %lf\n",n,a);
	}	
	return 0;
}

void LeerDatosEntrada(double *n,int *cantIteraciones){
	printf("Ingrese un número positivo: ");
	scanf("%lf",n);
	printf("Ingrese la cantidad de iteraciones: ");
	scanf("%d",cantIteraciones);	
}

void CalcularCocientePromedio(double n,double a,double *nEntreA,double *promedio){
	*nEntreA = n/a;
	*promedio = (a + *nEntreA)/2;
	printf(" %.6lf\t",n);
	printf(" %.6lf\t",a);
	printf(" %.6lf\t",*nEntreA);
	printf(" %.6lf\n",*promedio);
}


