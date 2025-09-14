#include <stdio.h>
#include <math.h>
void leerCoeficientes(double *, double *, double *, double *);
void leerIntervalosyn(double *, double *, int *);
double calcularFuncion(double, double, double, double, double);
double calcularRiemann(double, double, double, double, int, double, double);
double hallarTerminosSimpson38(int, double, double, double, double, double, double, int);
double calcularSimpson38(double, double, double, double, int, double, double);
int main()
{
    char opcion;
    double a, b, c, d, inferior, superior, area;
    int n;
    printf("Ingrese la opcio ́n con la que desea calcular el a ́rea de la funcio ́n :\n");
    printf("Suma de Riemann(R o r)\n");
    printf("Regla de Simpson 3 / 8 compuesta(T o t)\n");
    scanf(" % c", &opcion);
    if (opcion == "R" || opcion == "r" || opcion == "T" || opcion == "t")
    {
        leerCoeficientes(&a, &b, &c, &d);
        leerIntervalosyn(&inferior, &superior, &n);
        if (n > 0 && inferior <= superior)
        {
            if (opcion == "R" || opcion == "r")
            {
                /*Riemann*/
                area = calcularRiemann(a, b, c, d, n, inferior, superior);
                printf("El area calculando mediante las sumas de Riemann es : % lf", area);
            }
            else
            {
                /*Simpson 3/8 compuesta*/
                if (n % 3 == 0)
                {
                    area = calcularSimpson38(a, b, c, d, n, inferior, superior);
                    printf("El area calculando mediante la regla de Simpson 3 / 8 compuesta es : % lf", area);
                }
                else
                {
                    printf("Para utilizar la regla de Simpson 3 / 8 compuesta n debe ser mu ́ltiplo de 3.\n");
                }
            }
        }
        else if (n <= 0 && inferior < superior)
        {
            printf("El valor de n debe ser un nu ́mero mayor que 0");
        }
        else if (n > 0 && inferior > superior)
        {
            printf("El valor del límite inferior no puede ser mayor que el superior");
        }
    }
    else
    {
        printf("La opción ingresada no es correcta\n");
    }
    return 0;
}
void leerCoeficientes(double *a, double *b, double *c, double *d)
{
    printf("Ingrese los coeficientes de la funcio ́n(Ax3 + Bx2 + Cx + D) :\n");
    scanf(" % lf % lf % lf % lf", a, b, c, d);
}
void leerIntervalosyn(double *inferior, double *superior, int *n)
{
    printf("Ingrese el limite inferior y superior del intervalo :\n");
    scanf(" % lf % lf", inferior, superior);
    printf("Ingrese la cantidad de subintervalos(n) :\n");
    scanf(" % d", n);
}
double calcularFuncion(double x, double a, double b, double c, double d)
{
    return (a * pow(x, 3)) + (b * pow(x, 2)) + (c * x) + d;
}
double calcularRiemann(double a, double b, double c, double d, int n, double inferior, double superior)
{
    double i;
    double areaTotal, area, deltaX, altura;
    i = inferior;
    deltaX = (superior - inferior) / n;
    while (i <= superior)
    {
        /*altura*/
        altura = calcularFuncion(i, a, b, c, d);
        area = altura * deltaX;
        areaTotal = areaTotal + area;
        i = i + deltaX;
    }
    return areaTotal;
}
double hallarTerminosSimpson38(int j, double a, double b, double c, double d, double x, double h, int n)
{
    double sumatoria = 0, termino;
    int maxN;
    if (j == 1)
    {
        maxN = n - 2;
    }
    else if (j == 2)
    {
        maxN = n - 1;
    }
    else if (j == 3)
    {
        maxN = n - 3;
    }
    while (j <= maxN)
    {
        termino = calcularFuncion(x + j * h, a, b, c, d);
        sumatoria = sumatoria + termino;
        j = j + 3;
    }
    return sumatoria;
}
double calcularSimpson38(double a, double b, double c, double d, int n, double inferior, double superior)
{
    int j = 1;
    double yInicial, yFinal, h, x, areaTotal, sumatoria1, sumatoria2, sumatoria3;
    h = (superior - inferior) / n;
    yInicial = calcularFuncion(inferior, a, b, c, d);
    yFinal = calcularFuncion(superior, a, b, c, d);
    x = inferior;
    sumatoria1 = hallarTerminosSimpson38(1, a, b, c, d, x, h, n);
    sumatoria2 = hallarTerminosSimpson38(2, a, b, c, d, x, h, n);
    sumatoria3 = hallarTerminosSimpson38(3, a, b, c, d, x, h, n);
    areaTotal = (3 * h) / 8 * (yInicial + yFinal + 3 * sumatoria1 + 3 * sumatoria2 + 2 * sumatoria3);
    return areaTotal;
}