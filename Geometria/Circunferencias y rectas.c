#include <stdio.h>
#include <math.h>
void leerCoeficientes(double *, double *, double *, int);
void obtenerCentroyRadio(double, double, double, double *, double *, double *);
double calcularDistancia(double, double, double, double);
void contarCuadrante(double, double, int *, int *, int *, int *);
void leerCoeficientesRecta(double *, double *, double *, int);
void relacionEntreRectas(double, double, double, double, double, double);
int main()
{
    char opcion;
    int cont = 1, n, noCruce = 0, cruce = 0, cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0;
    double h1, k1, h2, k2, r1, r2, C1, D1, E1, C2, D2, E2, distancia;
    double A1, B1, A2, B2;
    printf("Ingrese la opcion que desea calcular:\n");
    printf("Circunferencias que se cruzan (A o a)\n");
    printf("Relacio ́n entre rectas (B o b)\n");
    scanf(" %c", &opcion);
    if (opcion == 'A' || opcion == 'a' || opcion == 'B' || opcion == 'b')
    {
        if (opcion == 'A' || opcion == 'a')
        {
            /*Opcio ́n 1*/
            printf("Ingrese la cantidad de veces que desea validar si 2 circunferencias de la forma x^2+y^2+Cx+Dy+E se cruzan:");
            scanf(" %d", &n);
            if (n >= 1 && n <= 20)
            {
                while (cont <= n)
                {
                    /*solicitar los coeficientes de las ecuaciones de las circunferencias*/
                    leerCoeficientes(&C1, &D1, &E1, cont);
                    leerCoeficientes(&C2, &D2, &E2, cont + 1);
                    obtenerCentroyRadio(C1, D1, E1, &h1, &k1, &r1);
                    obtenerCentroyRadio(C2, D2, E2, &h2, &k2, &r2);
                    distancia = calcularDistancia(h1, k1, h2, k2);
                    contarCuadrante(h1, k1, &cont1, &cont2, &cont3, &cont4);
                    contarCuadrante(h2, k2, &cont1, &cont2, &cont3, &cont4);
                    if (r1 + r2 < distancia)
                    {
                        printf("Las circunferencias no se cruzan.\n");
                        noCruce++;
                    }
                    else
                    {
                        printf("Las circunferencias se cruzan\n");
                        cruce++;
                    }
                    cont++;
                }
                printf("Se encontraron %d cruces entre circunferencias.\n", cruce);
                printf("En el cuadrante 1 se encontraron %d puntos que son centro de una circunferencia\n", cont1);
                printf("En el cuadrante 2 se encontraron %d puntos que son centro de una circunferencia\n", cont2);
                printf("En el cuadrante 3 se encontraron %d puntos que son centro de una circunferencia\n", cont3);
                printf("En el cuadrante 4 se encontraron %d puntos que son centro de una circunferencia\n", cont4);
            }
            else
            {
                printf("El valor de n no se encuentra dentro del rango solicitado.");
            }
        }
        else
        {
            /*opcion 2*/
            printf("Ingrese la cantidad de veces que desea validar si 2 rectas son secantes, paralelas o coincidentes:");
            scanf(" %d", &n);
            if (n >= 1 && n <= 20)
            {
                while (cont <= n)
                {
                    /*solicitar ingresar los coeficientes de las rectas*/
                    leerCoeficientesRecta(&A1, &B1, &C1, cont);
                    leerCoeficientesRecta(&A2, &B2, &C2, cont + 1);
                    relacionEntreRectas(A1, B1, C1, A2, B2, C2);
                    cont++;
                }
            }
            else
            {
                printf("El valor de n no se encuentra dentro del rango solicitado.");
            }
        }
    }
    else
    {
        printf("Error en la opción ingresada.\n");
    }
    return 0;
}
void leerCoeficientes(double *C, double *D, double *E, int i)
{
    printf("Ingrese los coeficientes C, D y E de la circunferencia %d (x^2+y^2+Cx+Dy+E = 0):", i);
    scanf(" %lf %lf %lf", C, D, E);
}
void obtenerCentroyRadio(double C, double D, double E, double *h, double *k, double *r)
{
    *h = -C / 2;
    *k = -D / 2;
    *r = sqrt(pow(*h, 2) + pow(*k, 2) - E);
}
double calcularDistancia(double h1, double k1, double h2, double k2)
{
    return sqrt(pow(h2 - h1, 2) + pow(k2 - k1, 2));
}
void contarCuadrante(double h, double k, int *cont1, int *cont2, int *cont3, int *cont4)
{
    int cuadrante1, cuadrante2, cuadrante3, cuadrante4;
    cuadrante1 = (h > 0 && k > 0);
    cuadrante2 = (h < 0 && k > 0);
    cuadrante3 = (h < 0 && k < 0);
    cuadrante4 = (h > 0 && k < 0);
    if (cuadrante1)
    {
        (*cont1)++;
    }
    else if (cuadrante2)
    {
        (*cont2)++;
    }
    else if (cuadrante3)
    {
        (*cont3)++;
    }
    else if (cuadrante4)
    {
        (*cont4)++;
    }
}
void leerCoeficientesRecta(double *A, double *B, double *C, int i)
{
    printf("Ingrese los coeficientes A, B y C de la recta %d (Ax + By + C = 0):", i);
    scanf(" %lf %lf %lf", A, B, C);
}
void relacionEntreRectas(double A1, double B1, double C1, double A2, double B2, double C2)
{
    double div1, div2, div3, diferencia1, diferencia2;
    div1 = A1 / A2;
    div2 = B1 / B2;
    div3 = C1 / C2;
    printf("div1: %lf\n", div1);
    printf("div2: %lf\n", div2);
    printf("div3: %lf\n", div3);
    diferencia1 = fabs(div1 - div2);
    diferencia2 = fabs(div2 - div3);
    if (diferencia1 < 0.01 && diferencia2 < 0.01)
    {
        printf("Las rectas son coincidentes.\n");
    }
    else if (diferencia1 < 0.01 && !diferencia2 < 0.01)
    {
        printf("Las rectas son paralelas.\n");
    }
    else
    {
        printf("Las rectas son secantes.\n");
    }
}