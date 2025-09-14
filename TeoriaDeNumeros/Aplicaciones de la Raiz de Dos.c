#include <stdio.h>
#include <math.h>

double raizdedos(int);

int main()
{
	// definir parametros
	int numint;
	char tipo;
	double resultado, ladomayor, ladomenor, area, longarista, volumen;
	printf("Ingrese el numero de iteraciones para calcular la Raiz de Dos: ");
	scanf("%d", &numint);

	// selectiva para ejecutar cuando las interacciones sean mayor igual a 10
	if (numint >= 10)
	{
		printf("Ingrese el tipo de aplicacion de la Raiz de Dos, (Coseno de 45 grados [C], Rectangulo de Plata [R] o Volumen del Tetraedro [T]): ");
		scanf("\n %c", &tipo);

		// selectiva multiple
		switch (tipo)
		{
		case 'C':
			resultado = 1 / (raizdedos(numint));
			printf("La aproximacion del valor del coseno de 45 grados es %lf", resultado);
			break;
		case 'R':
			printf("Ingrese la longitud del lado menor de un rectangulo de plata: ");
			scanf("%lf", &ladomenor);
			ladomayor = ladomenor * raizdedos(numint);
			area = ladomenor * ladomayor;
			printf("Los lados del rectangulo de plata son %.2lf y %.2lf; y su area es %.2lf", ladomenor, ladomayor, area);
			break;
		case 'T':
			printf("Ingrese la longitud de la arista del tetraedro regular: ");
			scanf("%lf", &longarista);
			volumen = (raizdedos(numint) / 12) * pow(longarista, 3);
			printf("El volumen de un tetraedro regular de arista %.2lf es %.2lf", longarista, volumen);
			break;
		default:
			printf("La aplicacion ingresada no es valida");
		}
	}
	else
		printf("El numero de iteraciones debe ser mayor o igual a 10.");

	return 0;
}

// modulo para calcular raiz de dos
double raizdedos(int numint)
{
	double f = 0;
	int i = 0;
	do
	{
		if (i == 0)
		{
			f = 1;
		}
		f = (f + 2 / f) / 2;
		i++;
	} while (i < numint);
	return f;
}
