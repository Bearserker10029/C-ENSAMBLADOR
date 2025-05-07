#include <stdio.h>

int main(){
	int num,unidad,decena,evaluar10,evaluar100;
	
	printf("Ingrese el número a evaluar: ");
	scanf("%d",&num);
	
	/*Obtener los dígitos del número para hacer las evaluaciones*/
	unidad = num % 10;
	decena = (num % 100) / 10;
	evaluar10 = (unidad==0);
	evaluar100 = (decena ==0 && unidad==0);
	if (evaluar10){
		printf("El número ingresado es múltiplo de 10\n");
	}
	else{
		printf("El número ingresado no es múltiplo de 10\n");
	}
	if (evaluar100){
		printf("El número ingresado es múltiplo de 100\n");
	}
	else{
		printf("El número ingresado no es múltiplo de 100\n");
	}	
	return 0;
}
