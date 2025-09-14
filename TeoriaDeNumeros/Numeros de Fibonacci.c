#include <stdio.h>
#include <math.h>

void leerDatos(int *, int *);
int obtenerCantFib(int, int);
int numeroFib(int);
int devolverPosicion(int);
int determinarCuadrado(int);
void imprimirCabecera(int);
void imprimirPieGrafica(int, int);
void dibujarBarras(int, int);

int main()
{
	int a, b, cantNumFib = 0;
	leerDatos(&a, &b);
	if ((a >= 0) && (a < b) && (b - a + 1 <= 15))
	{
		cantNumFib = obtenerCantFib(a, b);
		if (cantNumFib >= 1)
		{
			imprimirCabecera(cantNumFib);
			dibujarBarras(a, b);
			imprimirPieGrafica(a, b);
		}
		else
		{
			printf("No se encontraron números fibonacci dentro del rango.\n");
		}
	}
	else
	{
		printf("El rango ingresado no es correcto.\n");
	}
	return 0;
}

void leerDatos(int *a, int *b)
{
	printf("Ingrese el inicio del rango(a) : ");
	scanf(" %d", a);
	printf("Ingrese el final del rango(b) : ");
	scanf(" %d", b);
}

int obtenerCantFib(int a, int b)
{
	int i = 0, esFib = 0, contador = 0;
	for (i = a; i <= b; i++)
	{
		esFib = numeroFib(i);
		if (esFib != -1)
		{
			contador++;
		}
	}
	return contador;
}

int numeroFib(int num)
{
	int expresion1, expresion2, esCuadrado;
	expresion1 = 5 * pow(num, 2) + 4;
	expresion2 = 5 * pow(num, 2) - 4;
	esCuadrado = determinarCuadrado(expresion1) || determinarCuadrado(expresion2);
	if (esCuadrado)
	{
		return num;
	}
	return -1;
}

int determinarCuadrado(int num)
{
	int i, j, esCuadrado = 0;
	for (i = 0; i <= num; i++)
	{
		for (j = 2; j <= num / 2; j = j + 2)
		{
			if (pow(i, j) == num)
			{
				esCuadrado = 1;
				return esCuadrado;
			}
		}
	}
	return 0;
}

int devolverPosicion(int num)
{
	int encontrado = 0, i = 2, esFib, posicion, t0 = 0, t1 = 1, tn;
	if (num == 0)
	{
		posicion = 0;
		encontrado = 1;
	}
	else if (num == 1)
	{
		posicion = 1;
		encontrado = 1;
	}
	while (!encontrado)
	{
		tn = t0 + t1;
		t0 = t1;
		t1 = tn;
		if (tn == num)
		{
			posicion = i;
			encontrado = 1;
		}
		i++;
	}
	return posicion;
}

void imprimirCabecera(int final)
{
	int cabeceraFinal, i;
	cabeceraFinal = final + 3; /*porque recorre desde a hasta b+3; es decir b+3 saltos*/
	printf("\nEn la siguiente gráfica se muestran los números fibonacci dentro del rango ingresado :\n\n");
	for (i = 1; i <= cabeceraFinal; i++)
	{
		if (i == cabeceraFinal)
		{
			printf("Fibonacci(n)\n");
		}
		else
		{
			printf("\t");
		}
	}
}

void imprimirPieGrafica(int a, int b)
{
	int i, numFib, pos;
	printf("posición(n) :\t");
	for (i = a; i <= b; i++)
	{
		numFib = numeroFib(i);
		if (numFib != -1)
		{
			pos = devolverPosicion(numFib);
			if (pos == 1)
			{
				printf("1 o 2\t");
			}
			else
			{
				printf(" %d\t", pos);
			}
		}
	}
}

void dibujarBarras(int a, int b)
{
	int i, filas = 1, enBlanco, j, altura, k, numFib;
	for (i = a; i <= b; i++)
	{
		altura = numeroFib(i);
		if (altura)
		{
			if (altura >= filas)
			{
				filas = altura;
			}
		}
	}
	/*Con el número de filas empezamos a dibujar la gráfica*/
	for (j = 1; j <= filas; j++)
	{
		printf("\t\t");
		for (k = a; k <= b; k++)
		{
			numFib = numeroFib(k);
			if (numFib != -1)
			{
				altura = numeroFib(k);
				enBlanco = filas - altura;
				if (j <= enBlanco)
				{
					printf(" \t");
				}
				else
				{
					printf("|\t");
				}
			}
		}
		printf(" %d\n", filas - j + 1);
	}
}
