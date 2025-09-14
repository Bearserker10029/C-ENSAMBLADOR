#include <stdio.h>
#include <math.h>

int main()
{
    double input, suma;
    int esnumero;
    do
    {
        printf("Ingrese digito: ");
        esnumero = scanf("%lf", &input);
        if (esnumero)
        {
            if (input != 0)
            {
                suma = suma + input;
            }
            else
            {
                printf("La suma es: %.2lf\n", suma);
                suma = 0;
            }
        }
        else
        {
            printf("No es un numero \n");
            break;
        }
    } while (1);
    return 0;
}