#include <stdio.h>
#include <math.h>  // For sin()
#include <ctype.h> // For tolower()

// Define constants
const double G = 9.81;
const double PI = 3.1415926535;

// Function prototypes
int obtener_datos_prueba(double *masa_A, double *masa_B, double *angulo, int prueba_num);
double calcular_aceleracion(double masa_A, double masa_B, double angulo_rad, double fuerza);
void realizar_pruebas(int num_variaciones);
char preguntar_continuar();

int main()
{
	int num_variaciones;

	do
	{
		printf("Ingrese el numero de variaciones de la fuerza para las pruebas a realizar: ");
		scanf("%d", &num_variaciones);
		if (num_variaciones <= 0)
		{
			printf("El numero de variaciones de la fuerza debe ser mayor que cero. ");
		}
	} while (num_variaciones <= 0);

	realizar_pruebas(num_variaciones);

	return 0; // Success
}

void realizar_pruebas(int num_variaciones)
{
	double masa_A, masa_B, angulo_deg;
	char continuar;
	int prueba_num = 1;
	int i; // Declaration of 'i' moved here for C89 compatibility

	do
	{
		// Get data for the current test, passing the test number
		while (obtener_datos_prueba(&masa_A, &masa_B, &angulo_deg, prueba_num) == 0)
		{
			// Loop until valid data is entered
		}

		double angulo_rad = angulo_deg * PI / 180.0;
		double fuerza = 10.0;
		double aceleracion;

		double fuerza_inicio_movimiento = 0.0;

		printf("Los resultados de un sistema con masas de %g kg y %g kg y un ángulo de %g grados son:\n", masa_A, masa_B, angulo_deg);
		for (i = 0; i < num_variaciones; i++)
		{
			aceleracion = calcular_aceleracion(masa_A, masa_B, angulo_rad, fuerza);

			printf("Con una Fuerza de %.2f N se obtiene una aceleración de %.2f m/s2 el sistema %s.\n",
				   fuerza, aceleracion, (aceleracion > 0) ? "avanza" : "no avanza");

			if (aceleracion > 0 && fuerza_inicio_movimiento == 0.0)
			{
				fuerza_inicio_movimiento = fuerza;
			}

			fuerza += 10.0;
		}

		// Print summary for the test
		if (fuerza_inicio_movimiento == 0.0)
		{
			printf("El sistema no avanzó con ninguna de las fuerzas probadas.\n");
		}
		else if (fuerza_inicio_movimiento == 10.0)
		{
			printf("El sistema avanzó desde la primera fuerza probada.\n");
		}
		else
		{
			printf("El sistema no avanzó inicialmente, pero a partir de una fuerza de %.2f N empezó a avanzar.\n", fuerza_inicio_movimiento);
		}

		continuar = preguntar_continuar();
		prueba_num++;

	} while (continuar == 's');
}

int obtener_datos_prueba(double *masa_A, double *masa_B, double *angulo, int prueba_num)
{
	printf("Ingrese la masa del cuerpo A en kg de la prueba %d: ", prueba_num);
	scanf("%lf", masa_A);
	printf("Ingrese la masa del cuerpo B en kg de la prueba %d: ", prueba_num);
	scanf("%lf", masa_B);
	printf("Ingrese el ángulo de la plataforma en grados de la prueba %d: ", prueba_num);
	scanf("%lf", angulo);

	if (*masa_A <= 0 || *masa_B <= 0 || *angulo <= 0 || *angulo >= 90)
	{
		printf("Las masas deben ser mayor a cero y el ángulo mayor a cero y menor a noventa.\n");
		printf("Ingrese nuevamente la prueba %d.\n", prueba_num);
		return 0; // Invalid data
	}

	return 1; // Valid data
}

double calcular_aceleracion(double masa_A, double masa_B, double angulo_rad, double fuerza)
{
	double numerador = fuerza - G * (masa_A * sin(angulo_rad));
	double denominador = masa_A + masa_B;

	if (denominador == 0)
		return 0;

	return numerador / denominador;
}

char preguntar_continuar()
{
	char respuesta;
	printf("Desea realizar una nueva prueba: (S / N): ");
	scanf(" %c", &respuesta);
	return tolower(respuesta);
}
