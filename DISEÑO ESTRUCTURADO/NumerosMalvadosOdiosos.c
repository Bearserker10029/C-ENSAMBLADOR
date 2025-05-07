#include <stdio.h>

int ValidarRango(int inicio,int fin);
void MostrarYCalcularNumerosMalvadosOdiosos(int inicio,int fin);		
int ValidarNumero(int num);
void CalcularPorcentajes(int contMalvados,int contOdiosos,double *porcMalvados,double *porcOdiosos);


int main(){
	int inicio,fin,rangoValido;
	
	printf("Ingrese el rango de n�meros a evaluar: ");
	scanf("%d %d",&inicio,&fin);
	rangoValido = ValidarRango(inicio,fin);
	if (rangoValido){
		MostrarYCalcularNumerosMalvadosOdiosos(inicio,fin);		
	}
	else{
		printf("Los valores ingresados para el rango no son v�lidos\n");
	}
	
	return 0;
}

int ValidarRango(int inicio,int fin){
	return ((inicio>0) && (inicio<fin));
}
void MostrarYCalcularNumerosMalvadosOdiosos(int inicio,int fin){
	int contMalvados, contOdiosos,i, tipoNumero;
	double porcMalvados,porcOdiosos;
	
	contMalvados = 0;
	contOdiosos = 0;
	for(i=inicio;i<=fin;i++){
		tipoNumero = ValidarNumero(i);
		/*tipoNumero=1 para n�mero malvado y tipoNumero=2 para n�mero odioso*/
		if (tipoNumero==1){
			printf("El n�mero %d es un n�mero malvado\n",i);
			contMalvados++;
		}
		else{
			printf("El n�mero %d es un n�mero odioso\n",i);
			contOdiosos++;
		}
	}
	/*se debe calcular y mostrar los porcentajes del reporte*/
	CalcularPorcentajes(contMalvados,contOdiosos,&porcMalvados,&porcOdiosos);
	
	printf("---------Reporte------------------\n");	
	printf("El porcentaje de n�meros malvados es %.2lf\n",porcMalvados);
	printf("El porcentaje de n�meros odiosos es %.2lf\n",porcOdiosos);
}		

int ValidarNumero(int num){
	int contUnos,digito;
	
	contUnos = 0;
	do{
		digito = num % 2;
		num = num / 2;
		if (digito==1){
			contUnos++;
		}		
	}while(num>0);
	
	/*se debe validar el contUnos si es par o impar para saber qu� tipo de n�mero es */
	if ((contUnos % 2)==0){
		return 1;
	}
	else{
		return 2;
	}
}
void CalcularPorcentajes(int contMalvados,int contOdiosos,double *porcMalvados,double *porcOdiosos){
	*porcMalvados = ((double)contMalvados/(contMalvados+contOdiosos))*100;
	*porcOdiosos = 100 - (*porcMalvados);
}



