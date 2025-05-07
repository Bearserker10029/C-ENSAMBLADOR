#include <stdio.h>

int ValidarNumerYOperacion(int numero,char operacion);
void CalcularValoresDelNumero(int numero,char operacion,int *cantDigitos,int *esPar,int *resultado);

int main(){
	int numero,cantDigitos,esPar,resultado,datosValidos;
	char operacion;
	
	do{
		printf("Ingrese el n�mero a procesar: ");
		scanf("%d",&numero);
		if (numero!=-1){
			printf("Ingrese la operaci�n a realizar: ");
			scanf("\n%c",&operacion);
			datosValidos = ValidarNumerYOperacion(numero,operacion);
			if (datosValidos){
				CalcularValoresDelNumero(numero,operacion,&cantDigitos,&esPar,&resultado);
				printf("El n�mero tiene %d d�gitos\n",cantDigitos);
				if (esPar){
					printf("La cantidad de d�gitos es par\n");
				}
				else{
					printf("La cantidad de d�gitos es impar\n");
				}
				printf("El resultado de la operaci�n con los d�gitos es %d\n",resultado);
			}
			else{
				printf("Existe un error en los datos ingresados.\n");
			}			
		}		
	}while(numero!=-1);
	
	return 0;
}

int ValidarNumerYOperacion(int numero,char operacion){
	return ((numero>0 && numero<1000000) && (operacion=='+'|| operacion=='x'));
}

void CalcularValoresDelNumero(int numero,char operacion,int *cantDigitos,int *esPar,int *resultado){
	int digito;
	
	*cantDigitos = 0;
	if (operacion=='+'){
		*resultado = 0;
	}	
	else{
		*resultado = 1;
	}
	while (numero!=0){
		digito = numero % 10;
		numero = numero / 10;
		if (operacion=='+'){
			*resultado = *resultado + digito;
		}
		else{
			*resultado = *resultado * digito;
		}
		(*cantDigitos)++;
	}
	
	if ((*cantDigitos)%2 == 0){
		*esPar = 1;
	}	
	else{
		*esPar = 0;
	}
}












