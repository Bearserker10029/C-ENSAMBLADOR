#include <stdio.h>

// Funcion para calcular el MCD usando el algoritmo de Euclides
int calcularMCD(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Funcion para calcular el MCM usando el MCD
int calcularMCM(int a, int b)
{
    return (a * b) / calcularMCD(a, b);
}

int main()
{
    int num1, num2;
    int opcion;

    do
    {
        // Solicitar al usuario que ingrese dos numeros
        printf("Ingrese el primer numero: ");
        scanf("%d", &num1);

        printf("Ingrese el segundo numero: ");
        scanf("%d", &num2);

        // Solicitar al usuario que elija que calcular
        printf("Que desea calcular?\n");
        printf("1. MCD\n");
        printf("2. MCM\n");
        printf("3. Ambos\n");
        printf("4. Salir\n");
        scanf("%d", &opcion);

        // Calcular y mostrar segun la eleccion del usuario
        switch (opcion)
        {
        case 1:
            printf("El MCD de %d y %d es: %d\n", num1, num2, calcularMCD(num1, num2));
            break;
        case 2:
            printf("El MCM de %d y %d es: %d\n", num1, num2, calcularMCM(num1, num2));
            break;
        case 3:
            printf("El MCD de %d y %d es: %d\n", num1, num2, calcularMCD(num1, num2));
            printf("El MCM de %d y %d es: %d\n", num1, num2, calcularMCM(num1, num2));
            break;
        case 4:
            printf("Saliendo del programa.\n");
            break;
        default:
            printf("Opcion no valida\n");
        }

    } while (opcion != 4);

    return 0;
}
