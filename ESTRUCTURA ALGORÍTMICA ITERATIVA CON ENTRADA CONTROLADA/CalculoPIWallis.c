#include <stdio.h>
#include <math.h>

#define PI_REAL 3.141592
#define ERROR 0.005

int main(){
	int cantTerminos,i;
	double termino,productoria,valorPI,errorCalculado;
	
	printf("Ingrese la cantidad de t�rminos: ");
	scanf("%d",&cantTerminos);
	if (cantTerminos>0){
		i = 1;
		productoria = 1;
		while (i<=cantTerminos){
			termino = pow(4*i,2)/((4*i-1)*(4*i+1));
			productoria *= termino;
			i++;
		}		
		valorPI = productoria*2*sqrt(2);
		errorCalculado = fabs(valorPI-PI_REAL);
		printf("El valor calculado de PI a trav�s de la productoria para %d t�rminos es: %lf\n",cantTerminos,valorPI);
		if (errorCalculado<ERROR){
			printf("El error calculado no es considerable (< 0.005): %lf\n",errorCalculado);
		}
		else{
			printf("El error calculado es considerable (< 0.005): %lf\n",errorCalculado);
		}
	}
	else{
		printf("La cantidad de t�rminos debe ser mayor que cero\n");
	}
	
	return 0;
}
