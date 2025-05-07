#include <stdio.h>

int main(){
	int num,contDivisores,i,residuo;
	
	printf("Ingrese un n�mero: ");
	scanf("%d",&num);
	
	/*se calcular� la cantidad total de divisores del num*/
	contDivisores = 0;
	i = 1;
	while (i<=num){
		residuo = num % i;
		if (residuo == 0){
			contDivisores++;
		}
		i++;
	}
	/*Se debe evaluar si el contador de divisores es 2, para determinar si es n�mero primo*/
	if (contDivisores==2){
		printf("El n�mero %d es primo\n",num);
	}
	else{
		printf("El n�mero %d no es primo\n",num);
	}	
	return 0;
}
