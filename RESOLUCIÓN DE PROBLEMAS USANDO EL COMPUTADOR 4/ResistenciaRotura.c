#include <stdio.h>
#include <math.h>

#define PI 3.14159

void LeerRangoResistencias(double *resisMinima,double *resisMaxima);
void CalcularYMostrarValoresReporteResistencia(int cantMezclas,double resisMinima,double resisMaxima);
double CalcularResistencia(double diaSuperior,double diaMedio,double diaInferior,double carga);
int ValidarResistencia(double resistencia,double resisMinima,double resisMaxima);

int main(){
	int fin=0,cantMezclas,opcion;
	double resisMinima,resisMaxima;
	
	while (!fin){
		printf("--------Menú de opciones ------\n");
		printf("1. Para hallar y obtener muestras\n");
		printf("0. Salir\n");
		printf("Opc: ");
		scanf("%d",&opcion);
		if (opcion==1){
			printf("Ingrese la cantidad de mezclas a evaluar: ");
			scanf("%d",&cantMezclas);
			LeerRangoResistencias(&resisMinima,&resisMaxima);
			if (resisMinima<resisMaxima){
				CalcularYMostrarValoresReporteResistencia(cantMezclas,resisMinima,resisMaxima);
			}
			else{
				printf("La resistencia mínima debe ser menor de la resistencia máxima\n");
			}			
		}
		else if (opcion==0){
			fin = 1;
		}
		else{
			printf("Ingrese una opción válida\n");
		}
		printf("********************************\n");
	}	
	return 0;
}

void LeerRangoResistencias(double *resisMinima,double *resisMaxima){
	printf("Ingrese el rango mínimo y máximo de resistencias: ");
	scanf("%lf %lf",resisMinima,resisMaxima);
}
void CalcularYMostrarValoresReporteResistencia(int cantMezclas,double resisMinima,double resisMaxima){
	int i,resistenciaValida,flag=0;
	char idMezcla,idMezclaMin=' ',idMezclaMax=' ';
	double diaSuperior,diaMedio,diaInferior,carga,resistencia,minimo=9999,maximo=0;
	
	for (i=1;i<=cantMezclas;i++){
		printf("-------Mezcla #%d -------\n",i);
		printf("Identificador de la mezcla: ");
		scanf("\n%c",&idMezcla);
		printf("Valores de la Mezcla: ");
		scanf("%lf %lf %lf %lf",&diaSuperior,&diaMedio,&diaInferior,&carga);
		if (diaSuperior>0 && diaMedio>0 && diaInferior>0 && carga>0){
			resistencia = CalcularResistencia(diaSuperior,diaMedio,diaInferior,carga);
			/*se debe validar que la resistencia calculada se encuentre dentro del rango ingresado inicialmente*/
			resistenciaValida = ValidarResistencia(resistencia,resisMinima,resisMaxima);
			if (resistenciaValida){
				flag=1;
				printf("El valor calculado de la resistencia de la mezcla #%d con id %c es: %lf\n",i,idMezcla,resistencia);
				/*debe buscar min y max de resistencias calculadas*/
				if (resistencia<minimo){
					minimo=resistencia;
					idMezclaMin = idMezcla;
				}
				if (resistencia>maximo){
					maximo=resistencia;
					idMezclaMax = idMezcla;
				}
			}
			else{
				printf("El valor calculado de la resistencia de la mezcla #%d no se encuentra dentro del rango establecido: %lf\n",i,resistencia);
			}
		}		
	}
	/*Imprimir el reporte de mínimo y máximo*/
	if (flag){
		printf("--------------------------------\n");
		printf("Mezcla %c con menor MPA %lf\n",idMezclaMin,minimo);
		printf("Mezcla %c con mayor MPA %lf\n",idMezclaMax,maximo);
	}
}

double CalcularResistencia(double diaSuperior,double diaMedio,double diaInferior,double carga){
	double diametroPromedio,areaCompresion;
	diametroPromedio = (diaSuperior+diaMedio+diaInferior)/3;
	areaCompresion = PI*pow(diametroPromedio/2,2);
	return (carga/areaCompresion);
}
int ValidarResistencia(double resistencia,double resisMinima,double resisMaxima){
	return (resistencia>=resisMinima && resistencia<=resisMaxima);
}












