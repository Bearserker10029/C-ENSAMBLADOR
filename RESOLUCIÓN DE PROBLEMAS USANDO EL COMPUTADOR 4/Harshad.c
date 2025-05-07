#include <stdio.h>
#include <math.h>

#define BASE 10

void evaluar_sumatoria_Harshad(int m);	
void calcular_sumatorias(int num,int m,int *sumatoriaAuxiliar,int *sumatoria);
void obtener_e_imprimir_Harshad(int sumatoria,int sumatoriaAuxiliar);

int main(){
	int continuar=1,m;
	
	while (continuar){
		printf("\nIngrese el número de dígitos: ");
		scanf("%d",&m);
		if (m>0){
			printf("Los números de Harshad en base 10 de %d dígitos son (A,X)\n",m);
			evaluar_sumatoria_Harshad(m);			
		}
		else{
			continuar=0;
		}		
	}	
	return 0;
}

void evaluar_sumatoria_Harshad(int m){
	int inicio,fin,num,sumatoria,sumatoriaAuxiliar;
	
	inicio = (int)pow(BASE,m-1); /* si m=1 entonces inicio=1, si m=2 entonces inicio=10*/ 
	fin = (int)pow(BASE,m) - 1; /* si m=1 entonces fin=9, si m=2 entonces fin=99*/
	for(num=inicio;num<=fin;num++){
		calcular_sumatorias(num,m,&sumatoriaAuxiliar,&sumatoria);
		obtener_e_imprimir_Harshad(sumatoria,sumatoriaAuxiliar);
	} 
}

void calcular_sumatorias(int num,int m,int *sumatoriaAuxiliar,int *sumatoria){
	int sumaAux=0, suma=0,i,digito;
	i= 0;
	while (i<=(m-1)){
		digito = num % 10;
		num = num / 10;
		sumaAux = sumaAux + digito;
		suma = suma + digito*pow(BASE,i);
		i++;
	}
	*sumatoriaAuxiliar = sumaAux;
	*sumatoria = suma;
}

/*Tabla de datos calcular_sumatorias(1729,4,*sumatoriaAuxiliar,*sumatoria)
#iteración 	num		m	*sumatoriaAuxiliar	*sumatoria	sumaAux	suma	i	digito
-----------------------------------------------------------------------------------
	1.1.0  1729		4			N.D.		   N.D.		  0		  0		0 	  N.D.
    1.1.1  172		4			N.D.	       N.D.		  9		  9		1	   9 
	1.1.2  17		4			N.D.	       N.D.		  11      29	2	   2 
	1.1.3  1		4			N.D.	       N.D.		  18	  729	3	   7
	1.1.4  0		4			19		       1729		  19	  1729	4	   1
*/

void obtener_e_imprimir_Harshad(int sumatoria,int sumatoriaAuxiliar){
	int A;
	A=1;
	while (A<sumatoria){
		if (sumatoria==A*sumatoriaAuxiliar){
			printf("(%d,%d) ",A,sumatoria);
		}
		A++;
	}
}










