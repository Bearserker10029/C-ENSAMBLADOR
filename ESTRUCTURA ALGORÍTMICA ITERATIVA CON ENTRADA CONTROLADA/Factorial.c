#include <stdio.h>

int main(){
	int n,i,factorial;
	
	printf("Ingrese un número mayor o igual a cero: ");
	scanf("%d",&n);
	
	if (n<0){
		printf("Se ha ingresado un número menor que cero.\n");
	}
	else if (n==0){
		factorial = 1;
		printf("El factorial de %d es %d\n",n,factorial);
	}
	else{
		factorial = 1;
		i = 1;
		while (i<=n){
			factorial *= i; /* factorial = factorial * i; */
			i++;
		}	
		printf("El factorial de %d es %d\n",n,factorial);	
	}
	
	return 0;
}
