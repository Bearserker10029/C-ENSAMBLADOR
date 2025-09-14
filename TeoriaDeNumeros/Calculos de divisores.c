#include <stdio.h>

int main()
{
    int a, b, num, numMayor, i, cantDivComunes, suma;
    double promedio;

    printf("Ingrese los dos numeros a evaluar: ");
    scanf(" %d %d", &a, &b);

    /*buscar el menor de ambos para trabajar con sus divisores*/
    if (a < b)
    {
        num = a;
        numMayor = b;
    }
    else
    {
        num = b;
        numMayor = a;
    }
    /*buscar el menor divisor de ambos nu ́meros que no incluya a 1*/
    i = 2;
    cantDivComunes = 0;
    suma = 0;
    while (i < num)
    {
        if ((num % i) == 0 && (numMayor % i) == 0)
        {
            suma += i;
            cantDivComunes++;
        }
        i++;
    }
    if (cantDivComunes != 0)
    {
        promedio = (double)suma / cantDivComunes;
        printf("La suma de divisores comunes entre los dos numeros es: %d\n", suma);
        printf("El promedio de divisores comunes entre los dos numeros es: %.2lf\n", promedio);
    }
    else
    {
        printf("Los numeros ingresados no tienen divisores en comun.");
    }
    return 0;
}