#include <stdio.h>
#include <math.h>
int ExisteotroPrimo(int primo1, int primo2);
void sonprimos(int primo1, int primo2, int *esPrimo1, int *esPrimo2);
int esPrimo(int num);
void sonprimos(int primo1, int primo2, int *esPrimo1, int *esPrimo2);
int main()
{
    char evaluacion;
    double promedio;
    int primo1, equidistante, primo2, esPrimo1, existeotro, esPrimo2;
    printf("Ingrese dos números primos consecutivos: ");
    scanf(" %d %d", &primo1, &primo2);
    sonprimos(primo1, primo2, &esPrimo1, &esPrimo2);
    promedio = (double)(primo1 + primo2) / 2;
    equidistante = fabs(primo1 - promedio) == primo2 - promedio;
    existeotro = ExisteotroPrimo(primo1, primo2);
    if (esPrimo1 && esPrimo2 && equidistante && !existeotro)
    {
        printf("El número es interprimo\n");
    }
    else
    {
        printf("El número no es interprimo\n");
        printf("El número %d es primo %d\n", primo1, esPrimo1);
        printf("El número %d es primo %d\n", primo2, esPrimo2);
        printf("Los números son equidistantes %d\n", equidistante);
        printf("Existe otro primo identificado %d\n", existeotro);
    }
    return 0;
}
int ExisteotroPrimo(int primo1, int primo2)
{
    int esexacta, cont = 0, resp;
    primo1++;
    while (primo1 < primo2)
    {
        esexacta = (sqrt(primo1) - (int)sqrt(primo1)) == 0;
        printf(" %d", primo1);
        if (primo1 % 2 != 0 && primo1 % 3 != 0 && primo1 % 5 != 0 && primo1 % 7 != 0 && !esexacta)
        {
            cont++;
        }
        primo1++;
    }
    if (cont == 0)
    {
        resp = 0;
    }
    else
    {
        resp = 1;
    }
    return resp;
}
void sonprimos(int primo1, int primo2, int *esPrimo1, int *esPrimo2)
{
    *esPrimo1 = esPrimo(primo1);
    *esPrimo2 = esPrimo(primo2);
}
int esPrimo(int num)
{
    int resp = 0, i = 1, cont = 0;
    while (i <= num)
    {
        if (num % i == 0)
        {
            cont++;
        }
        i++;
    }
    if (cont == 2)
    {
        resp = 1;
    }
    return resp;
}