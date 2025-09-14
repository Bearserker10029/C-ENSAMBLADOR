#include <stdio.h>
#include <math.h>

int main()
{
	// Variables
	int num_lados, num_punto;
	double perimetro, lado, xp, yp, x, y, xt, yt;
	num_punto = 1;
	perimetro = 0;

	// Ingresar el numero de lados
	printf("Ingrese el numero de lados del poligono:");
	scanf(" %d", &num_lados);

	// El numero de lados debe ser mayor o igual a 3 para ser poligono
	if (num_lados >= 3)
	{

		// Mientras el numero del punto sea menor que el numero de lados, ejecutar el sgte bucle
		while (num_punto <= num_lados)
		{
			printf("Ingrese el punto %d (x,y): ", num_punto);
			scanf(" %lf %lf", &x, &y);

			if (num_punto == 1)
			{
				xt = x;
				yt = y;
				xp = x;
				yp = y;
			}

			if (num_punto == num_lados)
			{
				lado = sqrt(pow(xp - x, 2) + pow(yp - y, 2));
				// Formula de perimetro
				perimetro = perimetro + lado;
			}

			// El punto debe ser del 1er y 2do cuadrante
			if (y < 0)
			{
				printf("El punto ingresado no pertenece al primer ni al segundo cuadrante.\n");
			}
			else
			{
				lado = sqrt(pow(xt - x, 2) + pow(yt - y, 2));
				perimetro = perimetro + lado;
				xt = x;
				yt = y;
				// el numero de punto se aumenta en 1 por cada interaccion
				num_punto++;
			}
		}
	}

	// Mostrar resultado del perimetro
	printf("El perimetro del poligono de %d lados es: %lf", num_lados, perimetro);
	return 0;
}
