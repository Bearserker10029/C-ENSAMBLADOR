#include <stdio.h>
#include <math.h> // Para fabs()

// --- Prototipos de Módulos ---

double obtener_orientacion(double p1x, double p1y, double p2x, double p2y, double p3x, double p3y);
int validar_alineacion(double ax, double ay, double bx, double by, double cx, double cy);

// --- Módulo Principal ---
int main()
{
	int num_puntos;
	int i;
	int dentro_count = 0;
	int fuera_count = 0;

	// 1. Leer y validar la cantidad de puntos
	printf("Ingrese la cantidad de puntos, debe ser un múltiplo de 4 y encontrarse en el rango [4, 32]: ");
	scanf("%d", &num_puntos);

	if (num_puntos < 4 || num_puntos > 32 || num_puntos % 4 != 0)
	{
		printf("El valor ingresado no cumple con lo solicitado\n");
		return 1;
	}

	// 2. Iterar para cada grupo de 4 puntos
	for (i = 0; i < num_puntos / 4; i++)
	{
		double ax, ay, bx, by, cx, cy, px, py;

		printf("Ingrese el punto A: ");
		scanf("%lf %lf", &ax, &ay);
		printf("Ingrese el punto B: ");
		scanf("%lf %lf", &bx, &by);
		printf("Ingrese el punto C: ");
		scanf("%lf %lf", &cx, &cy);
		printf("Ingrese el punto P: ");
		scanf("%lf %lf", &px, &py);

		if (validar_alineacion(ax, ay, bx, by, cx, cy))
		{
			printf("Los puntos están alineados, no forman un triángulo\n");
			fuera_count++;
		}
		else
		{
			double orientacion_triangulo = obtener_orientacion(ax, ay, bx, by, cx, cy);
			double orient1 = obtener_orientacion(ax, ay, bx, by, px, py);
			double orient2 = obtener_orientacion(bx, by, cx, cy, px, py);
			double orient3 = obtener_orientacion(cx, cy, ax, ay, px, py);

			int is_inside = 0;
			if (fabs(orient1) > 1e-9 && fabs(orient2) > 1e-9 && fabs(orient3) > 1e-9)
			{
				if ((orientacion_triangulo > 0 && (orient1 > 0 && orient2 > 0 && orient3 > 0)) ||
					(orientacion_triangulo < 0 && (orient1 < 0 && orient2 < 0 && orient3 < 0)))
				{
					is_inside = 1;
				}
			}

			if (is_inside)
			{
				dentro_count++;
				printf("El punto P(%.2f,%.2f) se encuentra dentro del triángulo formado por los puntos A(%.2f,%.2f) B(%.2f,%.2f) C(%.2f,%.2f)\n", px, py, ax, ay, bx, by, cx, cy);
			}
			else
			{
				fuera_count++;
				printf("El punto P(%.2f,%.2f) se encuentra fuera del triángulo formado por los puntos A(%.2f,%.2f) B(%.2f,%.2f) C(%.2f,%.2f)\n", px, py, ax, ay, bx, by, cx, cy);
			}
		}
	}

	// 5. Mostrar el resultado final con el nuevo formato
	printf("\nLos puntos que se encontraron dentro de un triángulo son: %d\n", dentro_count);
	printf("Los puntos que se encontraron fuera de un triángulo son: %d\n", fuera_count);

	return 0;
}

double obtener_orientacion(double p1x, double p1y, double p2x, double p2y, double p3x, double p3y)
{
	return (p2y - p1y) * (p3x - p2x) - (p2x - p1x) * (p3y - p2y);
}

int validar_alineacion(double ax, double ay, double bx, double by, double cx, double cy)
{
	double orientacion = obtener_orientacion(ax, ay, bx, by, cx, cy);
	if (fabs(orientacion) < 1e-9)
	{
		return 1;
	}
	return 0;
}
