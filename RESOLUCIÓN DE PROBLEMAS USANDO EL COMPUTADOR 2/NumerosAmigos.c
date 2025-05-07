#include <stdio.h>

void LeerDosNumeros(int *num1,int *num2);
int ValidarNumerosAmigos(int num1,int num2);
int CalcularSumaDivisores(int num);

int main(){
	int num1,num2;	
	
	LeerDosNumeros(&num1,&num2);
	if (ValidarNumerosAmigos(num1,num2)){
		printf("Los números ingresados son amigos\n");
	}
	else{
		printf("Los números ingresados no son amigos");
	}	
	return 0;
}

void LeerDosNumeros(int *num1,int *num2){
	printf("Ingrese los dos números a evaluar: ");
	scanf("%d %d",num1,num2);
}

int ValidarNumerosAmigos(int num1,int num2){
	int sumaNum1,sumaNum2;
	
	sumaNum1 = CalcularSumaDivisores(num1);
	sumaNum2 = CalcularSumaDivisores(num2);
	if (sumaNum1==num2 && sumaNum2==num1){
		return 1;
	}
	else{
		return 0;
	}
}
int CalcularSumaDivisores(int num){
	int i,sumaDivisores;
	i = 1;
	sumaDivisores = 0;
	while (i<num){
		if ((num % i) ==0){
			sumaDivisores += i;
		}
		i++;
	}
	return sumaDivisores;
}






