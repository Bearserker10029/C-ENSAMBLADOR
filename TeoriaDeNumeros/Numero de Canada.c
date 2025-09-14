#include <stdio.h>
int main()
{
    char evaluacion;
    int div;
    int num, cantDig, esCanada, sum;
    printf("Ingrese el numero a evaluar: ");
    scanf(" %d", &num);
    evaluarSiEsCanada(num, &esCanada, &sum, &div, cantDig);
    if (esCanada)
    {
        printf("El numero es Canada ");
    }
    else
    {
        printf("El numero no es Canada ");
    }
    printf("\nLa suma de los cuadrados de sus digitos es %d y de sus divisores es %d", sum, div);
    return 0;
}
void evaluarSiEsCanada(int num, int *resp, int *sum, int *div, int cantDig)
{
    int es;
    *sum = CalcularSumaDigitos(num, cantDig);
    *div = SumaDivisores(num);
    es = *sum == *div;
    if (es)
    {
        *resp = 1;
    }
    else
    {
        *resp = 0;
    }
}

int SumaDivisores(int num)
{
    int resp = 0, suma = 0, i = 2, cont = 0;
    while (i < num)
    {
        if (num % i == 0)
        {
            suma = suma + i;
        }
        i++;
    }
    return suma;
}

int CalcularSumaDigitos(int num, int cantDig)
{
    int suma = 0, dig, i = 0;
    while (i < cantDig)
    {
        dig = num % 10;
        num = num / 10;
        suma = suma + dig * dig;
        i++;
    }
    return suma;
}