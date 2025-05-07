#include <stdio.h>

int main(){
	double operando1, operando2,resultado;
	char operador;
	int divPorCero;
	
	printf("Ingrese el valor de los operandos: ");
	scanf("%lf %lf",&operando1,&operando2);
	printf("Ingrese el operador: ");
	scanf("\n%c",&operador);
	
	divPorCero = 0;
	if (operador == '+'){
		resultado = operando1 + operando2;
	}
	else if (operador == '-'){
		resultado = operando1 - operando2;
	}
	else if (operador == '*'){
		resultado = operando1 * operando2;
	}
	else if (operador == '/'){
		if (operando2 != 0){
			resultado = operando1 / operando2;
		}
		else{
			divPorCero = 1;
		}
	}
	/*Se debe imprimir el resultado dependiendo de el valor de divPorCero*/
	if (!divPorCero){
		printf("%lf %c %lf = %lf\n",operando1,operador,operando2,resultado);
	}
	else{
		printf("No se puede dividir entre cero.\n");
	}
	
	return 0;
}
