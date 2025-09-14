#include <stdio.h>
#include <math.h> //Incluimos este directorio porque usamos "pow"

int main()
{ // definir los formatos de los datos
	double base1, base2, altura1, altura2, Areaprisma1, arealateral1, areabase1, volumen1, Areaprisma2, arealateral2, areabase2, volumen2;
	int numprisma, area2mayorarea1;
	// Introducir los datos requeridos
	printf("Ingrese la base y altura del prisma cuadrangular regular 1: ");
	scanf("%lf %lf", &base1, &altura1);
	printf("Ingrese la base y altura del prisma cuadrangular regular 2: "),
		scanf("%lf %lf", &base2, &altura2);

	// Calculo del area lateral del prisma 1 usando la suma de las cuatro areas rectangulares iguales del prisma
	arealateral1 = 4 * (base1 * altura1);
	// Calculo del area de la base del prisma 1 usando la formula base al cuadrado
	areabase1 = pow(base1, 2);
	// Calculo del area del prisma 1 usando la formula area del prisma= area lateral+ 2* area de la base
	Areaprisma1 = arealateral1 + 2 * areabase1;
	// Calculo del volumen del prisma 1 usando la formula volumen del prisma= area de la base * altura
	volumen1 = areabase1 * altura1;

	// Resultados que se obtuvieron a partir de los calculos
	printf("\n Resultados del Prisma cuadrangular regular 1: ");
	printf("\n Area: %lf", Areaprisma1);
	printf("\n Volumen: %lf\n", volumen1);

	// Calculo del area lateral del prisma 2 usando la suma de las cuatro areas rectangulares iguales del prisma
	arealateral2 = 4 * (base2 * altura2);
	// Calculo del area de la base del prisma 2 usando la formula base al cuadrado
	areabase2 = pow(base2, 2);
	// Calculo del area del prisma 2 usando la formula area del prisma= area lateral+ 2* area de la base
	Areaprisma2 = arealateral2 + 2 * areabase2;
	// Calculo del volumen del prisma 2 usando la formula volumen del prisma= area de la base * altura
	volumen2 = areabase2 * altura2;

	// Resultados que se obtuvieron a partir de los calculos
	printf("\n Resultados del Prisma cuadrangular regular 2: ");
	printf("\n Area: %lf", Areaprisma2);
	printf("\n Volumen: %lf\n", volumen2);

	// Comparar las areas obtenidas
	area2mayorarea1 = Areaprisma2 > Areaprisma1 || Areaprisma2 == Areaprisma1;
	numprisma = area2mayorarea1 + 1;
	printf("El prisma cuadrangular regular %d tiene mayor area", numprisma);

	return 0;
}
