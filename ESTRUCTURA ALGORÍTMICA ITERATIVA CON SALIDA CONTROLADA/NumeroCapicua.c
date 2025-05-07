#include <stdio.h>

int main(){
	int num, numOriginal,numInvertido,i,digMayor,digMenor,centinela;
	int digito, contVecesDigMayor,contVecesDigMenor;
	
	printf("Número a evaluar: ");
	scanf("%d",&num);
	
	numInvertido = 0;
	numOriginal = num;
	i = 0;
	digMayor = -1;
	digMenor = 10;
	centinela = 1;
	
	do{
		i++;
		digito = num%10;
		num = num/10; 
		numInvertido = numInvertido*10+digito;
		/*buscar cuál es el dígito mayor del número*/
		if (digito>digMayor){
			digMayor = digito;
		}
		/*buscar cuál es el dígito menor del número*/
		if (digito<digMenor){
			digMenor = digito;
		}	
		if (num==0){
			centinela=0;
		}			
	}while(centinela);
	printf("El número invertido es: %d\n",numInvertido);
	
	if (numOriginal==numInvertido){
		printf("El número %d es capicúa.\n",numOriginal);
		num = numOriginal;
		contVecesDigMayor = 0;
		contVecesDigMenor = 0;
		do{
			digito = num % 10;
			num = num/10;
			if (digito==digMayor){
				contVecesDigMayor++;
			}
			if (digito==digMenor){
				contVecesDigMenor++;
			}
		}while (num>0);
		printf("El dígito mayor es %d y aparece %d veces\n",digMayor,contVecesDigMayor);
		printf("El dígito menor es %d y aparece %d veces\n",digMenor,contVecesDigMenor);
	}
	else{
		printf("El número %d no es capicúa.\n",numOriginal);
	}	
	return 0;
}
