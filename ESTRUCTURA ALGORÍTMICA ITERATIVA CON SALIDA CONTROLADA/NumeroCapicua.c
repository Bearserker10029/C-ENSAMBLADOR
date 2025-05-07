#include <stdio.h>

int main(){
	int num, numOriginal,numInvertido,i,digMayor,digMenor,centinela;
	int digito, contVecesDigMayor,contVecesDigMenor;
	
	printf("N�mero a evaluar: ");
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
		/*buscar cu�l es el d�gito mayor del n�mero*/
		if (digito>digMayor){
			digMayor = digito;
		}
		/*buscar cu�l es el d�gito menor del n�mero*/
		if (digito<digMenor){
			digMenor = digito;
		}	
		if (num==0){
			centinela=0;
		}			
	}while(centinela);
	printf("El n�mero invertido es: %d\n",numInvertido);
	
	if (numOriginal==numInvertido){
		printf("El n�mero %d es capic�a.\n",numOriginal);
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
		printf("El d�gito mayor es %d y aparece %d veces\n",digMayor,contVecesDigMayor);
		printf("El d�gito menor es %d y aparece %d veces\n",digMenor,contVecesDigMenor);
	}
	else{
		printf("El n�mero %d no es capic�a.\n",numOriginal);
	}	
	return 0;
}
