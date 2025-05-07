#include <stdio.h>

void imprimirFactoresPrimos(int num)
{
    // Imprimir el numero
    printf("Los factores primos de %d son: ", num);

	int primerFactor = 1,i;  // Bandera para evitar imprimir coma antes del primer factor
	
    for ( i = 2; i <= num; i++) {
        while (num % i == 0) {
            if (primerFactor) {
                printf("%d", i);
                primerFactor = 0;
            } else {
                printf(", %d", i);
            }
            num /= i;
        }
    }
    printf("\n");
}

int main()
{
    int numero;
    while (1)
    {
        // Solicitar al usuario que ingrese un número
        printf("Ingrese un numero entero positivo: ");
        scanf("%d", &numero);

        if (numero <= 0)
        {
            printf("Por favor, ingrese un numero entero positivo.\n");
            return 1; // Salir con código de error
        }

        // Imprimir factores primos
        imprimirFactoresPrimos(numero);
    }
    return 0;
}
