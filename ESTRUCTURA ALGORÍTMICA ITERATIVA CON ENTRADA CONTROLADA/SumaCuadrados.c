#include <stdio.h>

int main(){
	int n,i,sumatoria,sumaFormula;
	
	printf("Ingrese un valor para n: ");
	scanf("%d",&n);
	
	i = 1;
	sumatoria = 0;
	while (i<=n){
		sumatoria += pow(i,2); /* sumatoria = sumatoria + pow(i,2); */
		i++;
	}
	sumaFormula = n*(n+1)*(2*n+1)/6;
	
	printf("La suma de los cuadrados (iteración) es: %d\n",sumatoria);
	printf("La suma de los cuadrados (fórmula)   es: %d\n",sumaFormula);
	
	if (sumatoria==sumaFormula){
		printf("La f´ormula es correcta.\n");
	}
	
	return 0;
}
