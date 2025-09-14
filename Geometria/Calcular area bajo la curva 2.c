#include <stdio.h>
#include <math.h>

void leerCoeficientes(double *, double *, double *, double *);
void leerIntervalosyn(double *, double *, int *);
double calcularFuncion(double, double, double, double, double);
double calcularSimpson13(double, double, double, double, int, double, double);
double calcularTrapecio(double, double, double, double, int, double, double);

int main()
{
    char opcion;
    double a, b, c, d, inferior, superior, area;
    int n;

    printf("Ingrese la opcion con la que desea calcular el area de la funcion:\n");
    printf("Regla de Simpson 1/3 compuesta (G o g)\n");
    printf("Metodo del trapecio compuesto (S o s)\n");
    scanf(" %c", &opcion);

    if (opcion == 'G' || opcion == 'g' || opcion == 'S' || opcion == 's')
    {
        leerCoeficientes(&a, &b, &c, &d);
        leerIntervalosyn(&inferior, &superior, &n);
        if (n > 0 && inferior <= superior)
        {
            if (opcion == 'G' || opcion == 'g')
            {
                /*Simpson 1/3 compuesta*/
                if (n % 2 == 0)
                {
                    area = calcularSimpson13(a, b, c, d, n, inferior, superior);
                    printf("El area calculando mediante la regla de Simpson 1/3 compuesta es: %lf", area);
                }
                else
                {
                    printf("Para utilizar la regla de Simpson 1/3 compuesta n debe ser múltiplo de 2.\n");
                }
            }
            else
            {
                /*Trapecio*/
                area = calcularTrapecio(a, b, c, d, n, inferior, superior);
                printf("El area calculando mediante el metodo del Trapecio compuesto es: %lf", area);
            }
        }
        else if (n <= 0 && inferior < superior)
        {
            printf("El valor de n debe ser un numero mayor que 0");
        }
        else if (n > 0 && inferior > superior)
        {
            printf("El valor del limite inferior no puede ser mayor que el superior");
        }
    }
    else
    {
        printf("La opcion ingresada no es correcta\n");
    }
    return 0;
}
void leerCoeficientes(double *a, double *b, double *c, double *d)
{
    printf("Ingrese los coeficientes de la funcion (Ax3 + Bx2 + Cx+ D):\n");
    scanf(" %lf %lf %lf %lf", a, b, c, d);
}
void leerIntervalosyn(double *inferior, double *superior, int *n)
{
    printf("Ingrese el limite inferior y superior del intervalo:\n");
    scanf(" %lf %lf", inferior, superior);
    printf("Ingrese la cantidad de subintervalos (n) que realizara el area que desea calcular\n");
    scanf(" %d", n);
}
double calcularFuncion(double x, double a, double b, double c, double d)
{
    return (a * pow(x, 3)) + (b * pow(x, 2)) + (c * x) + d;
}
double calcularSimpson13(double a, double b, double c, double d, int n, double inferior, double superior)
{
    double h, yInicial, yFinal, areaTotal, x, termino, sumatoria = 0, sumaKimpar = 0, sumaKpar = 0;
    int k = 1;
    h = (superior - inferior) / n;
    yInicial = calcularFuncion(inferior, a, b, c, d);
    yFinal = calcularFuncion(superior, a, b, c, d);
    x = inferior + k * h;

    while (k <= n)
    {
        termino = calcularFuncion(x, a, b, c, d);
        if (k % 2 != 0)
        {
            /*posicion impar*/
            sumaKimpar = sumaKimpar + termino;
        }
        else
        {
            /*posicion par*/
            sumaKpar = sumaKpar + termino;
        }
        x = inferior + k * h;
        k++;
    }
    sumatoria = 4 * sumaKimpar + 2 * sumaKpar;
    areaTotal = (yInicial + yFinal + sumatoria) * (h / 3);
    return areaTotal;
}

double calcularTrapecio(double a, double b, double c, double d, int n, double inferior, double superior)
{
    double h;
    double yInicial, yFinal, areaTotal, x, termino, sumatoria;
    int k = 1;

    h = (superior - inferior) / n;
    yInicial = calcularFuncion(inferior, a, b, c, d);
    yFinal = calcularFuncion(superior, a, b, c, d);
    x = inferior + k * h;
    while (k <= n - 1)
    {
        termino = calcularFuncion(x, a, b, c, d);
        sumatoria = sumatoria + termino;
        x = inferior + k * h;
        k++;
    }
    areaTotal = ((yInicial + yFinal) / 2 + sumatoria) * h;
    return areaTotal;
}
