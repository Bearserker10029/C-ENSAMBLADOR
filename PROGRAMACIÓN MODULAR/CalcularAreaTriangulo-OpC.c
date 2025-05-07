#include <stdio.h>
#include <math.h>

/*prototipos*/
void LeerDatosEntrada(double *lado1,double *lado2,double *lado3);
int ValidarPropiedadTriangulo(double lado1,double lado2,double lado3);
void CalcularAreaYSemiperimetro(double lado1,double lado2,double lado3,double *area,double *semiperimetro);
void MostrarSemiperimetroYArea(double semiperimetro,double area);

int main(){
	double lado1,lado2,lado3,semiperimetro,area;
	int ladosValidos;
	
	LeerDatosEntrada(&lado1,&lado2,&lado3);
	ladosValidos = ValidarPropiedadTriangulo(lado1,lado2,lado3);
	
	if (ladosValidos){
		CalcularAreaYSemiperimetro(lado1,lado2,lado3,&area,&semiperimetro);
		MostrarSemiperimetroYArea(semiperimetro,area);
	}
	else{
		printf("Los lados ingresados no cumplen la propiedad del tri�ngulo\n");
	}
	return 0;
}
void LeerDatosEntrada(double *lado1,double *lado2,double *lado3){
	printf("Ingrese los lados: ");
	scanf("%lf %lf %lf",lado1,lado2,lado3);
}

int ValidarPropiedadTriangulo(double lado1,double lado2,double lado3){
	return (((lado1+lado2)>lado3) && ((lado1+lado3)>lado2) && ((lado2+lado3)>lado1) && (lado1>0) && (lado2>0) && (lado3>0));
}

void CalcularAreaYSemiperimetro(double lado1,double lado2,double lado3,double *area,double *semiperimetro){
	*semiperimetro = ((lado1+lado2+lado3)/2);
	*area = sqrt(*semiperimetro*(*semiperimetro-lado1)*(*semiperimetro-lado2)*(*semiperimetro-lado3));
}

void MostrarSemiperimetroYArea(double semiperimetro,double area){
	printf("El semiper�metro del tri�ngulo es: %lf\n",semiperimetro);
	printf("El �rea del tri�ngulo es: %lf\n",area);
}


