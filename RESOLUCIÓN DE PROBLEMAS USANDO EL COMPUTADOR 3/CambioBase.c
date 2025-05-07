#include <stdio.h>
#include <math.h>

#define DIG_INVALIDO -1
#define DIG_NO_PERTENECE_BASE -2

int ObtenerNumeroBase10(int base, int cantDigitos);
void PasarAMayuscula(char *digito);
int ValidarDigitoNumerico(char digito);
int ValidarDigitoLetra(char digito);
int ValidarDigitoEnBase(int base,char digito);
int ObtenerValorDigitoBase10(char digito);

int main(){
	int base, cantDigitos,numBase10;
	
	printf("Ingrese la base: ");
	scanf("%d",&base);
	printf("Ingrese la cantidad de dígitos: ");
	scanf("%d",&cantDigitos);
	
	/*se creará una función que retorme un valor para que dependiendo de él se envíe el mensaje correspondiente*/
	numBase10 = ObtenerNumeroBase10(base, cantDigitos);
	if (numBase10==DIG_INVALIDO){
		printf("Los dígitos deben estar en el rango [A..Z], [a..z], [0..9]\n");
	} 
	else if (numBase10==DIG_NO_PERTENECE_BASE){
		printf("Ha ingresado un dígito inválido para la base seleccionada\n");
	} 
	else{
		printf("El número en base 10 es %d\n",numBase10);
	}	
	return 0;
}

int ObtenerNumeroBase10(int base, int cantDigitos){
	int i,numeroConvertido,valorDigitoBase10;
	char digito;
	
	i=1;
	numeroConvertido=0;
	while (i<=cantDigitos){
		printf("Ingrese el dígito %d: ",i);
		scanf("\n%c",&digito); /*digito puede ser una letra o número*/	
		/*Se debe pasar a mayúscula los dígitos letra*/
		PasarAMayuscula(&digito);
		if (!ValidarDigitoNumerico(digito) && !ValidarDigitoLetra(digito)){
			return DIG_INVALIDO;
		}	
		if (!ValidarDigitoEnBase(base,digito)){
			return DIG_NO_PERTENECE_BASE;
		}
		valorDigitoBase10 = ObtenerValorDigitoBase10(digito);
		/*se debe formar el número por composición*/
		numeroConvertido += valorDigitoBase10*pow(base,i-1);
		i++;
	}	
	return numeroConvertido;
}

void PasarAMayuscula(char *digito){
	int esMinuscula;
	esMinuscula = (*digito>='a') && (*digito<='z');
	if (esMinuscula){
		*digito = *digito-'a'+'A';
	}
}

int ValidarDigitoNumerico(char digito){
	return (digito>='0' && digito<='9');
}

int ValidarDigitoLetra(char digito){
	return (digito>='A' && digito<='Z');
}

int ValidarDigitoEnBase(int base,char digito){
	int valorDigBase10;
	valorDigBase10 = ObtenerValorDigitoBase10(digito);
	return (valorDigBase10<base);
}

int ObtenerValorDigitoBase10(char digito){
	int valorDigito;
	if (ValidarDigitoNumerico(digito)){
		valorDigito = digito - '0';
	}
	else{
		valorDigito = digito - 'A' + 10;
	}
	return valorDigito;
}



