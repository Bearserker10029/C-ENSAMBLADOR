#include <stdio.h>
#include <math.h>

// definir las funciones
int cantdigitos(double);
double sumadigitos(int, double, double *);
void evaluaryimprimir(double, double);

// funcion principal
int main()
{
	int cantdig, resultado;
	double numingresado, suma;
	printf("Ingrese el numero a evaluar: ");
	scanf("%lf", &numingresado);
	cantdig = cantdigitos(numingresado);
	sumadigitos(cantdig, numingresado, &suma);
	evaluaryimprimir(suma, numingresado);
	return 0;
}

// funcion para cantidad digitos
int cantdigitos(double numingresado)
{
	double cantdig;
	cantdig = log10(numingresado) + 1;
	return cantdig;
}

// funcion suma de digitos
double sumadigitos(int cantdig, double numingresado, double *suma)
{
	int i = 0;
	int residuo;
	while (i < cantdig)
	{
		residuo = (int)numingresado % 10;
		numingresado = (int)numingresado / 10;
		*suma += residuo;
		i++;
	}
	return *suma;
}

// evaluar y imprimir
void evaluaryimprimir(double suma, double numingresado)
{
	double resultado, esprimo, contar;
	int j = 1;
	resultado = (int)numingresado / (int)suma;
	contar = 0;
	while (j <= resultado)
	{
		if ((int)resultado % j == 0)
		{
			contar++;
		}
		j++;
	}
	esprimo = contar == 2;
	if (esprimo)
	{
		printf("El numero es Moran \n");
	}
	else
	{
		printf("El numero no es Moran \n");
	}
	printf("La suma de digitos es %.0lf y el resultado de la division es %.0lf", suma, numingresado / suma);
}
