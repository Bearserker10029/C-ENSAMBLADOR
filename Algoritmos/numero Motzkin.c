#include <stdio.h>

// Prototipos de las funciones (módulos)
void obtenerYValidarNumero(int *);
double calcularCombinatoria(int, int);
double calcularNumeroMotzkin(int);

/*
 Módulo principal que orquesta la ejecución del programa.
 Contiene el bucle principal para que el usuario realice consultas repetidas.
*/
int main()
{
	int n;
	do
	{
		// Módulo que usa parámetros por referencia para obtener y validar la entrada.
		obtenerYValidarNumero(&n);

		if (n > 1)
		{
			// Módulo que calcula y devuelve el numero de Motzkin.
			double motzkin = calcularNumeroMotzkin(n);
			printf("Para el valor %d es posible dibujar dichos acordes de %.0f formas\n", n, motzkin);
		}
		else if (n != 0)
		{
			printf("El valor ingresado no es mayor a 1\n");
		}

	} while (n != 0);

	printf("Fin del programa.\n");
	return 0;
}

/*
 Módulo 2: obtenerYValidarNumero
 Pide al usuario un numero y lo almacena en la variable pasada por referencia.
 No valida la lógica de negocio (n > 1), solo la entrada.
*/
void obtenerYValidarNumero(int *num)
{
	printf("Ingrese el numero n para calcular Mn: ");
	scanf("%d", num);
}

/*
 Módulo 3: calcularCombinatoria
 Es una función que calcula y devuelve el valor de la combinatoria C(n, k).
 Esencial para el cálculo de los terminos de Motzkin.
 Utiliza un bucle iterativo.
*/
double calcularCombinatoria(int n, int k)
{
	if (k < 0 || k > n)
	{
		return 0;
	}
	if (k == 0 || k == n)
	{
		return 1;
	}
	// Aprovechamos la simetría C(n, k) = C(n, n-k) para optimizar.
	if (k > n / 2)
	{
		k = n - k;
	}
	double res = 1;
	int i;
	// Bucle para calcular la combinatoria de forma eficiente sin usar factoriales grandes.
	for (i = 0; i < k; i++)
	{
		res = res * (n - i) / (i + 1);
	}
	return res;
}

/*
 Módulo 4: calcularNumeroMotzkin
 Calcula el numero de Motzkin para un 'n' dado.
 - Devuelve el valor calculado (double).
 - Usa una iterativa para la sumatoria.
 - Imprime el valor de cada termino en cada iteración.
 - Invoca al módulo calcularCombinatoria, creando así iterativas anidadas.

 =================================================================================
 TABLA DE DATOS PARA n = 8
 ---------------------------------------------------------------------------------
 Módulo: calcularNumeroMotzkin
 Descripción: Calcula el n-esimo numero de Motzkin. Imprime cada termino de la sumatoria.
 Parámetro de entrada (valor): n = 8
 Valor de retorno: motzkin_sum
 Variables locales:
	 k (int): contador del bucle de la sumatoria.
	 termino (double): valor de cada termino de la sumatoria.
	 c1 (double): valor de la combinatoria C(n, 2k).
	 c2 (double): valor de la combinatoria C(2k, k).
	 motzkin_sum (double): acumulador de la suma de los terminos.

 Traza de ejecución:
 -------------------------------------------------------------------------------------------------
 k | n/2 | Condicion k<=n/2 | c1=C(8,2k) | c2=C(2k,k) | termino=c1*c2/(k+1) | motzkin_sum | Salida impresa
 -------------------------------------------------------------------------------------------------
 - | -   | -                | -          | -          | -                     | 0           |
 0 | 4   | V                | C(8,0)=1   | C(0,0)=1   | 1*1/1 = 1             | 1           | Termino 1: 1
 1 | 4   | V                | C(8,2)=28  | C(2,1)=2   | 28*2/2 = 28           | 29          | Termino 2: 28
 2 | 4   | V                | C(8,4)=70  | C(4,2)=6   | 70*6/3 = 140          | 169         | Termino 3: 140
 3 | 4   | V                | C(8,6)=28  | C(6,3)=20  | 28*20/4 = 140         | 309         | Termino 4: 140
 4 | 4   | V                | C(8,8)=1   | C(8,4)=70  | 1*70/5 = 14           | 323         | Termino 5: 14
 5 | 4   | F                | -          | -          | -                     | 323         |
 -------------------------------------------------------------------------------------------------
 Valor de retorno: 323
 =================================================================================
*/
double calcularNumeroMotzkin(int n)
{
	double motzkin_sum = 0;
	int k;
	// Bucle principal para la sumatoria de Motzkin.
	for (k = 0; k <= n / 2; k++)
	{
		// Se invoca a otro módulo dentro del bucle.
		double c1 = calcularCombinatoria(n, 2 * k);
		double c2 = calcularCombinatoria(2 * k, k);

		if ((k + 1) == 0)
			continue; // Evitar división por cero, aunque no debería ocurrir.

		double termino = (c1 * c2) / (k + 1);

		motzkin_sum += termino;

		// Se imprime el valor acumulado en la iteración actual.
		printf("En la iteración %d el termino vale: %.0f\n", k + 1, motzkin_sum);
	}
	return motzkin_sum;
}
