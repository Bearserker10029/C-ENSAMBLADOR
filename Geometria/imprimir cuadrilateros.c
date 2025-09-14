#include <stdio.h>
#include <math.h>
#include <unistd.h>
#define clear() printf("\e[2J\e[J")

void Indicardatos(int i, int *j, int *a, int *b)
{
    int hab = 1;
    while (hab == 1)
    {
        printf("Indicar si es sin relleno (0) con relleno (1): ");
        scanf(" %d", j);
        if (*j == 0 || *j == 1)
        {
            if (i == 1)
            {
                printf("Indicar ancho y altura: ");
                scanf(" %d %d", a, b);
            }
            else
            {
                printf("Indicar lado: ");
                scanf(" %d", a);
            }
            hab = 0;
        }
        else
        {
            printf("Ingrese un valor valido \n");
        }
    }
}

void Salidadedatos(int j, int a, int b)
{
    int ancho = 1;
    if (j == 0)
    {
        while (ancho <= a)
        {
            int largo = 1;
            while (largo <= b)
            {
                if (largo == 1 || largo == b || ancho == 1 || ancho == a)
                {
                    printf("# ");
                }
                else
                {
                    printf("  ");
                }
                largo++;
            }
            printf("\n");
            ancho++;
        }
    }
    else if (j == 1)
    {
        while (ancho <= a)
        {
            int largo = 1;
            while (largo <= b)
            {
                printf("# ");
                largo++;
            }
            printf("\n");
            ancho++;
        }
    }
    sleep(20);
    clear();
}

int main()
{
    int i, j, a, b;
    while (1)
    {
        printf("Elige si es cuadrado (0) o rectangulo (1):");
        scanf("%d", &i);
        if (i == 1)
        {
            Indicardatos(i, &j, &a, &b);
            Salidadedatos(j, a, b);
        }
        else if (i == 0)
        {
            Indicardatos(i, &j, &a, &b);
            b = a;
            Salidadedatos(j, a, b);
        }
        else
            printf("Ingrese un valor valido \n");
    }
    return 0;
}