#include <stdio.h>
#include <math.h>
#define PI 3.1416
void leerDatosSumatoria1(double *, double *, double *);
void leerDatosSumatoria2(double *, int *);
double calcularSumatoria1(double, double, int);
double calcularSumatoria2(double, int);
int main()
{
    char opcion;
    double a, b, c, d, sumatoria;
    int n, validarA, validarB, validarAB, validarN;
    printf("Ingrese la sumatoria que desea calcular:\n");
    printf("Sumatoria 1 (A o a)\n");
    printf("Sumatoria 2 (B o b)\n");
    scanf(" %c", &opcion);
    if (opcion == "A" || opcion == "a" || opcion == "B" || opcion == "b")
    {
        if (opcion == "A" || opcion == "a")
        {
            /*Sumatoria 1*/
            leerDatosSumatoria1(&a, &b, &n);
            if (n >= 1 && n <= 10)
            {
                /*a entre 4 y 10 b entre 2 y 8 con a>b*/
                validarA = (a >= 2 && a <= 6);
                validarB = (b >= 1 && b <= 5);
                validarAB = (a > b);
                if (validarA && validarB && validarAB)
                {
                    // resolver sumatoria
                    sumatoria = calcularSumatoria1(a, b, n);
                    printf("El resultado de la sumatoria \" %c\" es: %lf\n", opcion, sumatoria);
                }
                else if (!validarA && validarB && validarAB)
                {
                    /*a no esta ́ en el rango*/
                    printf("el valor de a no se encuentra dentro del rango solicitado.\n");
                }
                else if (validarA && !validarB && validarAB)
                {
                    /*b no esta ́ en el rango*/
                    printf("el valor de b no se encuentra dentro del rango solicitado.\n");
                }
                else if (validarA && validarB && !validarAB)
                {
                    /*a no es mayor que b*/
                    printf("el valor de a debe ser mayor que el de b.\n");
                }
                else if (!validarA && !validarB && validarAB)
                {
                    /*a no esta ́ en el rango y b no esta ́ en el rango*/
                    printf("Los valores de a y b no se encuentran en el rango solicitado.\n");
                }
                else if (!validarA && validarB && !validarAB)
                {
                    /*a no esta ́ en el rango y a no es mayor que b*/
                    printf("El valor de a no se encuentra en el rango solicitado y no es mayor que b.\n"

                    );
                }
                else if (validarA && !validarB && !validarAB)
                {
                    /*b no esta ́ en el rango y a no es mayor que b*/
                    printf("El valor de b no se encuentra en el rango solicitado y a no es mayor que b.\n");
                }
                else
                {
                    /*ninguno cumple*/
                    printf("Lo valores no se encuentran dentro del rango solicitado.\n");
                }
            }
            else
            {
                printf("La cantidad de te ́rminos debe estar entre 1 y 10.\n");
            }
        }
        else
        {
            /*Sumatoria 2*/
            leerDatosSumatoria2(&a, &n);
            validarN = (n >= 1 && n <= 20);
            validarA = (a >= 1 && a <= 3);
            if (validarN && validarA)
            {
                /*Calcular sumatoria*/
                sumatoria = calcularSumatoria2(a, n);
                printf("El resultado de la sumatoria \" %c\" es: %lf\n", opcion, sumatoria);
            }
            else if (!validarA && validarN)
            {
                printf("El valor de a no se encuentra en el rango solicitado.\n");
            }
            else if (validarA && !validarN)
            {
                printf("La cantidad de te ́rminos debe estar entre 1 y 20.\n");
            }
            else
            {
                /*ninguno caso cumple*/
                printf("El valor de a y n no se encuentran dentro del rango solicitado.\n");
            }
        }
    }
    else
    {
        printf("Error en la opcio ́n ingresada.\n");
    }
    return 0;
}
void leerDatosSumatoria1(double *a, double *b, double *n)
{
    printf("Ingrese el valor n:\n");
    scanf(" %d", n);
    printf("Ingrese los valores de a y b:\n");
    scanf(" %lf %lf", a, b);
}
void leerDatosSumatoria2(double *a, int *n)
{
    printf("Ingrese los valores de a y n:\n");
    scanf(" %lf %d", a, n);
}
double calcularSumatoria1(double a, double b, int n)
{
    int j = 0, factorialPares = 1, factorialImpares = 1;
    double termino1, termino2, sumatoria = 0, numerador1, denominador1, numerador2, denominador2;
    while (j <= n)
    {
        if (j == 0)
        {
            numerador1 = a * b * PI;
            denominador1 = 2 * (a - b);
            numerador2 = 4 * b * a;
            denominador2 = a - b;
        }
        else
        {
            numerador1 = pow(PI * a, 2 * j) * pow(a, j) * pow(b, j + 1);
            factorialImpares = (2 * j + 1) * (2 * j) * factorialImpares;
            denominador1 = pow(2, 2 * j) * (a - b) * factorialImpares;
            numerador2 = 4 * pow(b, 2 * j + 1) * a;
            factorialPares = (2 * j) * (2 * j - 1) * factorialPares;
            denominador2 = (a - b) * factorialPares;
        }
        termino1 = numerador1 / denominador1;
        termino2 = numerador2 / denominador2;
        sumatoria = sumatoria + termino1 + termino2;
        j++;
    }
    return sumatoria;
}
double calcularSumatoria2(double a, int n)
{
    int j = 1, factorial = 1, factorialPares = 1;
    double termino, numerador = a, denominador = 1, sumatoria = a;
    while (j <= n)
    {
        factorial = j * factorial;
        factorialPares = (2 * j) * (2 * j - 1) * factorialPares;
        numerador = factorialPares * pow(a, 2 * j + 1);
        denominador = pow(4, j) * pow(factorial, 2) * (2 * j + 1);
        termino = numerador / denominador;
        printf("sumatoria 1: %lf\n", sumatoria);
        sumatoria = sumatoria + termino;
        j++;
    }
    return sumatoria;
}