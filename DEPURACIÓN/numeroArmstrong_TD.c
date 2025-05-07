#include <stdio.h>
#include <math.h>

int calcularDigitos(int );
int evaluarNumeroArmstrong(int ,int );

int main(){
	int encontrado=0,numero,ndigitos,nuevonumero;
	while (!encontrado){
		printf("Ingrese un numero a evaluar:");
		scanf("%d",&numero);
		if (numero>0){
			ndigitos=calcularDigitos(numero);
			nuevonumero=evaluarNumeroArmstrong(numero,ndigitos);
			if (numero==nuevonumero){
				printf("El numero %d es un numero Armstrong.\n",numero);
				encontrado=1;
			}
			else
				printf("El numero %d NO es un numero Armstrong.\n",numero);
		}		
		else
			printf("Debe ingresar un numero mayor a 0\n");
	}
	return 0;	
}
/* Tabla de datos de main
#iteración	encontrado	numero	ndigitos	nuevonumero
--------------------------------------------------------
	0			0		  N.D.	   N.D.			N.D.
	1			1		  153    	3			153
*/

int calcularDigitos(int num){
	int digitos=0;
	while (num>0){
		num/=10;
		digitos++;
	}
	return digitos;	
}

/*Tabla de datos calcularDigitos(153)
#iteración	num		digitos
---------------------------
   1.0		153		 0
   1.1		15		 1
   1.2      1        2
   1.3		0		 3
*/

int evaluarNumeroArmstrong(int num,int ndigitos){
	int nuevonum=0,digito;
	while (num>0){
		digito=num %10;
		num/=10;
		nuevonum+=pow(digito,ndigitos);
	}
	return nuevonum;	
}
/*Tabla de datos de evaluarNumeroArmstrong(153,3)
#iteración	num		ndigitos	nuevonum	digito
--------------------------------------------------
   1.0	    153 		3			0		  N.D.
   1.1		15			3			27		   3
   1.2		1			3			152		   5
   1.3		0			3			153		   1
*/



