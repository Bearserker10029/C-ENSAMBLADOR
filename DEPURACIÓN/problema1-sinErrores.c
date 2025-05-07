#include <stdio.h>
#include <math.h>

int calcularSumatoriaPotencias(int );
int sumarPotencias(int );

int main(){
	int numero=1,sumaPotencias,sumaFormula;
	while(numero>0){
		printf("Ingrese un n√∫mero mayor a 0:");
		scanf("%d",&numero);
		if (numero>0){
			sumaFormula=calcularSumatoriaPotencias(numero);
			sumaPotencias=sumarPotencias(numero);			
			printf("Resultado de la suma de potencias: %d\n",sumaFormula);
			printf("Resultado al usar la f√≥rmula: %d\n",sumaPotencias);
			if (sumaPotencias==sumaFormula){
				printf("Se comprueba que sumar las potencias individualmente es igual que utilizar la f√≥rmula\n\n");
			}
			else{
				printf("Error al comprobar la f√≥rmula\n\n");
			}					
		}			
	}	
}
/* Tabla de datos del main
# iteraciÛn		numero	sumaPotencias	sumaFormula
----------------------------------------------------
	0			  1			N.D.			N.D.
	1			  2			17				17

*/

int calcularSumatoriaPotencias(int numero){
	int i,suma=0;
	for (i=1;i<=numero;i++)
		suma=suma+pow(i,4);	
	return suma;
}
/* Tabla de datos de calcularSumatoriaPotencias(2)
#iteraciÛn	numero	i	suma
------------------------------
	1.0		  2	   1     0
	1.1		  2    2	 1
	1.2		  2	   3	 17
*/

int sumarPotencias(int numero){
	int suma;	
	suma=(numero*(numero+1)*(6*pow(numero,3)+9*pow(numero,2)+numero-1))/30;
	return suma;
}

/* Tabla de datos de sumarPotencias(2)
#iteraciÛn	numero	suma
------------------------------
	1.0		  2		 17
*/
