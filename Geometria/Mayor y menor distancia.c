#include <stdio.h>
#include <math.h>

int main()
{
    int nPuntos, i;
    double A, B, C, xi, yi, xMayor, yMayor, xMenor, yMenor, distancia, distanciaMayor, distanciaMenor, suma, promedio;

    printf("Ingrese los coeficientes A, B y C de la recta de forma Ax+By+C=0 :");
    scanf(" %lf %lf %lf", &A, &B, &C);
    printf("Ingrese el número de puntos a evaluar:");
    scanf(" %d", &nPuntos);

    i = 1;
    distanciaMayor = 0;
    distanciaMenor = 1000;
    suma = 0;
    while (i <= nPuntos)
    {
        printf("Ingrese el punto # %d (x,y): ", i);
        scanf(" %lf %lf", &xi, &yi);
        /*calcular la distancia e ir buscando la mayor y menor distancia*/
        distancia = abs(A * xi + B * yi + C) / sqrt(pow(A, 2) + pow(B, 2));
        printf("Distancia punto %d a la recta: %lf\n", i, distancia);
        suma += distancia;
        if (distancia > distanciaMayor)
        {
            xMayor = xi;
            yMayor = yi;
            distanciaMayor = distancia;
        }
        if (distancia < distanciaMenor)
        {
            xMenor = xi;
            yMenor = yi;
            distanciaMenor = distancia;
        }
        i++;
    }
    promedio = suma / nPuntos;

    printf("El punto con menor distancia a la recta es ( %.2lf, %.2lf)\n", xMenor, yMenor);
    printf("El punto con mayor distancia a la recta es ( %.2lf, %.2lf)\n", xMayor, yMayor);
    printf("El promedio de distancias de los puntos evaluados es: %.2lf\n", promedio);

    return 0;
}