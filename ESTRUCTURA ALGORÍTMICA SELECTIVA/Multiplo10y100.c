#include <stdio.h>

int main(){
	int num,unidad,decena,evaluar10,evaluar100;
	
	printf("Ingrese el n�mero a evaluar: ");
	scanf("%d",&num);
	
	/*Obtener los d�gitos del n�mero para hacer las evaluaciones*/
	unidad = num % 10;
	decena = (num % 100) / 10;
	evaluar10 = (unidad==0);
	evaluar100 = (decena ==0 && unidad==0);
	if (evaluar10){
		printf("El n�mero ingresado es m�ltiplo de 10\n");
	}
	else{
		printf("El n�mero ingresado no es m�ltiplo de 10\n");
	}
	if (evaluar100){
		printf("El n�mero ingresado es m�ltiplo de 100\n");
	}
	else{
		printf("El n�mero ingresado no es m�ltiplo de 100\n");
	}	
	return 0;
}
