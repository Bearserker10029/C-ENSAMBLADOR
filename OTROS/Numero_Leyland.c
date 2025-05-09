#include <stdio.h>
#include <math.h>

int main(){
	int num_a, num_b, numero_leyland, calculo_primer_num, calculo_segundo_num, valor1;
	
	printf("Ingrese los numeros a y b: ");
	scanf("%d %d", &num_a, &num_b);
	
	numero_leyland = pow(num_a,num_b) + pow(num_b,num_a);

	calculo_primer_num = pow(num_a,num_b);
	calculo_segundo_num = pow(num_b,num_a);
	
	/*Operaci�n l�gica para verificar si a y b son mayores a 1*/
	valor1 = (num_a>1) && (num_b>1);
	
	printf("Los numeros %d %d que forman el numero Leyland %d = %d + %d, son mayores a 1: %d ", num_a, num_b, numero_leyland, calculo_primer_num, calculo_segundo_num, valor1);
	
	
	return 0;
}
