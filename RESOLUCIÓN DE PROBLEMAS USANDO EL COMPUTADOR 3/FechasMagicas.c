#include <stdio.h>

void LeerAnhos(int *anhoInicio,int *anhoFin);
int ValidarFechaMagica(int dia,int mes,int anho);
void GenerarSiguienteFechaAEvaluar(int *dia,int *mes,int *anho);		
int VerificarAnhoBisiesto(int anho);

int main(){
	int dia,mes,anho, anhoInicio,anhoFin;
	
	LeerAnhos(&anhoInicio,&anhoFin);
	dia = 1;
	mes = 1;
	anho = anhoInicio;
	
	while (anho<=anhoFin){
		if (ValidarFechaMagica(dia,mes,anho)){
			printf("%d - %d - %d\n",dia,mes,anho);
		}
		GenerarSiguienteFechaAEvaluar(&dia,&mes,&anho);		
	}	
	return 0;
}

void LeerAnhos(int *anhoInicio,int *anhoFin){
	printf("Ingrese año de inicio: ");
	scanf("%d",anhoInicio);
	printf("Ingrese año fin: ");
	scanf("%d",anhoFin);
}
int ValidarFechaMagica(int dia,int mes,int anho){
	return ((dia*mes) == (anho % 100));
}
void GenerarSiguienteFechaAEvaluar(int *dia,int *mes,int *anho){
	int cantMaxDiasXMes;
	/*buscar la cantidad máxima de días por mes, dependiendo del mes*/
	if ((*mes)== 1 || (*mes)== 3 || (*mes)== 5 || (*mes)== 7 || (*mes)== 8 || (*mes)== 10 || (*mes)== 12){
		cantMaxDiasXMes = 31;
	}
	else if ((*mes)== 4 || (*mes)== 6 || (*mes)== 9 || (*mes)== 11){
		cantMaxDiasXMes = 30;
	} /*evaluar febrero y si es bisiesto*/
	else if (VerificarAnhoBisiesto(*anho)){
		cantMaxDiasXMes = 29;
	}
	else{
		cantMaxDiasXMes = 28;
	}
	/*pasar al siguiente día*/
	(*dia)++;
	if ((*dia)>cantMaxDiasXMes){ /* si pasó la máxima cantidad de días del mes, reinicia el día y agrega el mes*/
		*dia = 1;
		(*mes)++;
		if ((*mes)>12){/*si pasó el mes a 13 , reinicia el mes y agrega el año*/
			*mes = 1;
			(*anho)++;
		}
	}
}

int VerificarAnhoBisiesto(int anho){
	return ((anho % 4)==0 && (anho%400)==0 || (anho %100 !=0));
}









