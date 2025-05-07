#include <stdio.h>
#include <math.h>
int validarDatos(double, int, double);
void calcularRaices(double, int, double, double);
int main()
{
    double x, aproximacion, raizTaylor, raizBakhshali, raizReal, diferenciaTaylor, diferenciaBakhshali;
    int n;
    printf("Ingrese el n�mero para el que se calcular� la ra�z: ");
    scanf("%lf", &x);
    printf("Ingrese la cantidad de t�rminos: ");
    scanf("%d", &n);
    printf("Ingrese la aproximaci�n inicial a la ra�z: ");
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
    printf("Iteraci�n Ra�z_Taylor Ra�z_Bakhshali Mejor m�todo\n");
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
            printf(" M�todo de Bakhshali\n");
        i++;
        factNumerador *= 2 * i * (2 * i - 1);
        factDenominador *= i * i;
        numerador = (pow(-1, i) * factNumerador);
        denominador = ((1 - 2 * i) * factDenominador * pow(4, i));
        termino = (numerador / denominador) * pow(x, i);
        suma += termino;
    }
    printf("El valor real de la ra�z es: %lf\n", raizReal);
    printf("El valor calculado de la ra�z con la Serie de Taylor es: %lf\n", raizTaylor);
    printf("El valor calculado de la ra�z con el M�todo de Bakhshali es: %lf\n", aproximacion);
    if (diferenciaTaylor <= diferenciaBakhshali)
        printf("El c�lculo m�s pr�ximo a la ra�z se encuentra con la Serie de Taylor, la diferencia con el valor real es: %lf\n", diferenciaTaylor);
    else
        printf("El c�lculo m�s pr�ximo a la ra�z se encuentra con el Metodo de Bakhshali, la diferencia con el valor real es: %lf \n", diferenciaBakhshali);
}