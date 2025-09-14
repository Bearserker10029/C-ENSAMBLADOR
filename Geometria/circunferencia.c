#include <stdio.h>
#include <math.h>
#define PI 3.1415

int main()
{

	/*Declaracion de variables*/
	int cant_puntos_procesar, punto = 1, cant_puntos_pertenecen = 0, cant_puntos_no_pertenecen = 0;
	double x1, y1, x2, y2, xr, yr, radio, area, xz, yz, diferencia_radios, radio_z, x_mayor = 0, y_xmayor;

	/*Lectura de las coordenadas de los puntos P y Q*/
	printf("Ingrese las coordenadas del punto P: \n");
	scanf("%lf %lf", &x1, &y1);

	printf("Ingrese las coordenadas del punto Q: \n");
	scanf("%lf %lf", &x2, &y2);

	/*Calculo de las coordenadas del centro C*/
	xr = (x1 + x2) / 2;
	yr = (y1 + y2) / 2;
	printf("El centro de la circunferencia formado por el punto medio de P(%.6lf,%.3lf) y Q(%.3lf,%.3lf) es (%.3lf,%.3lf)\n", x1, y1, x2, y2, xr, yr);

	/*Calculo del radio de la circunferencia*/
	radio = sqrt(pow(xr - x1, 2) + pow(yr - y1, 2));
	printf("El radio de la circunferencia al cual pertenecen los puntos P(%.3lf,%.3lf) y Q(%.3lf,%.3lf) es %.3lf\n", x1, y1, x2, y2, radio);

	/*Calculo del area de la circunferencia*/
	area = PI * pow(radio, 2);
	printf("El area de la circunferencia al cual pertenecen los puntos P(%.3lf,%.3lf) y Q(%.3lf,%.3lf) es %.3lf\n", x1, y1, x2, y2, area);

	/*Lectura de la cantidad de puntos a procesar*/
	printf("Ingrese la cantidad de puntos a procesar: \n");
	scanf("%d", &cant_puntos_procesar);

	/*Construccion de la iterativa para cada punto a procesar*/
	while (punto <= cant_puntos_procesar)
	{

		/*Lectura de las coordenadas del punto Z*/
		printf("Ingrese las coordenadas del punto Z: \n");
		scanf("%lf %lf", &xz, &yz);

		/*Calculo del radio del punto Z al centro C de la circunferencia*/
		radio_z = sqrt(pow(xr - xz, 2) + pow(yr - yz, 2));
		printf("El radio es %.6lf\n", radio_z);

		/*Calculo del valor absoluto de la diferencia de radios*/
		diferencia_radios = fabs(radio - radio_z);

		/*Evaluacion de la pertenencia del punto Z a la circunferencia*/
		if (diferencia_radios <= 0.01)
		{
			/*Impresion de la pertenencia del punto Z a la circunferencia*/
			printf("El punto Z(%.3lf,%.3lf) pertenece a la circunferencia con centro C(%.3lf,%.3lf) y radio %.3lf\n", xz, yz, xr, yr, radio);
			/*Actualizacion del contador del numero de puntos que pertenecen a la circunferencia*/
			cant_puntos_pertenecen++;
		}
		else
		{
			/*Impresion de la no pertenencia del punto Z a la circunferencia*/
			printf("El punto Z(%.3lf,%.3lf) NO pertenece a la circunferencia con centro C(%.3lf,%.3lf) y radio %.3lf\n", xz, yz, xr, yr, radio);
			/*Actualizacion del contador del numero de puntos que no pertenecen a la circunferencia*/
			cant_puntos_no_pertenecen++;
		}

		/*Actualizacion de x mayor y su respectiva abscisa*/
		if (xz >= x_mayor)
		{
			x_mayor = xz;
			y_xmayor = yz;
		}

		/*Actualizacion del punto a evaluar para evitar bucles infinitos*/
		punto++;
	}

	/*Impresion de la cantidad de puntos pertenecientes a la circunferencia*/
	printf("La cantidad de puntos que pertenecen a la circunferencia fue: %d\n", cant_puntos_pertenecen);
	/*Evaluacion de la existencia de puntos pertenecientes a la circunferencia para imprimir el x mayor*/
	if (cant_puntos_pertenecen > 0)
	{
		printf("Las coordenadas del punto que pertenece a la circunferencia con mayor coordenada x fue (%.3lf,%.3lf)\n", x_mayor, y_xmayor);
	}
	/*Impresion de la cantidad de puntos no pertenecientes a la circunferencia*/
	printf("La cantidad de puntos que no pertenecen a la circunferencia fue: %d\n", cant_puntos_no_pertenecen);

	return 0;
}
