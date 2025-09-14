#include <stdio.h>

int main()
{
	int numero1, numero2;
	double resultado;
	char operacion;
	printf("Ingrese dos operandos: \n");
	scanf("%d %d %*c", &numero1, &numero2);
	printf("Ingrese operacion (+,-,*,/): \n");
	scanf("\n%c", &operacion);
	switch (operacion)
	{
	case '+':
		resultado = numero1 + numero2;
		break;
	case '-':
		resultado = numero1 - numero2;
		break;
	case '*':
		resultado = numero1 * numero2;
		break;
	case '/':
		resultado = numero1 / numero2;
		break;
	default:
		printf("Operacion no soportada\n");
	}
	printf("El resultado es: %lf", resultado);
	return 0;
}
