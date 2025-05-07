#include <stdio.h>

void EvaluarTipo(int numero,int *emirp,int *pernicioso,int *gapful,int *nBase2,int *cantUnos,int *invertido,int *divisor);
int VerificarPrimo(int numero);
int InvertirNumero(int numero);
void ObtenerPrimerYUltimoDigito(int numero,int *primer,int *ultimo);
void CambiarBaseYContarUnos(int numero,int *cantUnos,int *nBase2);

int main(){
	int continua=1, numero,emirp,pernicioso,gapful,nBase2,cantUnos,invertido,divisor;
	while (continua){ /* while(1) */
		emirp=0;
		pernicioso=0;
		gapful=0;
		nBase2=0;
		cantUnos=0;
		invertido=0;
		divisor=0;
		printf("\nIngrese el número a evaluar: ");
		scanf("%d",&numero);
		if (numero>0){
			EvaluarTipo(numero,&emirp,&pernicioso,&gapful,&nBase2,&cantUnos,&invertido,&divisor);
			if (pernicioso){
				printf("El número es pernicioso porque %d = %d tiene %d unos y %d es primo\n",numero,nBase2,cantUnos,cantUnos);
			}
			if (emirp){
				printf("El número es emirp ya que %d es primo y %d también es primo\n",numero,invertido);
			}
			if (gapful){
				printf("El número es gapful ya que %d es divisible entre %d\n",numero,divisor);
			}
		}
		else{
			if (numero<0){
				printf("Error al ingresar el número\n");
			}
			else{
				continua=0; /*break*/
			}
		}		
	}
	return 0;
}

void EvaluarTipo(int numero,int *emirp,int *pernicioso,int *gapful,int *nBase2,int *cantUnos,int *invertido,int *num){
	int esPrimo,esPrimo2, primer,ultimo;
	*pernicioso=0;
	*gapful=0;
	*emirp=0;
	esPrimo = VerificarPrimo(numero);
	*invertido = InvertirNumero(numero);
	esPrimo2 = VerificarPrimo(*invertido);
	if (esPrimo2 && esPrimo &&numero!=(*invertido)){
		(*emirp)=1;
	}
	ObtenerPrimerYUltimoDigito(numero,&primer,&ultimo);
	(*num)=primer*10+ultimo;
	if ((numero % (*num))==0){
		(*gapful)=1;
	}
	CambiarBaseYContarUnos(numero,cantUnos,nBase2);
	esPrimo=VerificarPrimo(*cantUnos);
	if (esPrimo){
		*pernicioso=1;
	}
}

int VerificarPrimo(int numero){
	int i=1, contDiv=0;
	while (i<=numero){
		if ((numero % i)==0){
			contDiv++;
		}
		i++;
	}
	if (contDiv==2){
		return 1;
	}
	else{
		return 0;
	}
}

int InvertirNumero(int numero){
	int nuevoNum=0, digito;
	while (numero>0){
		digito = numero % 10;
		numero = numero /10;
		nuevoNum = nuevoNum*10+digito;
	}
	return nuevoNum;
}

void ObtenerPrimerYUltimoDigito(int numero,int *primer,int *ultimo){
	*ultimo = numero % 10;
	while (numero>10){
		numero = numero /10;
	}
	*primer=numero;
}

void CambiarBaseYContarUnos(int numero,int *cantUnos,int *nBase2){
	int cont=0,suma=0,digito;
	while (numero>0){
		digito = numero % 2;
		numero = numero/2;
		suma = suma*10 +digito;
		if (digito==1){
			cont++;
		}
	}
	*nBase2 = suma;
	*cantUnos=cont;
}


















