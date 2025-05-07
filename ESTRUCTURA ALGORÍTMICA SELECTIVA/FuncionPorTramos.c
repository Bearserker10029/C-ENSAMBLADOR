#include <stdio.h>
#include <math.h>

int main(){
	double x,fx;
	
	printf("Ingrese el valor de x: ");
	scanf("%lf",&x);
	
	if (x<5){
		fx = pow(x,2);
	}
	else if (x>=5 && x<10){
		fx = pow(x,3) - 1;
	}
	else{
		fx = x/2;
	}
	printf("El valor de fx es %lf\n",fx);
	
	return 0;
}
