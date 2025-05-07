#include <stdio.h>
#include <math.h>

#define PI 3.1415926536

int main(){
	int cantidad,i,signo;
	double sumatoria,denominador,termino,calculoPi;
	
	printf("Cantidad de términos a evaluar: ");
	scanf("%d",&cantidad);
	if (cantidad<1){
		printf("Error, la cantidad de términos debe ser mayor o igual a 1\n");
	}
	else{
		i=0;
		signo=1;
		sumatoria=0;
		denominador=1;
		do{
			i++;
			termino=signo*(1/denominador);
			sumatoria+=termino;
			denominador+=2;
			signo*=(-1);
		}while(i<cantidad);
		calculoPi = 4*sumatoria;
		printf("Nro de términos\t Resultado aprox de Pi \t Diferencia\n");
		printf("   %d\t\t %.10lf \t\t %.10lf\n",cantidad,calculoPi,fabs(PI-calculoPi));
	}
	
	return 0;
}
