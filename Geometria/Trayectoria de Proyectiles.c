#include <stdio.h>
#include <math.h>
#define PI 3.14159

void veloyangulo(int, int, int, int, int);
void mediciones(int, int, int, int);
void datomayor(double, double, double, double, double *, double *, double *, double *, double);

int main()
{
	// definir par�metros
	int cantdisparo, cantmediciones, valido, disparo = 1, angulo, veloinicial;

	// Ingresar datos
	printf("Ingrese el numero de disparos ejecutados:");
	scanf("%d", &cantdisparo);
	printf("Ingrese el numero de mediciones por disparo:");
	scanf("%d", &cantmediciones);

	// Validar datos
	valido = cantdisparo >= 0 && cantmediciones >= 4;
	if (valido)
	{
		while (disparo <= cantdisparo)
		{
			veloyangulo(cantdisparo, disparo, cantmediciones, angulo, veloinicial);
			disparo++;
		}
	}
	if (cantmediciones < 4)
		printf("El numero de mediciones debe ser mayor igual que cuatro (4).");
	if (cantdisparo < 0)
		printf("El numero de disparos debe ser mayor que cero (0).");
	return 0;
}

// modulo hallar velocidad y angulo
void veloyangulo(int cantdisparo, int disparo, int cantmediciones, int angulo, int veloinicial)
{
	int valido = 0, validoangulo = 0;
	do
	{
		printf("Ingrese los datos del disparo numero %d\n", disparo);
		printf("- Angulo (alfa) en grados: ");
		scanf(" %d", &angulo);
		printf("- Velocidad Inicial (Vo) en m/s: ");
		scanf(" %d", &veloinicial);
		validoangulo = (angulo >= 0 && angulo < 90);
		if (veloinicial <= 0)
			printf("Debe ingresar una velocidad inicial mayor que 0\n");
		if (!validoangulo)
			printf("Debe ingresar un angulo mayor que 0 grados y menor que 90 grados.\n");
		valido = validoangulo && veloinicial > 0;
	} while (!valido);
	mediciones(veloinicial, angulo, cantmediciones, disparo);
}

// modulo hallar mediciones
void mediciones(int veloinicial, int angulo, int cantmediciones, int disparo)
{
	int medicion = 1;
	double tiempo = 0, tiempoperiodo = 0, tiempototal = 0, velx = 0, vely = 0, x = 0, y = 0, xante, yante, xmayor, ymayor, tiempoxmayor, tiempoymayor;
	while (medicion <= cantmediciones)
	{
		xante = x;
		yante = y;
		tiempototal = 2 * veloinicial * (sin(angulo * PI / 180) / 9.8);
		tiempoperiodo = tiempototal / cantmediciones;
		tiempo = tiempo + tiempoperiodo;
		velx = veloinicial * (cos(angulo * PI / 180));
		vely = (veloinicial * (sin(angulo * PI / 180))) - (9.8 * tiempo);
		x = velx * tiempo;
		y = (vely * tiempo) + ((9.8 * (pow(tiempo, 2))) / 2);
		datomayor(x, y, xante, yante, &xmayor, &ymayor, &tiempoxmayor, &tiempoymayor, tiempo);
		printf("- %d: Tiempo: %.2lf s, Vx: %.2lf m/s, Vy: %.2lf m/s, X: %.2lf m, Y: %.2lf m \n", medicion, tiempo, velx, vely, x, y);
		medicion++;
	}
	printf("El recorrido horizontal del disparo (Xmax) numero %d fue de %.2lf m y se logro en %.2lf s \nmientras que la altura maxima (Ymax) alcanzada fue de %.2lf m y se logro a los %.2lf s \n", disparo, xmayor, tiempoxmayor, ymayor, tiempoymayor);
}

void datomayor(double x, double y, double xante, double yante, double *xmayor, double *ymayor, double *tiempoxmayor, double *tiempoymayor, double tiempo)
{
	if (x >= xante)
	{
		*xmayor = x;
		*tiempoxmayor = tiempo;
	}
	if (y >= yante)
	{
		*ymayor = y;
		*tiempoymayor = tiempo;
	}
}
