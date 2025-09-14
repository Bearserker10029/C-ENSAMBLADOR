#include <stdio.h>
#include <math.h>
int validarDatos(double, int, double);
void calcularRaices(double, int, double, double);
int main()
{
    double x, aproximacion, raizTaylor, raizBakhshali, raizReal, diferenciaTaylor, diferenciaBakhshali;
    int n;
    printf("Ingrese el numero para el que se calculara la raiz: ");
    scanf("%lf", &x);
    printf("Ingrese la cantidad de terminos: ");
    scanf("%d", &n);
    printf("Ingrese la aproximacion inicial a la raiz: ");
    scanf("%lf", &aproximacion);
    if (validarDatos(x, n, aproximacion))
    {
        raizReal = sqrt(x);
        calcularRaices(x, n, aproximacion, raizReal);
    }
    else
    {
        printf("Los datos ingresados no son correctos\n");
    }
    return 0;
}

int validarDatos(double x, int n, double aproximacion)
{
    return x > 0 && x < 1 && n > 0 && n < 10 && aproximacion > 0;
}
void calcularRaices(double x, int n, double aproximacion, double raizReal)
{
    double factNumerador = 1, factDenominador = 1, termino = 1, suma = 1, impar = 1, signo = 1, a, b, numerador, denominador;
    double raizTaylor, diferenciaTaylor, diferenciaBakhshali;
    int i = 0;
    printf("Iteracion Raiz_Taylor Raiz_Bakhshali Mejor metodo\n");
    while (i < n)
    {
        a = (x - pow(aproximacion, 2)) / (2 * aproximacion);
        b = aproximacion + a;
        aproximacion = b - pow(a, 2) / (2 * b);
        raizTaylor = sqrt(pow(suma, 2) - 1);
        printf("%d %lf %lf", i + 1, raizTaylor, aproximacion);
        diferenciaTaylor = fabs(raizTaylor - raizReal);
        diferenciaBakhshali = fabs(aproximacion - raizReal);
        if (diferenciaTaylor <= diferenciaBakhshali)
            printf(" Serie de Taylor\n");
        else
            printf(" Metodo de Bakhshali\n");
        i++;
        factNumerador *= 2 * i * (2 * i - 1);
        factDenominador *= i * i;
        numerador = (pow(-1, i) * factNumerador);
        denominador = ((1 - 2 * i) * factDenominador * pow(4, i));
        termino = (numerador / denominador) * pow(x, i);
        suma += termino;
    }
    printf("El valor real de la raiz es: %lf\n", raizReal);
    printf("El valor calculado de la raiz con la Serie de Taylor es: %lf\n", raizTaylor);
    printf("El valor calculado de la raiz con el Metodo de Bakhshali es: %lf\n", aproximacion);
    if (diferenciaTaylor <= diferenciaBakhshali)
        printf("El calculo mas proximo a la raiz se encuentra con la Serie de Taylor, la diferencia con el valor real es: %lf\n", diferenciaTaylor);
    else
        printf("El calculo mas proximo a la raiz se encuentra con el Metodo de Bakhshali, la diferencia con el valor real es: %lf \n", diferenciaBakhshali);
}