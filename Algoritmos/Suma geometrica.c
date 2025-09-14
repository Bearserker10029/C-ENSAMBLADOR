#include <stdio.h>
#include <math.h>
#define ERROR 0.0001

int main()
{
    double r, suma, sumaFormula, errorCalculado;
    int i, nTerminos;

    printf("Ingrese la cantidad de términos a evaluar: ");
    scanf(" %d", &nTerminos);
    printf("Ingrese el valor de r: ");
    scanf(" %lf", &r);
    i = 1;
    suma = 0;
    while (i <= nTerminos)
    {
        suma = suma + pow(r, i - 1);
        i++;
    }
    sumaFormula = (pow(r, nTerminos) - 1) / (r - 1);
    errorCalculado = abs(suma - sumaFormula);
    printf("Suma en serie: %lf\n", suma);
    printf("Suma aplicando la fórmula: %lf\n", sumaFormula);
    if (errorCalculado <= ERROR)
    {
        printf("Coincide el valor de la serie con el valor de la fórmula\n");
    }
    else
    {
        printf("No coincide el valor de la serie con el valor de la fórmula\n");
    }
    return 0;
}