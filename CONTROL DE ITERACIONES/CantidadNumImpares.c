#include <stdio.h>

int main(){
	int esImpar,contImpares,num;
	
	esImpar = 1;
	contImpares = 0;
	while (esImpar){
		printf("Ingrese el n�mero impar: ");
		scanf("%d",&num);
		/*validar que el n�mero sea impar */
		if ((num % 2) == 1){
			contImpares++;
		}
		else{
			esImpar = 0;
		}
	}
	printf("La cantidad de n�meros impares le�dos es: %d\n",contImpares);
	
	return 0;
}
