#include <stdio.h>
#include <math.h>

/*prototipos*/
int ValidarPropiedadTriangulo(double lado1,double lado2,double lado3);
double CalcularSemiperimetro(double lado1,double lado2,double lado3);
double CalcularAreaTriangulo(double semiperimetro,double lado1,double lado2,double lado3);

int main(){
	double lado1,lado2,lado3,semiperimetro,area;
	int ladosValidos;
	
	printf("Ingrese los lados: ");
	scanf("%lf %lf %lf",&lado1,&lado2,&lado3);
	
	ladosValidos = ValidarPropiedadTriangulo(lado1,lado2,lado3);
	if (ladosValidos){
		semiperimetro = CalcularSemiperimetro(lado1,lado2,lado3);
		area = CalcularAreaTriangulo(semiperimetro,lado1,lado2,lado3);
		printf("El área del triángulo es: %lf\n",area);
	}
	else{
		printf("Los lados ingresados no cumplen la propiedad del triángulo\n");
	}	
	return 0;
}

int ValidarPropiedadTriangulo(double lado1,double lado2,double lado3){
	return (((lado1+lado2)>lado3) && ((lado1+lado3)>lado2) && ((lado2+lado3)>lado1) && (lado1>0) && (lado2>0) && (lado3>0));
	/*int trianguloValido;
	trianguloValido = ((lado1+lado2)>lado3) && ((lado1+lado3)>lado2) && ((lado2+lado3)>lado1) && (lado1>0) && (lado2>0) && (lado3>0);
	return trianguloValido;*/
}

double CalcularSemiperimetro(double lado1,double lado2,double lado3){
	return ((lado1+lado2+lado3)/2);
}

double CalcularAreaTriangulo(double semiperimetro,double lado1,double lado2,double lado3){
	return (sqrt(semiperimetro*(semiperimetro-lado1)*(semiperimetro-lado2)*(semiperimetro-lado3)));
}
